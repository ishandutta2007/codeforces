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

    int last = 1;
    int max = 1;

    for(int i = 0; i < n; i++) {
      int cur;
      std::cin >> cur;
      max = std::max(max, cur*last);
      last = cur;
    }

    std::cout << max << std::endl;
  }

  return 0;
}