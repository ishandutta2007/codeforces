#include <iostream>

#define int long long

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    if(n%2) {
      n -= 1;
      for(int i = 2; i <= n; i++) {
        if(gcd(i, n-i) == 1) {
          std::cout << i << " " << n-i << " " << 1 << std::endl;
          break;
        }
      }
    }
    else {
      n -= 1;
      std::cout << n/2 << " " << n-n/2 << " " << 1 << std::endl;
    }
  }

  return 0;
}