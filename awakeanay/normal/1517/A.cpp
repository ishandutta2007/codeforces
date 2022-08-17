#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    if(n%2050) {
      std::cout << -1 << std::endl;
    }
    else {
      int k = n/2050;
      int ans = 0;
      while(k > 0) {
        ans += k%10;
        k /= 10;
      }

      std::cout << ans << std::endl;
    }
  }

  return 0;
}