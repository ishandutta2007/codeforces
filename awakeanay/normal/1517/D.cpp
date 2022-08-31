#include <iostream>

#define int long long

const int INF = 10000000000000000;

signed main() {
  int n, m, k;
  std::cin >> n >> m >> k;

  if(k%2) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++)
        std::cout << -1 << " ";
      std::cout << std::endl;
    }
    return 0;
  }

  k = k/2 + 1;
  int dp[n][m][k];

  int a[n][m-1];
  int b[n-1][m];

  for(int i = 0; i < n; i++)
    for(int j = 0; j+1 < m; j++)
      std::cin >> a[i][j];
  for(int i = 0; i+1 < n; i++)
    for(int j = 0; j < m; j++)
      std::cin >> b[i][j];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      dp[i][j][0] = 0;

  for(int l = 1; l < k; l++) {
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        dp[i][j][l] = INF;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j+1 < m; j++) {
        dp[i][j][l] = std::min(dp[i][j][l], dp[i][j+1][l-1] + a[i][j]);
        dp[i][j+1][l] = std::min(dp[i][j+1][l], dp[i][j][l-1] + a[i][j]);
      }
    }

    for(int i = 0; i+1 < n; i++) {
      for(int j = 0; j < m; j++) {
        dp[i][j][l] = std::min(dp[i][j][l], dp[i+1][j][l-1] + b[i][j]);
        dp[i+1][j][l] = std::min(dp[i+1][j][l], dp[i][j][l-1] + b[i][j]);
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++)
      std::cout << 2*dp[i][j][k-1] << " ";
    std::cout << std::endl;
  }

  return 0;
}