#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_R = 1e3 + 5;

vector<int> adj [MAX_N];
int conn [MAX_R][MAX_R];

int root [MAX_R];
int find (int u) {
  if (u != root[u]) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);
  root[u] = v;
}

int main () {
  ios::sync_with_stdio(false);
  
  int vertexc, edgec;
  cin >> vertexc >> edgec;

  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  pair<int, int> mindeg = make_pair(MAX_N, MAX_N);
  for (int i = 1; i <= vertexc; i++) {
    mindeg = min(mindeg, make_pair((int) adj[i].size(), i));
  }

  map<int, int> new_id;
  for (int i = 1; i <= vertexc; i++) {
    new_id[i] = 0;
  }

  for (int i = 0; i < (int) adj[mindeg.second].size(); i++) {
    new_id[adj[mindeg.second][i]] = i + 1;
  }
  
  int rvc = (int) adj[mindeg.second].size() + 1;
  int zmul = vertexc - rvc + 1;
  for (int i = 0; i < rvc; i++) {
    root[i] = i;
    for (int j = 0; j < rvc; j++) {
      if (i != j) {
        if (i == 0 || j == 0) {
          conn[i][j] = zmul;
        } else {
          conn[i][j] = 1;
        }
      }
    }
  }

  for (int i = 1; i <= vertexc; i++) {
    for (int u : adj[i]) {
      conn[new_id[i]][new_id[u]]--;
    }
  }

  for (int i = 0; i < rvc; i++) {
    for (int j = i + 1; j < rvc; j++) {
      if (conn[i][j]) {
        merge(i, j);
      }
    }
  }

  int compc = 0;
  for (int i = 0; i < rvc; i++) {
    if (find(i) == i) {
      compc++;
    }
  }

  cout << compc - 1 << endl;
}