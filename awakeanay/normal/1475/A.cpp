#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    while(n%2 == 0) {
      n /= 2;
    }

    if(n == 1) {
      std::cout << "NO" << std::endl;
    }
    else
       std::cout << "YES" << std::endl;
  }

  return 0;
}