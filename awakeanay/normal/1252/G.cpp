#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    long long a, b, c, p;
    std::cin >> p >> b >> c >> a;

    std::cout << std::min(std::min((a-p%a)%a, (b-p%b)%b), (c-p%c)%c) << std::endl;
  }

  return 0;
}