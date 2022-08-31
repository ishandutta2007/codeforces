#include <iostream>
#include <algorithm>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
      char x;
      std::cin >> x;
      a[i] = (x == 'R');
    }

    if(n == 3) {
      std::cout << (a[0] == a[1] && a[1] == a[2]) << std::endl;
      continue;
    }

    int ans = n+5;
    for(int p = 0; p < 3; p++) {
      int dp[2][2][n];
      dp[1][0][0] = dp[0][1][0] = n+5;
      dp[1][1][0] = (a[0] != 1);
      dp[0][0][0] = (a[0] != 0);

      for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
          dp[i][j][1] = (a[1] != j) + (a[0] != i);
        }
      }

      for(int i = 2; i < n; i++) {
        for(int j = 0; j < 2; j++) {
          dp[j][0][i] = (a[i] != 0) + std::min(dp[j][1][i-1], (a[i-1] != 0) + dp[j][1][i-2]);
          dp[j][1][i] = (a[i] != 1) + std::min(dp[j][0][i-1], (a[i-1] != 1) + dp[j][0][i-2]);
        }
      }

      ans = std::min(ans, std::min(dp[0][1][n-1], dp[1][0][n-1]));
      std::rotate(a, a+1, a+n);
    }
    

    std::cout << ans << std::endl;
          
  }

  return 0;
}