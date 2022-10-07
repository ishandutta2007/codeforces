#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      while (a[i] % 2 == 0) {
        a[i] /= 2;
        ++cnt;
      }
    }
    *std::max_element(a.begin(), a.end()) <<= cnt;
    std::cout << std::accumulate(a.begin(), a.end(), 0ll) << "\n";
  }
}