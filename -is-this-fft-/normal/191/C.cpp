#include <iostream>
#include <vector>

const int MAX_BIT = 17;
const int MAX_VERTEX = 100005;

using namespace std;

int par [MAX_VERTEX][MAX_BIT], lvl [MAX_VERTEX];
vector<int> adj [MAX_VERTEX];

void dfs (int vertex, int parent) {
  par[vertex][0] = parent;
  for (int i = 1; i < MAX_BIT; i++) {
    par[vertex][i] = par[par[vertex][i - 1]][i - 1];
  }

  lvl[vertex] = lvl[parent] + 1;

  for (int i = 0; i < (int) adj[vertex].size(); i++) {
    if (adj[vertex][i] != parent) {
      dfs(adj[vertex][i], vertex);
    }
  }
}

int lca (int u, int v) {
  if (lvl[u] > lvl[v]) {
    int diff = lvl[u] - lvl[v];
    
    for (int i = 0; i < MAX_BIT; i++) {
      if (diff & 1 << i) {
        u = par[u][i];
      }
    }
  } else if (lvl[v] > lvl[u]) {
    int diff = lvl[v] - lvl[u];
    
    for (int i = 0; i < MAX_BIT; i++) {
      if (diff & 1 << i) {
        v = par[v][i];
      }
    }
  }

  if (u == v) {
    return u;
  }

  for (int i = MAX_BIT - 1; i >= 0; i--) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  
  return par[u][0];
}

int incr [MAX_VERTEX];

void augment (int vertex, int parent) {
  for (int i = 0; i < (int) adj[vertex].size(); i++) {
    if (adj[vertex][i] != parent) {
      augment(adj[vertex][i], vertex);
      
      incr[vertex] += incr[adj[vertex][i]];
    }
  }
}

int main () {
  int vertexc;
  cin >> vertexc;

  vector<pair<int, int> > edges;
  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    cin >> u >> v;

    edges.push_back(make_pair(u, v));
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);

  int queryc;
  cin >> queryc;

  for (int i = 0; i < queryc; i++) {
    int u, v;
    cin >> u >> v;

    incr[lca(u, v)] -= 2;
    incr[u]++;
    incr[v]++;
  }

  augment(1, 0);

  for (int i = 0; i < (int) edges.size(); i++) {
    if (lvl[edges[i].first] > lvl[edges[i].second]) {
      cout << incr[edges[i].first] << " ";
    } else {
      cout << incr[edges[i].second] << " ";
    }
  }
  cout << endl;
}