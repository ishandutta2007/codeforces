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
    if (std::is_sorted(a.begin(), a.end())) {
      std::cout << 0 << "\n";
      continue;
    }
    if (a[n - 2] > a[n - 1] || a[n - 1] < 0) {
      std::cout << -1 << "\n";
      continue;
    }
    std::cout << n - 2 << "\n";
    for (int i = 0; i < n - 2; ++i) {
      std::cout << i + 1 << " " << n - 1 << " " << n << "\n";
    }
  }
}