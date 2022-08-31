#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int a, b, n;
    std::cin >> a >> b >> n;

    int c = 0;
    while(a <= n && b <= n) {
      if(a < b)
        a ^= b ^= a ^= b;

      b += a;
      c++;
    }

    std::cout << c << std::endl;
  }

  return 0;
}