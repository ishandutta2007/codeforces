#include <iostream>
#include <vector>

#define int long long

const int MOD = 1000000007;

signed main() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> div[n+1];
  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= n; j+=i) {
      div[j].push_back(i);
    }
  }

  int dp[k+1][n+1];
  for(int i = 1; i <= n; i++)
    dp[1][i] = 1;

  int ans = 0;
  for(int i = 2; i <= k; i++) {
    for(int j = 1; j <= n; j++) {
      dp[i][j] = 0;
      for(int l : div[j]) {
        dp[i][j] += dp[i-1][l];
        dp[i][j] %= MOD;
      }
    }
  }

  for(int i = 1; i <= n; i++)
    ans = (ans + dp[k][i])%MOD;

  std::cout << ans << std::endl;

  return 0;
}