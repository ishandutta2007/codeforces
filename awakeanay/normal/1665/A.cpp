#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::cout << n-3 << " " << 1 << " " << 1 << " " << 1 << std::endl;
  }

  return 0;
}