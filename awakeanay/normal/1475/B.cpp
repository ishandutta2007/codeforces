#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    if(n/2020 < n%2020) {
      std::cout << "NO" << std::endl;
    }
    else
       std::cout << "YES" << std::endl;
  }

  return 0;
}