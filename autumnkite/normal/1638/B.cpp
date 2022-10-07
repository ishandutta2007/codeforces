#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a, b;
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      if (x & 1) {
        a.push_back(x);
      } else {
        b.push_back(x);
      }
    }
    if (std::is_sorted(a.begin(), a.end()) &&
        std::is_sorted(b.begin(), b.end())) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  }
}