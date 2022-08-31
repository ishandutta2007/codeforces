#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> adj [MAX_N];

void add_edge (int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int vis [MAX_N];

void dfs (int u, int c) {
  vis[u] = c;
  for (int nxt : adj[u]) {
    if (vis[nxt] == 0) {
      dfs(nxt, -c);
    }
  }
}

int to2 (int x) {
  if (x == -1) return 1;
  return 2;
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<pair<int, int>> input (n);
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    
    u--;
    v--;

    add_edge(u, v);
    input[i] = {u, v};
  }

  for (int i = 0; i < 2 * n; i += 2) {
    add_edge(i, i + 1);
  }

  for (int i = 0; i < 2 * n; i++) {
    if (vis[i] == 0) {
      dfs(i, 1);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << to2(vis[input[i].first]) << " " << to2(vis[input[i].second]) << '\n';
  }
}