#include <bits/stdc++.h>

void solve() {
  int x, y;
  std::cin >> x >> y;
  if (y < x) {
    std::cout << x + y << "\n";
  } else {
    std::cout << y - (y % x) / 2 << "\n";
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}