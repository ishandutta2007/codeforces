#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    if(n < 3) {
      std::cout << 0 << std::endl;
      continue;
    }

    int dp[n][n];
    int max = 0;
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
        dp[i][j] = 2;
        for(int k = 0; k < i; k++) {
          if((a[k]-a[j])*(j-i) == (a[j]-a[i])*(k-j)) {
            dp[i][j] = std::max(dp[i][j], dp[k][j]+1);
          }
        }

        max = std::max(max, dp[i][j]);
      }
    }

    std::cout << n-max << std::endl;
  }

  return 0;
}