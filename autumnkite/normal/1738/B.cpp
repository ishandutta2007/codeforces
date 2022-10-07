#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(m);
    for (int i = 0; i < m; ++i) {
      std::cin >> a[i];
    }
    if (m == 1) {
      std::cout << "Yes\n";
      continue;
    }
    std::vector<int> b(n);
    for (int i = 1; i < m; ++i) {
      b[i + n - m] = a[i] - a[i - 1];
    }
    if (!std::is_sorted(b.begin() + n - m + 1, b.end())) {
      std::cout << "No\n";
      continue;
    }
    if (1ll * b[n - m + 1] * (n - m + 1) >= a[0]) {
      std::cout << "Yes\n";
      continue;
    }
    std::cout << "No\n";
  }
}