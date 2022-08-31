#include <iostream>
#include <map>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    std::map<int, int> mp;
    bool poss = false;

    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if(mp[x-k] || mp[x+k])
        poss = 1;
      mp[x] = 1;
    }

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}