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
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      sum += a[i];
    }
    std::cout << (sum % n > 0) << "\n";
  }
}