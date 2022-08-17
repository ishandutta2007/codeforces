#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    if(n == 1) {
      std::cout << 0 << std::endl;
    }
    else if(n == 2) {
      std::cout << 1 << std::endl;
    }
    else if(n == 3) {
      std::cout << 2 << std::endl;
    }
    else if(n%2) {
      std::cout << 3 << std::endl;
    }
    else {
      std::cout << 2 << std::endl;
    }
  }

  return 0;
}