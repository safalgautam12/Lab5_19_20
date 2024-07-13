#include <iostream>

using namespace std;

class Graph {
private:
    static const int MAX_VERTICES = 100;
    bool adjMatrix[MAX_VERTICES][MAX_VERTICES];
    bool directed;
    int vertices;

public:
    Graph(bool isDirected = false) : directed(isDirected), vertices(0) {
        for (int i = 0; i < MAX_VERTICES; ++i) {
            for (int j = 0; j < MAX_VERTICES; ++j) {
                adjMatrix[i][j] = false;
            }
        }
    }

    bool isEmpty() {
        return vertices == 0;
    }

    bool isDirected() {
        return directed;
    }

    void addVertex(int newVertex) {
        if (newVertex >= 0 && newVertex < MAX_VERTICES) {
            vertices++;
        } else {
            cout << "Vertex number out of range." << endl;
        }
    }

    void addEdge(int vertex1, int vertex2) {
        if (vertex1 >= 0 && vertex1 < MAX_VERTICES && vertex2 >= 0 && vertex2 < MAX_VERTICES) {
            adjMatrix[vertex1][vertex2] = true;
            if (!directed) {
                adjMatrix[vertex2][vertex1] = true;
            }
        } else {
            cout << "Vertex number out of range." << endl;
        }
    }

    void removeVertex(int vertexToRemove) {
        if (vertexToRemove >= 0 && vertexToRemove < MAX_VERTICES) {
            for (int i = 0; i < MAX_VERTICES; ++i) {
                adjMatrix[vertexToRemove][i] = false;
                adjMatrix[i][vertexToRemove] = false;
            }
            vertices--;
        } else {
            cout << "Vertex number out of range." << endl;
        }
    }

    void removeEdge(int vertex1, int vertex2) {
        if (vertex1 >= 0 && vertex1 < MAX_VERTICES && vertex2 >= 0 && vertex2 < MAX_VERTICES) {
            adjMatrix[vertex1][vertex2] = false;
            if (!directed) {
                adjMatrix[vertex2][vertex1] = false;
            }
        } else {
            cout << "Vertex number out of range." << endl;
        }
    }

    int numVertices() {
        return vertices;
    }

    int numEdges() {
        int count = 0;
        for (int i = 0; i < MAX_VERTICES; ++i) {
            for (int j = 0; j < MAX_VERTICES; ++j) {
                if (adjMatrix[i][j]) {
                    count++;
                }
            }
        }
        if (!directed) {
            count /= 2;
        }
        return count;
    }

    int indegree(int vertex) {
        int count = 0;
        if (vertex >= 0 && vertex < MAX_VERTICES) {
            for (int i = 0; i < MAX_VERTICES; ++i) {
                if (adjMatrix[i][vertex]) {
                    count++;
                }
            }
        } else {
            cout << "Vertex number out of range." << endl;
        }
        return count;
    }

    int outdegree(int vertex) {
        int count = 0;
        if (vertex >= 0 && vertex < MAX_VERTICES) {
            for (int i = 0; i < MAX_VERTICES; ++i) {
                if (adjMatrix[vertex][i]) {
                    count++;
                }
            }
        } else {
            cout << "Vertex number out of range." << endl;
        }
        return count;
    }

    int degree(int vertex) {
        return outdegree(vertex) + indegree(vertex);
    }

    void neighbours(int vertex) {
        if (vertex >= 0 && vertex < MAX_VERTICES) {
            for (int i = 0; i < MAX_VERTICES; ++i) {
                if (adjMatrix[vertex][i]) {
                    cout << i << " ";
                }
            }
            cout << endl;
        } else {
            cout << "Vertex number out of range." << endl;
        }
    }

    bool neighbour(int vertex1, int vertex2) {
        if (vertex1 >= 0 && vertex1 < MAX_VERTICES && vertex2 >= 0 && vertex2 < MAX_VERTICES) {
            return adjMatrix[vertex1][vertex2];
        } else {
            cout << "Vertex number out of range." << endl;
            return false;
        }
    }
};

void testGraph() {
    Graph g(true); // Directed graph

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);

    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);
    g.addEdge(2, 4);

    cout << "Graph is empty: " << (g.isEmpty() ? "True" : "False") << endl;
    cout << "Graph is directed: " << (g.isDirected() ? "True" : "False") << endl;
    cout << "Number of vertices: " << g.numVertices() << endl;
    cout << "Number of edges: " << g.numEdges() << endl;

    cout << "Indegree of vertex 2: " << g.indegree(2) << endl;
    cout << "Outdegree of vertex 2: " << g.outdegree(2) << endl;
    cout << "Degree of vertex 2: " << g.degree(2) << endl;

    cout << "Neighbours of vertex 2: ";
    g.neighbours(2);

    cout << "Vertex 4 is a neighbour of vertex 2: " << (g.neighbour(2, 4) ? "True" : "False") << endl;

    g.removeEdge(2, 4);
    cout << "Removed edge from 2 to 4." << endl;
    cout << "Vertex 4 is a neighbour of vertex 2: " << (g.neighbour(2, 4) ? "True" : "False") << endl;

    g.removeVertex(3);
    cout << "Removed vertex 3." << endl;
    cout << "Number of vertices: " << g.numVertices() << endl;
    cout << "Number of edges: " << g.numEdges() << endl;
}

int main() {
    testGraph();
    return 0;
}
