#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    int ans = -1;
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      if (x != i) {
        ans &= x;
      }
    }
    std::cout << ans << "\n";
  }
}