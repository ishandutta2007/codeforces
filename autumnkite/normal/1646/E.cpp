#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  int lg = std::__lg(n);
  std::vector<long long> cnt(lg + 1);
  for (int k = 1; k <= lg; ++k) {
    for (int S = 1; S < (1 << k); ++S) {
      int min = 0, lcm = 1, sgn = -1;
      for (int i = 1; i <= k; ++i) {
        if (S >> (i - 1) & 1) {
          sgn = -sgn;
          if (!min) {
            min = i;
          } else {
            lcm = std::lcm(lcm, i / std::gcd(i, min));
          }
        }
      }
      cnt[k] += sgn * (m / lcm);
    }
  }

  std::vector<bool> vis(n + 1);
  long long ans = 1;
  for (int i = 2; i <= n; ++i) {
    if (!vis[i]) {
      int c = 1;
      for (int j = i; j <= n / i; j *= i) {
        vis[i * j] = true;
        ++c;
      }
      ans += cnt[c];
    }
  }
  std::cout << ans << "\n";
}