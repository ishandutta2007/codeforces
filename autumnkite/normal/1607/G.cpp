#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    long long m;
    std::cin >> n >> m;
    long long sum = 0;
    std::vector<long long> l(n), r(n);
    long long L = 0, R = 0;
    for (int i = 0; i < n; ++i) {
      long long a, b;
      std::cin >> a >> b;
      sum += a - b + m;
      l[i] = std::max(b, m) - b;
      r[i] = std::min(a, m);
      L += l[i];
      R += r[i];
    }
    if (sum < 2 * L) {
      std::cout << 2 * L - sum << "\n";
      for (int i = 0; i < n; ++i) {
        std::cout << l[i] << " " << m - l[i] << "\n";
      }
    } else if (sum > 2 * R) {
      std::cout << sum - 2 * R << "\n";
      for (int i = 0; i < n; ++i) {
        std::cout << r[i] << " " << m - r[i] << "\n";
      }
    } else {
      std::cout << (sum & 1) << "\n";
      for (int i = 0; i < n; ++i) {
        L -= l[i];
        R -= r[i];
        long long x = std::min((sum - 2 * L) / 2, r[i]);
        sum -= 2 * x;
        std::cout << x << " " << m - x << "\n";
      }
    }
  }
}