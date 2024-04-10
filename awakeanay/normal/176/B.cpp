#include <iostream>

#define int long long
#define MOD 1000000007

signed main() {
  std::string s, t;
  std::cin >> s >> t;

  int n = s.length();
  int c = 0;
  bool best = false;
  for(int i = 0; i < n; i++) {
    if(s.substr(i, n-i) + s.substr(0, i) == t) {
      c++;
      if(i == 0) best = true;
    }
  }

  int k;
  std::cin >> k;

  int dp[2][k+1];
  dp[0][0] = best;
  dp[1][0] = !best;

  int y = n-c;

  for(int i = 1; i <= k; i++) {
    dp[0][i] = (dp[0][i-1]*(c-1) + dp[1][i-1]*c)%MOD;
    dp[1][i] = (dp[1][i-1]*(y-1) + dp[0][i-1]*y)%MOD;
  }

  if(c == 0)
    std::cout << 0 << std::endl;
  else
    std::cout << dp[0][k] << std::endl;
  return 0;
}