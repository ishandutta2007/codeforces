#include <iostream>
#include <vector>

#define int long long
int MOD;

int a[501];
int n, m, b;

signed main() {
  std::cin >> n >> m >> b >> MOD;

  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int dp[2][m+1][b+1];
  for(int j = 0; j <= m; j++)
    for(int k = 0; k <= b; k++)
      dp[0][j][k] = (a[0]*j <= k);

  for(int i = 1; i < n; i++) {
    int p = (i%2);
    for(int j = 0; j <= m; j++) {
      for(int k = 0; k <= b; k++) {
        dp[p][j][k] = 0;
        if(j && k >= a[i]) dp[p][j][k] = dp[p][j-1][k-a[i]];
        dp[p][j][k] = (dp[p][j][k] + dp[p^1][j][k])%MOD;
      }
    }
  }

  std::cout << dp[(n-1)%2][m][b]%MOD << std::endl;

  return 0;
}