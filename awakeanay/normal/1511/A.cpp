#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int ans = 0;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      ans += x != 2;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}