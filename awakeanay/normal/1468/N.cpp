#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int c1, c2, c3;
    std::cin >> c1 >> c2 >> c3;

    int a1, a2, a3, a4, a5;
    std::cin >> a1 >> a2 >> a3 >> a4 >> a5;

    c1 -= a1;
    c2 -= a2;
    c3 -= a3;

    if(c1 < 0 || c2 < 0 || c3 < 0) {
      std::cout << "NO" << std::endl;
      continue;
    }

    a4 -= std::min(a4, c1);
    a5 -= std::min(a5, c2);

    c3 -= a4+a5;

    if(c3 < 0) {
      std::cout << "NO" << std::endl;
      continue;
    }

    std::cout << "YES" << std::endl;
  }

  return 0;
}