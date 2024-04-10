#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    long long l, r;
    std::cin >> l >> r;

    if(2*l > r)
      std::cout << -1 << " " << -1;
    else
      std::cout << l << " " << 2*l;

    std::cout << std::endl;
  }

  return 0;
}