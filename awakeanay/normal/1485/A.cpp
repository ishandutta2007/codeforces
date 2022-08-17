#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int a, b;
    std::cin >> a >> b;

    if(b > a) {
      std::cout << 1 << std::endl;
      continue;
    }

    int ans = a+2-b;
    int count = 0;
    if(b == 1) {
      b++;
      count++;
    }
    while(true) {
      int na = a;
      int nc = count;
      int newc = 0;
      while(na > 0) {
        na /= b;
        nc++;
        newc++;
      }


      ans = std::min(ans, nc);
      if(newc <= 3)
        break;
      b++;
      count++;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}