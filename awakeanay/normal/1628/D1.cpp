#include <iostream>

#define int long long

const int MOD = 1000'000'007;
const int HALF = (MOD+1)/2;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m, k;
    std::cin >> n >> m >> k;

    int dp[n+1][n+1];
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j <= i; j++) {
        if(j == 0)
          dp[i][j] = 0;
        else if(j == i)
          dp[i][j] = (i*k)%MOD;
        else {
          dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])*HALF;
          dp[i][j] %= MOD;
        }
      }
    }

    std::cout << dp[n][m] << std::endl;
  }

  return 0;
}