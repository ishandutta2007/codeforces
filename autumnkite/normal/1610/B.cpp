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
    int l = 0, r = n - 1;
    while (l < r && a[l] == a[r]) {
      ++l;
      --r;
    }

    auto check = [&](int x) {
      int l = 0, r = n - 1;
      while (l < r) {
        if (a[l] == a[r]) {
          ++l, --r;
        } else if (a[l] == x) {
          ++l;
        } else if (a[r] == x) {
          --r;
        } else {
          return false;
        }
      }
      return true;
    };

    if (l >= r || check(a[l]) || check(a[r])) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}