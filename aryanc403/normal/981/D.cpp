/**
 *    author:  tourist
 *    created: 27.05.2018 18:00:22       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto good = [&](long long mask) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k; j++) {
        if (!dp[i][j]) {
          continue;
        }
        long long cur = 0;
        for (int t = i; t < n; t++) {
          cur += a[t];
          if ((cur & mask) == mask) {
            dp[t + 1][j + 1] = 1;
          }
        }
      }
    }
    return dp[n][k];
  };
  long long ans = 0;
  for (int bit = 60; bit >= 0; bit--) {
    if (good(ans + (1LL << bit))) {
      ans += (1LL << bit);
    }
  }
  cout << ans << '\n';
  return 0;
}