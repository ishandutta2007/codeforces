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

    int ans = 0;
    int p10 = 1;
    for(int i = 0; i < 10; i++) {
      ans += (r/p10) - (l/p10);
      p10 *= 10;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}