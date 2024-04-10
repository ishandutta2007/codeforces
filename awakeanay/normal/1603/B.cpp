#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int x, y;
    std::cin >> x >> y;

    if(x > y) {
      std::cout << x + y << std::endl;
      continue;
    }
    else if(x == y) {
      std::cout << x << std::endl;
      continue;
    }
    else if(y%x == 0) {
      std::cout << y-x/2 << std::endl;
      continue;
    }

    int lo = y-y%x, hi = y;
    while(lo < hi) {
      int m = (lo+hi)/2;

      int a = m%x;
      int b = y%m;

      if(a >= b)
        hi = m;
      else
        lo = m+1;
    }

    std::cout << lo << std::endl;
  }

  return 0;
}