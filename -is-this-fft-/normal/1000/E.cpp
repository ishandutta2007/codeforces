#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 300005;

int ord [MAX_V], par [MAX_V], bridge [MAX_V];
int low [MAX_V];
vector<int> adj [MAX_V];

int cur_ord;
void dfs (int vertex) {
  cur_ord++;
  ord[vertex] = cur_ord;
  low[vertex] = ord[vertex];

  for (int nxt : adj[vertex]) {
    if (ord[nxt] != 0) {
      if (nxt != par[vertex]) {
        low[vertex] = min(low[vertex], ord[nxt]);
      }
    } else {
      par[nxt] = vertex;
      dfs(nxt);
      low[vertex] = min(low[vertex], low[nxt]);
    }
  }

  if (low[vertex] == ord[vertex] && vertex != 1) {
    bridge[vertex] = true;
  }
}

bool is_bridge (pair<int, int> edge) {
  if (ord[edge.first] > ord[edge.second]) {
    swap(edge.first, edge.second);
  }

  return (par[edge.second] == edge.first) && bridge[edge.second];
}

int root [MAX_V];

int find (int v) {
  if (root[v] != v) {
    root[v] = find(root[v]);
  }
  return root[v];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  root[u] = v;
}

vector<int> tree_adj [MAX_V];

int diam;
int height [MAX_V];
void longest_dfs (int vertex, int parent) {
  height[vertex] = 0;
  for (int nxt : tree_adj[vertex]) {
    if (nxt != parent) {
      longest_dfs(nxt, vertex);

      diam = max(diam, height[nxt] + height[vertex] + 1);
      height[vertex] = max(height[nxt] + 1, height[vertex]);
    }
  }
}

int main () {
  for (int i = 0; i < MAX_V; i++) {
    root[i] = i;
  }
  
  ios::sync_with_stdio(false);
  
  int vertexc, edgec;
  cin >> vertexc >> edgec;

  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);

  for (int u = 1; u <= vertexc; u++) {
    for (int v : adj[u]) {
      if (!is_bridge(make_pair(u, v))) {
        merge(u, v);
      }
    }
  }

  for (int u = 2; u <= vertexc; u++) {
    if (bridge[u]) {
      int v = par[u];

      tree_adj[find(u)].push_back(find(v));
      tree_adj[find(v)].push_back(find(u));
    }
  }

  longest_dfs(find(1), find(1));
  cout << diam << '\n';
}