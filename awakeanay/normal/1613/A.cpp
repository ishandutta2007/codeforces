#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int x1, p1, x2, p2;
    std::cin >> x1 >> p1 >> x2 >> p2;

    int min = std::min(p1, p2);
    p2 -= min;
    p1 -= min;

    if(p1 > 10)
      std::cout << '>' << std::endl;
    else if(p2 > 10)
      std::cout << '<' << std::endl;
    else {
      while(p1 != 0) {
        x1 *= 10;
        p1--;
      }
      while(p2 != 0) {
        p2--;
        x2 *= 10;
      }
      if(x1 == x2)
        std::cout << '=' << std::endl;
      else if(x1 < x2)
        std::cout << '<' << std::endl;
      else
        std::cout << '>' << std::endl;
    }
  }

  return 0;
}