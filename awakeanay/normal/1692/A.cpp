#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << ((b > a) + (c > a) + (d > a)) << std::endl;
  }

  return 0;
}