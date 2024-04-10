#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    k--;
    if(n%2) {
      std::cout << (1+(k+k/(n/2))%n) << std::endl;
    }
    else {
      std::cout << (1+k%n) << std::endl;
    }
  }

  return 0;
}