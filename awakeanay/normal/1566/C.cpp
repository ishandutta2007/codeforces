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

    int a[n+1], b[n+1];
    for(int i = 0; i < n; i++) {
      char c;
      std::cin >> c;
      a[i+1] = c == '1';
    }
    for(int i = 0; i < n; i++) {
      char c;
      std::cin >> c;
      b[i+1] = c == '1';
    }

    int dp[n+1];
    dp[0] = 0;
    int last_zero = -1, last_one = -1;
    for(int i = 1; i <= n; i++) {
      if(a[i] == 0 || b[i] == 0)
        last_zero = i;
      if(a[i] == 1 || b[i] == 1)
        last_one = i;
      dp[i] = 0;
      if(last_zero != -1)
        dp[i] = std::max(dp[i], dp[last_zero-1] + 1);
      int next = std::min(last_zero, last_one);
      if(next != -1)
        dp[i] = std::max(dp[i], dp[next-1] + 2);
    }

    std::cout << dp[n] << std::endl;
  }

  return 0;
}