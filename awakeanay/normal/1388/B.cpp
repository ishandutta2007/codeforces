#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int k = (3*n)/4;
    for(int i = 0; i < k; i++)
      std::cout << 9;
    for(int i = k; i < n; i++)
      std::cout << 8;

    std::cout << std::endl;
  }

  return 0;
}