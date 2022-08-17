#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int l, r;
    std::cin >> l >> r;

    int l2 = r-r/2+(r%2 == 0);
    l2 = std::max(l, l2);
    std::cout << (r%l2) << std::endl;
  }

  return 0;
}