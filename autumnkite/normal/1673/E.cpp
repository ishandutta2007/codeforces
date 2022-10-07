#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::bitset<1 << 20> ans;

  auto binom_prefix = [&](int n, int m) -> int {
    if (m < 0) {
      return 0;
    }
    if (n == 0) {
      return 1;
    }
    return ((n - 1) & m) == m;
  };

  for (int i = 0; i < n; ++i) {
    int j = i + 1, sum = 0;
    while (sum < 20 && (1ll * a[i] << sum) < (1 << 20)) {
      int rem_tot = n - j + i - (i > 0) - (j < n);
      int rem_power = n - k - j + i;
      if (binom_prefix(rem_tot, rem_power)) {
        ans.flip(a[i] << sum);
      }
      if (j == n) {
        break;
      }
      sum += a[j];
      ++j;
    }
  }
  
  auto pos = ans.size();
  while (pos > 1 && !ans[pos - 1]) {
    --pos;
  }
  while (pos--) {
    std::cout << ans[pos];
  }
  std::cout << "\n";
}