#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int ax, ay, bx, by, cx, cy;
    std::cin >> ax >> ay >> bx >> by >> cx >> cy;
    int ans = 0;
    if (ay == by && cy < ay) {
      ans += std::abs(ax - bx);
    }
    if (ay == cy && by < ay) {
      ans += std::abs(ax - cx);
    }
    if (by == cy && ay < by) {
      ans += std::abs(bx - cx);
    }
    std::cout << ans << "\n";
  }
}