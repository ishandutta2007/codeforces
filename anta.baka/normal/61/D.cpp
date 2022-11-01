#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
vector<pair<int, int>> g[100000];
vector<int> pr[100000], su[100000];
int dp[100000];
long long ans = 1e18;

void dfs1(int v, int p) {
  for(int i = 0; i < g[v].size(); i++) {
    int to = g[v][i].first;
    if(to == p) {
      g[v].erase(g[v].begin() + i);
      --i;
      continue;
    }
    dfs1(to, v);
    dp[v] += g[v][i].second + dp[to];
  }
  int sz = g[v].size();
  if(!sz)
    return;
  pr[v].resize(sz);
  pr[v][0] = dp[g[v][0].first] + g[v][0].second;
  for(int i = 1; i < sz; i++)
    pr[v][i] = pr[v][i - 1] + dp[g[v][i].first] + g[v][i].second;
  su[v].resize(sz);
  su[v][sz - 1] = dp[g[v][sz - 1].first] + g[v][sz - 1].second;
  for(int i = sz - 2; i >= 0; i--)
    su[v][i] = su[v][i + 1] + dp[g[v][i].first] + g[v][i].second;
}

void dfs2(int v, long long up) {
  int sum = 0;
  int sz = g[v].size();
  for(int i = 0; i < sz; i++) {
    dfs2(g[v][i].first, up + (i > 0 ? 2 * pr[v][i - 1] : 0) + (i + 1 < sz ? 2 * su[v][i + 1] : 0) + g[v][i].second);
    sum += 2 * (g[v][i].second + dp[g[v][i].first]);
  }
  ans = min(ans, sum + up);
}

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u; --v;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  dfs1(0, -1);
  dfs2(0, 0);
  cout << ans;
}