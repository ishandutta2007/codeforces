#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::cout << (n/2) + (n%2) << std::endl;
  }

  return 0;
}