#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<pair<int, int>> g_adj [MAX_N];
int side [MAX_N];

void bi_dfs (int u, int c, bool &ok) {
  side[u] = c;
  for (auto e : g_adj[u]) {
    int nxt = e.first;
    if (side[nxt] == 0) {
      bi_dfs(nxt, e.second * c, ok);
    } else if (side[nxt] != e.second * c) {
      ok = false;
    }
  }
}

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    g_adj[i].clear();
    side[i] = 0;
  }

  vector<pair<pair<int, int>, int>> tree;
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    tree.emplace_back(make_pair(u, v), w);

    if (w != -1) {
      if (__builtin_popcount(w) % 2 == 0) {
        g_adj[u].emplace_back(v, 1);
        g_adj[v].emplace_back(u, 1);
      } else {
        g_adj[u].emplace_back(v, -1);
        g_adj[v].emplace_back(u, -1);
      }
    }
  }

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    int x = w ? -1 : 1;
    g_adj[u].emplace_back(v, x);
    g_adj[v].emplace_back(u, x);
  }

  bool ok = true;
  for (int i = 1; i <= n; i++) {
    if (!side[i]) {
      bi_dfs(i, 1, ok);
    }
  }

  if (!ok) {
    cout << "NO" << '\n';
    return;
  }

  cout << "YES" << '\n';
  for (auto e : tree) {
    int u = e.first.first;
    int v = e.first.second;
    if (e.second == -1) {
      e.second = side[u] != side[v];
    }
    cout << u << " " << v << " " << e.second << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}