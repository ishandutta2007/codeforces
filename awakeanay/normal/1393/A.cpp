#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    long long n;
    std::cin >> n;

    std::cout << n/2 + 1<< std::endl;
  }

  return 0;
}