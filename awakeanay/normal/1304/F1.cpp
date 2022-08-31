/*
Author: AwakeAnay
Date: 15/02/2020
Time: 19:45:12
*/

#include <iostream>

#define int long long

signed main() {
  int n, m, k;
  std::cin >> n >> m >> k;

  int pre[n+1][m];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      std::cin >> pre[i][j];
      if(j) pre[i][j] += pre[i][j-1];
    }
  }

  for(int j = 0; j < m; j++)
    pre[n][j] = 0;

  int l = m-k+1;
  int dp[n][l];
  int pred[n][l];
  int sufd[n][l];

  for(int i = 0; i < n; i++) {
    for(int j = l-1; j >= 0; j--) {
      int cur = pre[i][j+k-1] + pre[i+1][j+k-1];
      if(j) cur -= pre[i][j-1] + pre[i+1][j-1];

      dp[i][j] = cur;
      
      if(i == 0)
        continue;

      for(int u = j; u < std::min(j+k, l); u++) {
        int upd = cur + dp[i-1][u] - pre[i][j+k-1];
        if(u) upd += pre[i][u-1];
        dp[i][j] = std::max(dp[i][j], upd);
      }

      for(int u = std::max((long long)0, j-k+1); u < j; u++) {
        int upd = cur + dp[i-1][u] - pre[i][u+k-1];
        if(j) upd += pre[i][j-1];
        dp[i][j] = std::max(dp[i][j], upd);
      }

      if(j+k < l)
        dp[i][j] = std::max(dp[i][j], cur + sufd[i-1][j+k]);
      if(j-k >= 0)
        dp[i][j] = std::max(dp[i][j], cur + pred[i-1][j-k]);
    }

    for(int j = 0; j < l; j++) {
      pred[i][j] = dp[i][j];
      if(j) pred[i][j] = std::max(pred[i][j-1], pred[i][j]);
    }

    for(int j = l-1; j >= 0; j--) {
      sufd[i][j] = dp[i][j];
      if(j < l-1) sufd[i][j] = std::max(sufd[i][j+1], sufd[i][j]);
    }
  }

  std::cout << sufd[n-1][0] << std::endl;

  return 0;
}