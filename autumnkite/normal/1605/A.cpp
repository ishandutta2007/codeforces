#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int x, y, z;
    std::cin >> x >> y >> z;
    if ((x + y - 2 * z) % 3 == 0) {
      std::cout << 0 << "\n";
    } else {
      std::cout << 1 << "\n";
    }
  }
}