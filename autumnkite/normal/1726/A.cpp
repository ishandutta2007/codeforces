#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = std::max(ans, a[i] - a[(i + 1) % n]);
      ans = std::max(ans, a[i] - a[0]);
      ans = std::max(ans, a[n - 1] - a[i]);
    }
    std::cout << ans << "\n";
  }
}