#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
      std::cout << (i+1)%n+1 << " ";
    }

    std::cout << std::endl;
  }

  return 0;
}