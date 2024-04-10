#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    int lg = std::__lg(n - 1);
    int mask = 1 << lg;
    for (int i = mask - 1; i >= 0; --i) {
      std::cout << i << " ";
    }
    for (int i = mask; i < n; ++i) {
      std::cout << i << " ";
    }
    std::cout << "\n";
  }
}