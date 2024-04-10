#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i] >> b[i];
    }
    auto check = [&](int m) {
      int r = 0;
      for (int i = 0; i < n; ++i) {
        if (m - a[i] - 1 <= r && r <= b[i]) {
          ++r;
        }
      }
      return m <= r;
    };
    int l = 0, r = n + 1;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    std::cout << l << "\n";
  }
}