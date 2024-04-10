#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, H, M;
    std::cin >> n >> H >> M;
    int X = H * 60 + M;
    int ans = 24 * 60;
    for (int i = 0; i < n; ++i) {
      int h, m;
      std::cin >> h >> m;
      int x = h * 60 + m;
      ans = std::min(ans, (x - X + 24 * 60) % (24 * 60));
    }
    std::cout << ans / 60 << " " << ans % 60 << "\n";
  }
}