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
    for (int& x : a) {
      std::cin >> x;
    }
    std::cout << std::accumulate(a.begin(), a.end(), 0, std::bit_or<int>())
              << "\n";
  }
}