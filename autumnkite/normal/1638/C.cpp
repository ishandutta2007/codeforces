#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    int max = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      --x;
      max = std::max(max, x);
      ans += max == i;
    }
    std::cout << ans << "\n";
  }
}