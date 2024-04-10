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

    int ans = 0;
    while(n > 0) {
      ans = std::max(ans, n%10);
      n /= 10;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}