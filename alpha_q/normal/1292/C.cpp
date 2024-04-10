#include <bits/stdc++.h>

using namespace std;

const int N = 3030;

bitset <N> vis;
vector <int> g[N];
long long dp[N][N];
int n, lca[N][N], dep[N], p[N], d[N][N], sub[N][N];

void go (int u = 1, int par = 0, int far = 0) {
  dep[u] = far, p[u] = par;
  for (int v : g[u]) if (v ^ par) go(v, u, far + 1);
}

int getLCA (int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  if (lca[u][v]) return lca[u][v];
  if (u == v) return lca[u][v] = u;
  return lca[u][v] = getLCA(u, p[v]);
}

inline int dist (int u, int v) {
  int l = getLCA(u, v);
  return dep[u] + dep[v] - 2 * dep[l];
}

long long call (int u, int v) {
  if (~dp[u][v]) return dp[u][v];
  int cur = d[u][v];
  long long ret = 0;
  for (int to : g[u]) if (d[to][v] > d[u][v]) {
    ret = max(ret, (long long) sub[to][v] * sub[v][to] + call(to, v));
  }
  for (int to : g[v]) if (d[to][u] > d[u][v]) {
    ret = max(ret, (long long) sub[to][u] * sub[u][to] + call(u, to));
  }
  return dp[u][v] = ret;
}

void dfs (int u, int par) {
  vis[u] = 1;
  for (int v : g[u]) if (v ^ par) dfs(v, u);
}

void fuck (int u, int par, int root) {
  for (int v : g[u]) if (v ^ par) {
    fuck(v, u, root);
    if (!sub[root][v]) sub[root][v] = sub[u][v];
  }
}

int main() {
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  go();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) d[i][j] = dist(i, j);
  }
  for (int i = 1; i <= n; ++i) for (int j : g[i]) {
    vis.reset(); dfs(j, i); sub[i][j] = vis.count();
  }
  for (int i = 1; i <= n; ++i) {
    fuck(i, 0, i);
  }
  memset(dp, -1, sizeof dp);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) ans = max(ans, call(i, i));
  cout << ans << endl;
  return 0;
}