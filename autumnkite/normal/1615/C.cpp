#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    int c[2][2] = {};
    for (int i = 0; i < n; ++i) {
      ++c[a[i] ^ '0'][b[i] ^ '0'];
    }
    int ans = n + 1;
    if (c[0][1] == c[1][0]) {
      ans = std::min(ans, c[0][1] + c[1][0]);
    }
    if (c[1][1] == c[0][0] + 1) {
      ans = std::min(ans, c[1][1] + c[0][0]);
    }
    if (ans == n + 1) {
      std::cout << -1 << "\n";
    } else {
      std::cout << ans << "\n";
    }
  }
}