#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int p[2*n];
    for(int i = 0; i < 2*n; i++)
      std::cin >> p[i];

    int first[2*n];
    for(int i = 0; i < 2*n; i++) {
      first[i] = 2*n;
      for(int j = i+1; j < 2*n; j++) {
        if(p[j] > p[i]) {
          first[i] = j;
          break;
        }
      }
    }

    int dp[n+1][n+1][2];

    for(int i = 0; i <= n; i++) {
      for(int j = 0; j <= n; j++) {
        if(i + j == 0) {
          dp[i][j][0] = dp[i][j][1] = true;
          continue;
        }

        int cur = 2*n-i-j;
        int k = first[cur] - cur;
        dp[i][j][0] = dp[i][j][1] = false;
        if(i >= k) dp[i][j][0] = (dp[i-k][j][0] || dp[i-k][j][1]);
        if(j >= k) dp[i][j][1] = (dp[i][j-k][0] || dp[i][j-k][1]);
      }
    }

    if(dp[n][n][0] || dp[n][n][1])
      std::cout << "YES";
    else
      std::cout << "NO";

    std::cout << std::endl;
  }

  return 0;
}