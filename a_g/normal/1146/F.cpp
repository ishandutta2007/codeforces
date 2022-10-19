#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
const int MOD = 998244353;
vector<int> children[N];
int dp[N][2];
// dp[v][0] = number of leaf partitions of subtree of v
// dp[v][1] = number of augmented leaf partitions of subtree of v, where one
// piece of partition that could contain v is distinguished
//
// dp[v][0] = prod_{u in C(v)} dp[v][0] (v is uncolored case)
//          + sum_{S in 2^{C(v)}, |S| >= 2}prod_{v in S}dp[v][1] prod_{v not in S}dp[v][0]
//          (v is colored case)
//          = sum_{S in 2^{C(v)}, |S| != 1} ...
//
// dp[v][1] = sum_{u in C(v)} dp[u][1]*prod_{u' != u} dp[u'][0] + ...
//          = sum_{S in 2^{C(v)}, |S| != 0} ...
int pref[N], suff[N];

int add(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}

int sub(int x, int y) {
  x -= y;
  if (x < 0) x += MOD;
  return x;
}

void dfs(int v) {
  int k = (int)children[v].size();
  if (k == 0) {
    dp[v][0] = dp[v][1] = 1;
    return;
  }
  dp[v][0] = 1;
  for (int u: children[v]) {
    dfs(u);
    dp[v][0] = 1LL*dp[v][0]*(dp[u][0]+dp[u][1]) % MOD;
  }
  pref[0] = 1;
  suff[k] = 1;
  for (int i = 0; i < k; i++) {
    int u = children[v][i];
    pref[i+1] = 1LL*pref[i]*dp[u][0] % MOD;
  }
  for (int i = k-1; i >= 0; i--) {
    int u = children[v][i];
    suff[i] = 1LL*suff[i+1]*dp[u][0] % MOD;
  }
  dp[v][1] = sub(dp[v][0], pref[k]);
  for (int i = 0; i < k; i++) {
    int u = children[v][i];
    int term = pref[i]*(1LL*dp[u][1]*suff[i+1] % MOD) % MOD;
    dp[v][0] -= term;
    if (dp[v][0] < 0) dp[v][0] += MOD;
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    children[p].push_back(i);
  }
  dfs(1);
  cout << dp[1][0] << '\n';
}