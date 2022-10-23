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
      --x;
      a[x] = i;
    }
    for (int i = n - 1; i >= 0; --i) {
      std::cout << a[i] + 1 << " \n"[i == 0];
    }
  }
}