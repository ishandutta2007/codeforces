#include <iostream>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  int a[n];
  int b[n];

  int cval = 0;
  for(int i = 0; i < n; i++)
    std::cin >> a[i];
  for(int i = 0; i < n; i++)
    std::cin >> b[i];

  for(int i = 0; i < n; i++)
    cval += a[i]*b[i];

  int dp[n][4];

  int chmax = 0;
  for(int i = 0; i < n; i++) {
    dp[i][1] = 0;
  }
  for(int i = 0; i+1 < n; i++) {
    dp[i][2] = a[i]*b[i+1] + b[i]*a[i+1] - b[i]*a[i] - b[i+1]*a[i+1];
    chmax = std::max(chmax, dp[i][2]);
  }

  for(int j = 3; j <= n; j++) {
    int m = j%4;
    for(int i = 0; i+j <= n; i++) {
      int r = i+j-1;
      dp[i][m] = dp[i+1][(m+2)%4] + a[i]*b[r] + a[r]*b[i] - a[r]*b[r] - a[i]*b[i];
      chmax = std::max(chmax, dp[i][m]);
    }
  }

  std::cout << cval + chmax << std::endl;

  return 0;
}