#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    int c = 0;
    for (int i = 1; i <= n; ++i) {
      int v;
      std::cin >> v;
      c += std::max(v - (c + i), 0);
    }
    std::cout << c << "\n";
  }
}