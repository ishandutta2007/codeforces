#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    int a[n+1];
    for(int i = 0; i < n; i++)
      std::cin >> a[i+1];

    int dp[n+1];
    int ans = n;
    for(int j = 1; j <= n; j++) {
      dp[j] = 0;
      if(a[j] <= j) {
        dp[j] = 1;
        for(int i = 1; i < j; i++) {
          if(a[i] < a[j] && a[j]-a[i] <= j-i)
            dp[j] = std::max(dp[j], dp[i]+1);
        }
      }
      if(dp[j] >= k)
        ans = std::min(ans, j-a[j]);
    }

    if(ans == n)
      std::cout << -1 << std::endl;
    else
      std::cout << ans << std::endl;
  }

  return 0;
}