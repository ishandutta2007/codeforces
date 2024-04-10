#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int a, b;
    std::cin >> a >> b;
    a = std::min(a, 2*b);
    b = std::min(b, 2*a);

    std::cout << (a+b)/3 << std::endl;
  }

  return 0;
}