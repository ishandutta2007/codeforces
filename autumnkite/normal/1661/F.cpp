#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  for (int i = n - 1; i > 0; --i) {
    a[i] -= a[i - 1];
  }

  long long m;
  std::cin >> m;

  auto calc = [&](int x, int c) {
    int t0 = x / c, t1 = t0 + 1;
    int c1 = x % c, c0 = c - c1;
    return 1ll * t0 * t0 * c0 + 1ll * t1 * t1 * c1;
  };

  auto check = [&](long long d) {
    long long res = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      int l = 0, r = a[i];
      while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (calc(a[i], mid) - calc(a[i], mid + 1) >= d) {
          l = mid;
        } else {
          r = mid;
        }
      }
      res += calc(a[i], r);
      cnt += r - 1;
    }
    return std::make_pair(res, cnt);
  };

  long long l = 0, r = 2e18;
  while (l + 1 < r) {
    long long mid = (l + r) >> 1;
    if (check(mid).first <= m) {
      l = mid;
    } else {
      r = mid;
    }
  }
  
  auto [res, cnt] = check(l);
  std::cout << cnt - (m - res) / l << "\n";
}