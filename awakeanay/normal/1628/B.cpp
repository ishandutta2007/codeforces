#include <iostream>
#include <algorithm>
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

    std::string s[n], t[n];
    std::map<std::string, int> mp;

    bool poss = false;
    for(int i = 0; i < n; i++) {
      std::cin >> s[i];

      t[i] = s[i];
      std::reverse(t[i].begin(), t[i].end());

      if(s[i] == t[i])
        poss = true;

      if(mp[t[i]])
        poss = true;

      mp[s[i]] = 1;
      if(s[i].length() == 3) {
        mp[s[i].substr(0, 2)] = 1;
      }
    }

    mp.clear();

    for(int i = n-1; i >= 0; i--) {
      if(mp[t[i]])
        poss = true;

      mp[s[i]] = true;
      if(s[i].length() == 3) {
        mp[s[i].substr(1, 2)] = 1;
      }
    }

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}