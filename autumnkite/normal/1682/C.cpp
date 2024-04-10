#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      ++cnt[x];
    }
    int c = 0, d = 0;
    for (auto [x, v] : cnt) {
      if (v == 1) {
        ++c;
      } else {
        ++d;
      }
    }
    std::cout << d + (c + 1) / 2 << "\n";
  }
}