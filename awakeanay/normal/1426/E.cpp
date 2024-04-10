#include <iostream>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  int ar, as, ap;
  int br, bs, bp;
  std::cin >> ar >> as >> ap >> br >> bs >> bp;

  int max = std::min(ar, bs) + std::min(as, bp) + std::min(ap, br);
  int min = std::max((int) 0, std::max(ar-bp-br, std::max(as-bs-br, ap-bp-bs)));

  std::cout << min << " " << max << std::endl;

  return 0;
}