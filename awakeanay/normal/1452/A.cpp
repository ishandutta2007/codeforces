#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int a, b;
    std::cin >> a >> b;
    if(abs(a-b) <= 1) {
      std::cout << a+b << std::endl;
    }
    else {
      std::cout << std::max(2*a-1, 2*b-1) << std::endl;
    }
  }
  return 0;
}