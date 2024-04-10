#include <iostream>
#include <map>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    int dp[n];
    int cur = 0;
    std::map<int, int> mp;
    mp[0] = 1;
    for(int i = 0; i < n; i++) {
      cur ^= a[i];
      dp[i] = (a[i] != 0) + (i == 0 ? 0 : dp[i-1]);
      if(mp.find(cur) != mp.end()) {
        dp[i] = std::min(dp[i], i-1+mp[cur]);
        mp[cur] = std::min(mp[cur], dp[i] - i);
      }
      else 
        mp[cur] = dp[i] - i;
    }

    std::cout << dp[n-1] << "\n";
  }

  return 0;
}