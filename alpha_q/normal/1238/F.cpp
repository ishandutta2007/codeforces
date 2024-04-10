#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

vector <int> g[N];
int t, n, f[N], dp[N];

void go (int u = 1, int par = -1) {
  for (int v : g[u]) {
    g[v].erase(find(g[v].begin(), g[v].end(), u));
    go(v, u);
  }
}

void dfs (int u = 1, int par = -1) {
  f[u] = 1; vector <int> vec;
  for (int v : g[u]) {
    dfs(v, u); vec.emplace_back(f[v]);
    f[u] = max(f[u], (int) g[u].size() + f[v]);
  }
  sort(vec.begin(), vec.end(), greater <int> ());
  dp[u] = f[u];
  if (vec.size() > 1) dp[u] = max(dp[u], vec[0] + vec[1] + (int) g[u].size() - 1 + (u > 1));
}

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i) {
      scanf("%d %d", &u, &v);
      g[u].emplace_back(v), g[v].emplace_back(u);
    }
    go(); dfs(); 
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[i]);
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i) g[i].clear();
  }
  return 0;
}