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
    for (int i = 1; i < n - 1; ++i) {
      if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
        ++ans;
        a[i + 1] = std::max(a[i], i + 2 < n ? a[i + 2] : 0);
      }
    }
    std::cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
      std::cout << a[i] << " \n"[i == n - 1];
    }
  }
}