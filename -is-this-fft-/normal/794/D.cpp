#include <iostream>
#include <vector>
#include <algorithm>

const int MAX_VERT = 300005;

using namespace std;

struct vertex {
  int id;
  vector<int> adj;
};

bool operator< (vertex p, vertex q) {
  return p.adj < q.adj;
}

vertex vertices [MAX_VERT];
int contr [MAX_VERT];
vector<int> contr_adj [MAX_VERT];
int label [MAX_VERT];

void dfs (int vertex, int parent, int depth) {
  label[vertex] = depth;

  for (int i = 0; i < (int) contr_adj[vertex].size(); i++) {
    if (contr_adj[vertex][i] != parent) {
      dfs(contr_adj[vertex][i], vertex, depth + 1);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int vertexc, edgec;
  cin >> vertexc >> edgec;

  for (int i = 1; i <= vertexc; i++) {
    vertices[i].id = i;
    vertices[i].adj.push_back(i);
  }

  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;

    vertices[u].adj.push_back(v);
    vertices[v].adj.push_back(u);
  }
  
  for (int i = 1; i <= vertexc; i++) {
    sort(vertices[i].adj.begin(), vertices[i].adj.end());
  }

  sort(vertices + 1, vertices + vertexc + 1);

  for (int i = 1; i <= vertexc; i++) {
    if (i == 1 || vertices[i].adj != vertices[i - 1].adj) {
      contr[vertices[i].id] = vertices[i].id;
    } else {
      contr[vertices[i].id] = contr[vertices[i - 1].id];
    }
  }

  for (int i = 1; i <= vertexc; i++) {
    if (contr[vertices[i].id] == vertices[i].id) {
      for (int j = 0; j < (int) vertices[i].adj.size(); j++) {
        if (vertices[i].adj[j] != vertices[i].id &&
            contr[vertices[i].adj[j]] == vertices[i].adj[j]) {
          contr_adj[vertices[i].id].push_back(vertices[i].adj[j]);
        }
      }
    }
  }

  int zeroc = 0, onec = 0, twoc = 0, root;
  for (int i = 1; i <= vertexc; i++) {
    if (contr[i] == i) {
      if ((int) contr_adj[i].size() == 0) {
        zeroc++;
        root = i;
      } else if ((int) contr_adj[i].size() == 1) {
        onec++;
        root = i;
      } else if ((int) contr_adj[i].size() == 2) {
        twoc++;
      } else {
        cout << "NO" << endl;
        return 0;
      }
    }
  }

  if (onec != 2 && zeroc == 0) {
    cout << "NO" << endl;
    return 0;
  }

  dfs(root, root, 1);

  cout << "YES" << endl;
  for (int i = 1; i <= vertexc; i++) {
    cout << label[contr[i]] << " ";
  }
  cout << endl;
}