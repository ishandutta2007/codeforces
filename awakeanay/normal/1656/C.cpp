#include <iostream>
#include <map>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int one = 0, zero = 0;
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      a[i] = x;
      one |= x == 1;
      zero |= x == 0;
    }

    if(one && zero)
      std::cout << "NO" << std::endl;
    else if(one) {
      std::map<int, int> mp;
      bool imposs = 0;
      for(int i = 0; i < n; i++) {
        if(mp[a[i]+1] || mp[a[i]-1])
          imposs = 1;
        mp[a[i]] = 1;
      }
      std::cout << (imposs ? "NO" : "YES") << std::endl;
    }
    else {
      std::cout << "YES" << std::endl;
    }
  }

  return 0;
}