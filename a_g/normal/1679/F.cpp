#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1679/submission/157178900
const int MOD = 998244353;
const int K = 10;
int dp[1<<K], ndp[1<<K];
int mask[K];
// dp[mask] = # of lexicographically minimal representatives where mask
// represents banned digits

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    mask[u] |= 1<<v;
    mask[v] |= 1<<u;
  }
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1<<K); j++) {
      if (dp[j]) {
        for (int k = 0; k < K; k++) {
          if (!((j>>k)&1)) {
            // 2^k-1: digits smaller than k
            // mask[k]: can be moved past k
            int z = (j|((1<<k)-1))&mask[k];
            ndp[z] = (ndp[z]+dp[j]) % MOD;
          }
        }
      }
    }
    swap(dp, ndp);
    fill(ndp, ndp+(1<<K), 0);
  }
  cout << accumulate(dp, dp+(1<<K), 0LL)%MOD << '\n';
}