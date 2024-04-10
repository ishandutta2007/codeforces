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
    while (l + 1 < n && a[l] != a[l + 1]) {
      ++l;
    }
    while (r >= 1 && a[r] != a[r - 1]) {
      --r;
    }
    if (r - l <= 1) {
      std::cout << 0 << "\n";
      continue;
    }
    std::cout << std::max(r - l - 2, 1) << "\n";
  }
}