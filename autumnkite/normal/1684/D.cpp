#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    long long sum = std::accumulate(a.begin(), a.end(), 0ll);
    for (int i = 0; i < n; ++i) {
      a[i] = (n - i - 1) - a[i];
    }
    std::nth_element(a.begin(), a.begin() + k - 1, a.end());
    sum += std::accumulate(a.begin(), a.begin() + k, 0ll);
    std::cout << sum - 1ll * k * (k - 1) / 2 << "\n";
  }
}