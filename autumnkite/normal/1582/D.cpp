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
    std::vector<int> b(n);
    for (int i = 0; i + 2 <= n; i += 2) {
      if (i + 3 == n) {
        if (a[i + 1] + a[i + 2] != 0) {
          b[i] = a[i + 1] + a[i + 2];
          b[i + 1] = -a[i];
          b[i + 2] = -a[i];
        } else {
          b[i] = a[i + 1];
          b[i + 1] = a[i];
          b[i + 2] = 2 * a[i];
        }
        break;
      }
      b[i] = a[i + 1];
      b[i + 1] = -a[i];
    }
    for (int i = 0; i < n; ++i) {
      std::cout << b[i] << " \n"[i == n - 1];
    }
  }
}