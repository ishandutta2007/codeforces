#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int M = 205;
const int K = 1005;
int dp[M][K], ndp[M][K];
// (number of unfinished groups, total imbalance)

void add(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  sort(a.begin(), a.end());
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < M; j++) {
      for (int l = 0; l < K; l++) {
        if (dp[j][l]) {
          int new_imbalance = l+(i ? a[i]-a[i-1] : 0)*j;
          if (new_imbalance > k) continue;
          // new group
          add(ndp[j+1][new_imbalance], dp[j][l]);
          add(ndp[j][new_imbalance], dp[j][l]);
          // part of existing group
          if (j) {
            add(ndp[j][new_imbalance], 1LL*j*dp[j][l] % MOD);
            add(ndp[j-1][new_imbalance], 1LL*j*dp[j][l] % MOD);
          }
        }
      }
    }
    for (int j = 0; j < M; j++) {
      for (int l = 0; l < K; l++) {
        dp[j][l] = ndp[j][l];
        ndp[j][l] = 0;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < K; i++) add(ans, dp[0][i]);
  cout << ans << '\n';
}