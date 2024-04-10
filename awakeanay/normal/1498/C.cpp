#include <iostream>

#define int long long

const int MOD = 1000000007;

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    int dp[k+1][n];
    for(int i = 0; i < n; i++)
      dp[1][i] = 0;

    for(int i = 2; i <= k; i++) {
      for(int j = n-1; j >= 0; j--) {
        int add = 1;
        if(j != n-1)
          add = (add + dp[i][j+1])%MOD;
        if(j != 0)
          add = (add + dp[i-1][n-j])%MOD;
        dp[i][j] = add;
      }
    }

    std::cout << (dp[k][0]+1)%MOD << std::endl;
  }

  return 0;
}