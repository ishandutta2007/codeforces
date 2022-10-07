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
    while (n > 1) {
      int p = n - 1;
      while (p > 0 && a[p]) {
        --p;
      }
      for (int i = p; i < n; ++i) {
        a[i] = a[i + 1] - a[i];
      }
      a.pop_back();
      --n;
      std::sort(a.begin() + p, a.end());
    }
    std::cout << a[0] << "\n";
  }
}