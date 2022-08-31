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

    int x;
    std::cin >> x;

    for(int i = 1; i < n; i++) {
      int y;
      std::cin >> y;
      x &= y;
    }

    std::cout << x << std::endl;
  }

  return 0;
}