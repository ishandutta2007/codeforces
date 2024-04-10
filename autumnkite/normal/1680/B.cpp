#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::pair<int, int> min(n, m);
    int minx = n, miny = m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        char c;
        std::cin >> c;
        if (c == 'R') {
          min = std::min(min, std::make_pair(i, j));
          minx = std::min(minx, i);
          miny = std::min(miny, j);
        }
      }
    }
    std::cout << (min == std::make_pair(minx, miny) ? "YES\n" : "NO\n");
  }
}