#include <iostream>
#include <vector>

#define int long long

const int MAXN = 4000005;

int dp[MAXN], diff[MAXN], pref[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;


  dp[1] = 1;
  pref[1] = 1;

  for(int i = 1; i <= n; i++) {
    diff[i] = (diff[i] + diff[i-1])%m;
    dp[i] = (dp[i] + diff[i])%m;
    dp[i] = (dp[i] + pref[i-1])%m;
    pref[i] = (pref[i-1] + dp[i])%m;

    for(int j = 2*i; j <= n; j+=i) {
      diff[j] = (diff[j] - dp[i-1] + dp[i] + m)%m;
    }
  }

  std::cout << dp[n] << std::endl;

  return 0;
}