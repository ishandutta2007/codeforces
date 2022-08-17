#include <iostream>

#define int long long

const int MOD = 1000000007;

signed main() {
  int n, l, r;
  std::cin >> n >> l >> r;

  int c[3];
  c[0] = c[1] = c[2] = 0;

  int dp[n+1][3];
  dp[0][0] = 1;
  dp[0][1] = 0;
  dp[0][2] = 0;

  while((r+1)%3 != l%3) {
    c[r%3]++;
    r--;
  }

  for(int j = 0; j < 3; j++) {
    c[j] += (r-l+1)/3;
  }


  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 3; j++) {
      dp[i][j] = 0;
      for(int k = 0; k < 3; k++) {
        dp[i][j] += (dp[i-1][k]*c[(j-k+3)%3])%MOD;
        dp[i][j] %= MOD;
      }
    }
  }

  std::cout << dp[n][0] << std::endl;

  return 0;
}