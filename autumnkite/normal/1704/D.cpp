#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<long long> sum(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        long long x;
        std::cin >> x;
        sum[i] += x * j;
      }
    }
    auto max = std::max_element(sum.begin(), sum.end());
    auto min = std::min_element(sum.begin(), sum.end());
    std::cout << max - sum.begin() + 1 << " " << *max - *min << "\n";
  }
}