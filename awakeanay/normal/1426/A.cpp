#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, x;
    std::cin >> n >> x;
    if(n == 1 || n == 2)
      std::cout << 1 << std::endl;
    else
      std::cout << (n-3)/x + 2 << std::endl;
  }

  return 0;
}