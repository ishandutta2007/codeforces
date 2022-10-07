#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(m, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        std::cin >> a[j][i];
      }
    }
    std::vector<int> pre(m);
    for (int i = 1; i < m; ++i) {
      if (a[i] > a[pre[i - 1]]) {
        pre[i] = i;
      } else {
        pre[i] = pre[i - 1];
      }
    }
    int x = 0, y = 0;
    for (int i = m - 1; i > 0; --i) {
      if (a[i] < a[pre[i]]) {
        x = pre[i], y = i;
        break;
      }
    }
    std::swap(a[x], a[y]);
    bool ok = true;
    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ok &= a[i - 1][j] <= a[i][j];
      }
    }
    if (ok) {
      std::cout << x + 1 << " " << y + 1 << "\n";
    } else {
      std::cout << -1 << "\n";
    }
  }
}