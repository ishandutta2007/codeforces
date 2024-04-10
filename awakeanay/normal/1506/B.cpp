#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    int dp[n];
    int last = -1;
    for(int i = n-1; i >= 0; i--) {
      if(s[i] == '.')
        continue;
      if(last == -1) {
        dp[i] = 1;
        last = i;
        continue;
      }

      dp[i] = n+5;
      for(int j = i+1; j <= std::min(i+k, n-1); j++) {
        if(s[j] == '*')
          dp[i] = std::min(dp[i], dp[j]+1);
      }
      last = i;
    }

    std::cout << dp[last] << std::endl;
  }

  return 0;
}