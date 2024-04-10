#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

int root [MAX_N];

int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  root[u] = v;
}

vector<int> out_adj [MAX_N];
int vis [MAX_N];
int has_cyc [MAX_N];

void find_cyc (int u) {
  vis[u] = 1;
  for (int nxt : out_adj[u]) {
    if (vis[nxt] == 1) {
      has_cyc[find(u)] = 1;
    } else if (vis[nxt] == 0) {
      find_cyc(nxt);
    }
  }
  vis[u] = 2;
}

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    root[i] = i;
  }
  
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    out_adj[u].push_back(v);
    merge(u, v);
  }

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      find_cyc(i);
    }
  }

  int ans = n;
  for (int i = 1; i <= n; i++) {
    if (find(i) == i) {
      if (!has_cyc[i]) {
        ans--;
      }
    }
  }
  cout << ans << endl;
}