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
      --a[i];
    }
    int p = 0;
    while (p < n && a[p] == p) {
      ++p;
    }
    if (p < n) {
      int q = std::min_element(a.begin() + p, a.end()) - a.begin();
      std::reverse(a.begin() + p, a.begin() + q + 1);
    }
    for (int i = 0; i < n; ++i) {
      std::cout << a[i] + 1 << " \n"[i + 1 == n];
    }
  }
}