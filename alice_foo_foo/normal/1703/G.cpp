#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const ll N = 1e5 + 5;
const int M = 31;
const ll INF = 1e15;
ll t, n, k;
// dp[i][j]ij.
ll dp[N][M + 5];
 
int main() {
  std::cin >> t;
  while (t--) {
    std::cin >> n >> k;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= M; ++j) {
        dp[i][j] = -INF;
      }
    }
    dp[0][0] = 0;
    
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      for (int j = 0; j <= M; ++j) {
        // Good Key
        dp[i][j] = std::max(dp[i][j], dp[i - 1][j] - k + (x >> j));
        if (j == M) dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + (x >> j));
        // Bad Key
        if (j - 1 >= 0)
        dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + (x >> j));
      }
    }
    ll ans = 0;
    for (int j = 0; j <= M; ++j) ans = std::max(ans, dp[n][j]);
    cout << ans << endl;
  }
  return 0;
}