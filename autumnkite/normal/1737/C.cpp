#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    int x[3], y[3];
    for (int i = 0; i < 3; ++i) {
      std::cin >> x[i] >> y[i];
    }
    int mx = x[0] == x[1] ? x[0] : x[2];
    int my = y[0] == y[1] ? y[0] : y[2];
    int qx, qy;
    std::cin >> qx >> qy;

    if ((mx == 1 || mx == n) && (my == 1 || my == n)) {
      if (qx == mx || qy == my) {
        std::cout << "YES\n";
      } else {
        std::cout << "NO\n";
      }
      continue;
    }
    if ((mx - qx) & 1 && (my - qy) & 1) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
    }
  }
}