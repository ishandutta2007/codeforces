#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    long long n, x;
    std::cin >> n >> x;

    auto calc = [&](long long k) {
      if (k <= n) {
        return k * (k + 1) / 2;
      } else {
        k -= n;
        return n * (n + 1) / 2 + (n - k + n - 1) * k / 2;
      }
    };

    long long l = 0, r = 2 * n;
    while (l + 1 < r) {
      long long mid = (l + r) >> 1;
      if (calc(mid) < x) {
        l = mid;
      } else {
        r = mid;
      }
    }
    std::cout << std::min(l + 1, 2 * n - 1) << "\n";
  }
}