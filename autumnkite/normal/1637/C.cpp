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
    int cnt[2] = {};
    long long sum = 0;
    for (int i = 1; i < n - 1; ++i) {
      sum += a[i];
      ++cnt[a[i] & 1];
    }
    if (cnt[0] || (n > 3 && sum != n - 2)) {
      std::cout << (cnt[1] + 1) / 2 + sum / 2 << "\n";
    } else {
      std::cout << -1 << "\n";
    }
  }
}