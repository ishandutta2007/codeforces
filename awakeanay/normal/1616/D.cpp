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

    int a[n+1];
    for(int i = 0; i < n; i++)
      std::cin >> a[i+1];
    int x;
    std::cin >> x;

    int dp[n+1];
    int ans = 1;
    dp[1] = 1;
    dp[0] = 0;

    if(n >= 2) {
      dp[2] = (a[1] + a[2] >= 2*x ? 2 : 1);
      ans = std::max(ans, dp[2]);
    }

    for(int i = 3; i <= n; i++) {
      dp[i] = dp[i-2] + 1;
      if(a[i] + a[i-1] >= 2*x) {
        dp[i] = std::max(dp[i], dp[i-3]+2);
        if(a[i] + a[i-1] + a[i-2] >= 3*x) {
          dp[i] = std::max(dp[i], dp[i-1]+1);
        }
      }
      ans = std::max(ans, dp[i]);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}