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

    std::string s[n];
    std::map<std::string, int> mp;
    for(int i = 0; i < n; i++) {
      std::cin >> s[i];
      mp[s[i]] = 1;
    }

    for(int i = 0; i < n; i++) {
      int ans = 0;
      int j = s[i].size();
      for(int k = 1; k <= j-1; k++) {
        if(mp[s[i].substr(0, k)] && mp[s[i].substr(k, j-k)])
          ans = 1;
      }
      std::cout << ans;
    }

    std::cout << std::endl;
  }

  return 0;
}