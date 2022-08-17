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

    std::string s;
    std::cin >> s;

    std::map<int, int> mp;
    mp[0] = 1;
    int cur = 0;
    int done = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == 'a')
        cur++;
      else
        cur--;
      if(mp[cur]) {
        done = 1;
        std::cout << mp[cur] << " " << i+1 << std::endl;
        break;
      }
      mp[cur] = i+2;
    }

    if(!done)
      std::cout << -1 << " " << -1 << std::endl;
  }

  return 0;
}