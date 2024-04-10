#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int l1, r1, l2, r2;
    std::cin >> l1 >> r1 >> l2 >> r2;
    if (std::max(l1, l2) <= std::min(r1, r2)) {
      std::cout << std::max(l1, l2) << "\n";
    } else {
      std::cout << l1 + l2 << "\n";
    }
  }
}