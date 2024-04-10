#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  int zero = 0;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    zero += !a[i];
    sum += a[i];
  }

  if (sum + 1ll * zero * k < 0 || sum - 1ll * zero * k > 0) {
    std::cout << -1 << "\n";
    return 0;
  }

  long long ans = 0;
  for (int p = 0; p < n; ++p) {
    int rem = zero;
    long long pre = 0;
    long long all = sum;
    for (int i = 0; i < n; ++i) {
      if (!a[i]) {
        --rem;
        long long t = std::min<long long>(1ll * rem * k - all, k);
        all += t;
        pre += t;
      } else {
        pre += a[i];
      }
      ans = std::max(ans, pre);
    }
    std::rotate(a.begin(), a.begin() + 1, a.end());
  }
  std::cout << ans + 1 << "\n";
}