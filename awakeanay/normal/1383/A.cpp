#include <iostream>
#include <set>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;

    std::set<std::pair<int, int> > pairs;
    bool poss = true;
    for(int i = 0; i < n; i++) {
      if(s[i] > t[i]) {
        std::cout << -1 << std::endl;
        poss = false;
        break;
      }

      if(s[i] < t[i]) pairs.insert({s[i]-'a', t[i]-'a'});
    }
    
    if(!poss)
      continue;

    int ans = 0;
    while(!pairs.empty()) {
      std::pair<int, int> cur = *pairs.begin(); pairs.erase(pairs.begin());
      ans++;
      while(!pairs.empty() && (*pairs.begin()).first == cur.first) {
        pairs.insert({cur.second, (*pairs.begin()).second});
        pairs.erase(pairs.begin());
      }
    }

    std::cout << ans << std::endl;

  }

  return 0;
}