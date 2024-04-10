#include <iostream>

#define int long long

const int MOD = 998244353;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int div[n+1];
  for(int i = 0; i <= n; i++)
    div[i] = 0;

  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= n; j+=i)
      div[j]++;
  }

  int dp[n+1];
  dp[0] = 0;
  dp[1] = 1;

  for(int i = 2; i <= n; i++) {
    int cur = (dp[i-1] + div[i])%MOD;
    dp[i] = (dp[i-1] + cur)%MOD;
  }

  std::cout << (dp[n]-dp[n-1]+MOD)%MOD << std::endl;

  return 0;
}