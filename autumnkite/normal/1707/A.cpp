#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }

    std::vector<int> ans(n);

    auto check = [&](int c) {
      for (int i = 0; i < n; ++i) {
        if (a[i] <= q) {
          ans[i] = 1;
          --c;
        } else {
          ans[i] = 0;
        }
      }
      if (c <= 0) {
        return true;
      }
      int p = n - 1;
      while (p >= 0) {
        if (a[p] > q) {
          --c;
          if (c == 0) {
            break;
          }
        }
        --p;
      }
      int m = q;
      for (int i = p; i < n; ++i) {
        if (!m) {
          return false;
        }
        if (a[i] > m) {
          --m;
        }
      }
      for (int i = p; i < n; ++i) {
        ans[i] = 1;
      }
      return true;
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
    check(l);
    for (int i = 0; i < n; ++i) {
      std::cout << ans[i];
    }
    std::cout << "\n";
  }
}