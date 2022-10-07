#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      ans += (1ll + !x) * (i + 1) * (n - i);
    }
    std::cout << ans << "\n";
  }
}