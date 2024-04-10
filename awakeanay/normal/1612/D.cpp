#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  
  while(t--) {
    int a, b, x;
    std::cin >> a >> b >> x;

    if(a == x || b == x) {
      std::cout << "YES" << std::endl;
      continue;
    }

    while(true) {
      if(a > b)
        a ^= b ^= a ^= b;

      if(a == x || b == x) {
        std::cout << "YES" << std::endl;
        break;
      }
      
      if(a == 0) {
        std::cout << "NO" << std::endl;
        break;
      }

      if(a <= x && x <= b && x%a == b%a) {
        std::cout << "YES" << std::endl;
        break;
      }
      else if(x > b || a == 0) {
        std::cout << "NO" << std::endl;
        break;
      }
      else {
        int till = b/a;
        b -= till*a;
      }
    }
  }

  return 0;
}