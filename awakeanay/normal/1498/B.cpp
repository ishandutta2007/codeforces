#include <iostream>
#include <algorithm>
#include <set>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, W;
    std::cin >> n >> W;

    int a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    std::sort(a, a+n);
    std::reverse(a, a+n);

    int count = 0;
    std::set<std::pair<int, int> > ms;
    for(int i = 0; i < n; i++) {
      auto it = ms.lower_bound({a[i], -1});
      if(it == ms.end()) {
        ms.insert({W-a[i], count++});
      }
      else {
        int cur = (*it).first;
        ms.erase(it);
        ms.insert({cur-a[i], count++});
      }
    }

    std::cout << ms.size() << std::endl;
  }

  return 0;
}