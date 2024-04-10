#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
vector<int> G[N];
int par[N], tin[N], tout[N];
int timer = 0;

class dsu {
  public:
    vector<int> parents;
    vector<int> sizes;
    dsu (int n) {
      parents.resize(n);
      iota(parents.begin(), parents.end(), 0);
      sizes.resize(n, 1);
    }
    int root(int u) {
      return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
      int a = root(u);
      int b = root(v);
      if (a == b) return 0;
      if (sizes[a] > sizes[b]) swap(a, b);
      parents[a] = b;
      sizes[b] += sizes[a];
      return 1;
    }
};

void dfs(int v, int p) {
  tin[v] = timer++;
  for (int u: G[v]) {
    if (u == p) continue;
    par[u] = v;
    dfs(u, v);
  }
  tout[v] = timer++;
}

bool is_ancestor(int u, int v) {
  return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    dsu D(n+1);
    vector<pair<int, int>> edges(m);
    string ans(m, '0');
    vector<int> extras;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      edges[i] = make_pair(u, v);
      if (D.join(u, v)) {
        G[u].push_back(v);
        G[v].push_back(u);
      }
      else {
        extras.push_back(i);
        ans[i] = '1';
      }
    }
    dsu E(n+1);
    int g = 0;
    for (int i: extras) {
      g += 1-E.join(edges[i].first, edges[i].second);
    }

    if (g) {
      timer = 0;
      dfs(1, 1);
      int u = edges[extras[0]].first;
      int v = edges[extras[0]].second;
      if (is_ancestor(u, v)) swap(u, v);
      // swap with edge u -> par[u]
      for (int i = 0; i < m; i++) {
        if ((edges[i].first == u && edges[i].second == par[u]) ||
            (edges[i].second == u && edges[i].first == par[u])) {
          ans[i] = '1';
          ans[extras[0]] = '0';
          break;
        }
      }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
      G[i].clear();
    }
  }
}