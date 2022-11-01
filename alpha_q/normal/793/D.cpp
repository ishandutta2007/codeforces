#include <bits/stdc++.h> 

using namespace std;

typedef pair <int, int> edge;

int n, k, m;
vector <edge> g[100];
int dp[82][82][82][82];

int call (int cur, int rem, int l, int r) {
  if (rem == 0) return 0;
  if (dp[cur][rem][l][r] != -1) return dp[cur][rem][l][r];
  int ret = 1000000000;
  for (edge e : g[cur]) {
    int v = e.first, w = e.second;
    if (v <= l or v >= r) continue;
    if (v == cur) continue;
    if (v > cur) {
      ret = min(ret, w + call(v, rem - 1, cur, r));
    } else {
      ret = min(ret, w + call(v, rem - 1, l, cur));
    }
  }
  return dp[cur][rem][l][r] = ret;
}

int main (int argc, char const *argv[]) {
  scanf("%d %d %d", &n, &k, &m);
  while (m--) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    g[u].push_back(edge(v, w));
  } 
  memset(dp, -1, sizeof dp);
  int ans = 1000000000;
  for (int i = 1; i <= n; ++i) {
    ans = min(ans, call(i, k - 1, 0, n + 1));
  }
  if (ans >= 1000000000) puts("-1");
  else cout << ans << endl;
  return 0;
}