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
      int x;
      std::cin >> x;
      while (x % 10 != 2 && x % 10 != 0) {
        x += x % 10;
      }
      if (x % 10 == 2) {
        x %= 20;
      }
      a[i] = x;
    }
    if (std::unique(a.begin(), a.end()) - a.begin() != 1) {
      std::cout << "No\n";
    } else {
      std::cout << "Yes\n";
    }
  }
}