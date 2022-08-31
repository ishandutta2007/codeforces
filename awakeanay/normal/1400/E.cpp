#include <iostream>
#include <vector>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  std::vector<std::vector<int> > dp(n, std::vector<int>(n+1, 3*n));

  for(int i = 0; i <= std::min(n, a[0]); i++) {
    dp[0][i] = (a[0] != i);
  }

  for(int i = std::min(n, a[0]); i >= 0; i--) {
    dp[0][i] += i;
    if(i+1 <= std::min(n, a[0]))
      dp[0][i] = std::min(dp[0][i], dp[0][i+1]);
  }

  for(int i = 1; i < n; i++) {
    for(int j = 0; j <= std::min(n, a[i]); j++) {
      dp[i][j] = dp[i-1][std::min(j, a[i-1])] + (j != a[i]) - std::min(j, a[i-1]);
    }

    for(int j = std::min(n, a[i]); j >= 0; j--) {
      dp[i][j] = dp[i][j] + j;
      if(j+1 <= std::min(n, a[i]))
        dp[i][j] = std::min(dp[i][j], dp[i][j+1]);
    }
  }

  std::cout << std::min(n, dp[n-1][0]) << std::endl;

  return 0;
}