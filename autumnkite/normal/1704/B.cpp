#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    int ans = 0;
    int min = a[0], max = a[0];
    for (int i = 1; i < n; ++i) {
      min = std::min(min, a[i]);
      max = std::max(max, a[i]);
      if (max - min > 2 * x) {
        ++ans;
        min = max = a[i];
      }
    }
    std::cout << ans << "\n";
  }
}