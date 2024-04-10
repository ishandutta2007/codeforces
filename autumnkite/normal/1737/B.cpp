#include <bits/stdc++.h>

long long solve(long long n) {
  long long t = sqrtl(n);
  while (t * t > n) {
    --t;
  }
  while ((t + 1) * (t + 1) <= n) {
    ++t;
  }
  return 3 * t - 2 + (t * (t + 1) <= n) + (t * (t + 2) <= n);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    long long l, r;
    std::cin >> l >> r;
    std::cout << solve(r) - solve(l - 1) << "\n";
  }
}