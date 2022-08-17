#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    if(k%n == 0)
      std::cout << k/n << std::endl;
    else if(n%k == 0) {
      std::cout << 1 << std::endl;
    }
    else {
      int x = k*((n/k)+1);
      std::cout << x/n + (x%n != 0) << std::endl;
    }
  }

  return 0;
}