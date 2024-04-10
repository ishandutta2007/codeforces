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
    std::vector<int> b[2];
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      b[a[i]].push_back(x);
    }
    std::sort(b[0].begin(), b[0].end(), std::greater<int>());
    std::sort(b[1].begin(), b[1].end(), std::greater<int>());
    if (b[0].size() == b[1].size()) {
      std::cout << 2 * std::accumulate(b[0].begin(), b[0].end(), 0ll) +
                   2 * std::accumulate(b[1].begin(), b[1].end(), 0ll) -
                   std::min(b[0].back(), b[1].back()) << "\n";
    } else {
      auto x = std::min(b[0].size(), b[1].size());
      std::cout << std::accumulate(b[0].begin(), b[0].end(), 0ll) +
                   std::accumulate(b[1].begin(), b[1].end(), 0ll) +
                   std::accumulate(b[0].begin(), b[0].begin() + x, 0ll) +
                   std::accumulate(b[1].begin(), b[1].begin() + x, 0ll) << "\n";
    }
  }
}