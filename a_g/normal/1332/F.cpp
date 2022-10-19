#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 3e5+2;
vector<int> G[N];
int dp[N][3];

void dfs(int v, int p) {
  for (int i = 0; i < 3; i++) {
    dp[v][i] = 1;
  }
  for (int u: G[v]) {
    if (u == p) continue;
    dfs(u, v);
    dp[v][0] = dp[v][0]*(0LL+2*dp[u][0]+2*dp[u][1]-dp[u][2])%MOD;
    dp[v][1] = dp[v][1]*(0LL+2*dp[u][0]+dp[u][1]-dp[u][2])%MOD;
    dp[v][2] = dp[v][2]*(0LL+dp[u][0]+dp[u][1]-dp[u][2])%MOD;
  }
  for (int i = 0; i < 3; i++) {
    if (dp[v][i] < 0) dp[v][i] += MOD;
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 1);
  int ans = dp[1][0]+dp[1][1]-dp[1][2]-1;
  if (ans < 0) ans += MOD;
  if (ans >= MOD) ans -= MOD;
  cout << ans << '\n';
}