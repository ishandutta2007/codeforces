#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int l, r;
    std::cin >> l >> r;
    int ans = r - l + 1;
    for (int i = 0; i < 18; ++i) {
      auto calc = [&](int n) {
        return (n >> (i + 1) << i) + std::min(1 << i, n & ((1 << (i + 1)) - 1));
      };
      ans = std::min(ans, calc(r + 1) - calc(l));
    }
    std::cout << ans << "\n";
  }
}