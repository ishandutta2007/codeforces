#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int x, y;
    std::cin >> x >> y;
    if ((x + y) & 1) {
      std::cout << "-1 -1" << "\n";
    } else {
      int d = (x + y) / 2;
      if (x < y) {
        std::cout << 0 << " " << d << "\n";
      } else {
        std::cout << d << " " << 0 << "\n";
      }
    }
  }
}