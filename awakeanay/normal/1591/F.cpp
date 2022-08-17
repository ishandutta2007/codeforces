#include <iostream>

#define int long long

const int MOD = 998244353;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int a[n+1];
  int next[n+1];

  for(int i = 0; i < n; i++)
    std::cin >> a[i];
  a[n] = 0;
  next[n-1] = n;

  int dp[n+1];
  int suff[n+1];
  dp[n] = 1;
  suff[n] = 1;

  for(int i = n-1; i >= 0; i--) {
    next[i] = i+1;
    while(a[next[i]] >= a[i])
      next[i] = next[next[i]];
    int j = next[i];

    int sub;
    if(j == n)
      sub = 0;
    else {
      if((j-i)%2)
        sub = suff[j+1];
      else
        sub = -suff[j+1];
    }

    dp[i] = a[i]*(suff[i+1] + sub + MOD);
    dp[i] %= MOD;

    if(j < n) {
      if((j-i)%2 == 0)
        dp[i] += dp[j];
      else
        dp[i] += MOD-dp[j];
      dp[i] %= MOD;
    }

    suff[i] = (dp[i] - suff[i+1] + MOD)%MOD;
  }

  std::cout << dp[0] << std::endl;

  return 0;
}