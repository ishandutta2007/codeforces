#include <iostream>

#define int long long

const int LOG = 35;
const int MAXN = 100005;

int dp[LOG][MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    int a[n];
    for(int i = 0; i < LOG; i++)
      dp[i][n] = 0;
    for(int i = 0; i < n; i++)
      std::cin >> a[i];
    for(int i = n-1; i >= 0; i--) {
      for(int j = 0; j < LOG; j++) {
        dp[j][i] = 0;
        if(j+1 < LOG) {
          dp[j][i] = std::max(dp[j][i], (a[i] >> (j+1)) + dp[j+1][i+1]);
        }
        dp[j][i] = std::max(dp[j][i], (a[i] >> j) - k + dp[j][i+1]);
      }
    }

    std::cout << dp[0][0] << std::endl;
  }

  return 0;
}