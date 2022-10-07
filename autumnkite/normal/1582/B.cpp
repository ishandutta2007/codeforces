#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    int c[2] = {};
    for (int i = 0; i < n; ++i) {
      int v;
      std::cin >> v;
      if (v < 2) {
        ++c[v];
      }
    }
    std::cout << (1ll << c[0]) * c[1] << "\n";
  }
}