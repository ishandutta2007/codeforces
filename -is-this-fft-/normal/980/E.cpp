#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

const int MAX_V = 1000005;
const int MAX_LG = 22;

vector<int> adj [MAX_V];
int par [MAX_V][MAX_LG];
int lvl [MAX_V];
bool saved [MAX_V];

void dfs (int vertex, int parent) {
  lvl[vertex] = lvl[parent] + 1;
  par[vertex][0] = parent;
  for (int i = 1; i < MAX_LG; i++) {
    par[vertex][i] = par[par[vertex][i - 1]][i - 1];
  }

  for (int child : adj[vertex]) {
    if (child != parent) {
      dfs(child, vertex);
    }
  }
}

int cost (int vertex) {
  if (saved[vertex]) {
    return 0;
  }

  int adjoin = vertex;
  for (int k = MAX_LG - 1; k >= 0; k--) {
    if (!saved[par[adjoin][k]]) {
      adjoin = par[adjoin][k];
    }
  }
  adjoin = par[adjoin][0];

  return lvl[vertex] - lvl[adjoin];
}

void augment (int vertex) {
  while (!saved[vertex]) {
    saved[vertex] = true;
    vertex = par[vertex][0];
  }
}

int main () {
  ios::sync_with_stdio(false);

  int vertexc, removec;
  cin >> vertexc >> removec;

  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  saved[vertexc] = true;
  int saveable = vertexc - removec - 1;

  dfs(vertexc, vertexc);

  for (int i = vertexc - 1; i >= 1; i--) {
    int cost_to_save = cost(i);
    if (cost_to_save <= saveable) {
      augment(i);
      saveable -= cost_to_save;
    }
  }
  
  for (int i = 1; i <= vertexc; i++) {
    if (!saved[i]) {
      cout << i << " ";
    }
  }
  cout << endl;
}