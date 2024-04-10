#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  
  int sx = a[0], sy = b[0];
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  sx = std::lower_bound(a.begin(), a.end(), sx) - a.begin();
  sy = std::lower_bound(b.begin(), b.end(), sy) - b.begin();

  auto check = [&](int v) {
    std::vector<int> px(n), py(m);
    for (int i = 0, j = m - 1; i < n; ++i) {
      while (j >= 0 && a[i] + b[j] > v) {
        --j;
      }
      px[i] = j;
    }
    for (int i = 0, j = n - 1; i < m; ++i) {
      while (j >= 0 && b[i] + a[j] > v) {
        --j;
      }
      py[i] = j;
    }
    std::vector<long long> pre(n + 1);
    for (int i = 0; i < n; ++i) {
      pre[i + 1] = pre[i] + px[i] + 1;
    }

    auto calc = [&](int l, int r) {
      return pre[r] - pre[l];
    };

    long long ans0 = std::max(calc(0, n), 1ll * n * m - calc(0, n));
    long long ans1 = std::max(calc(0, n) - (sy <= px[sx]),
                              1ll * n * m - calc(0, n) - (sy > px[sx]));

    auto sum = [&](int x, int y, bool c) {
      if (px[x] < y) {
        bool flag = false;
        if (c) {
          flag |= sx > x && sy > y;
          flag |= sx <= x && sy <= y && sy <= px[sx];
        }
        int l = py[y];
        return 1ll * (l + 1) * (y + 1) + calc(l + 1, x + 1) +
               1ll * (n - x - 1) * (m - y - 1) - flag;
      } else {
        bool flag = false;
        if (c) {
          flag |= sx <= x && sy <= y;
          flag |= sx > x && sy > y && sy > px[sx];
        }
        int r = py[y];
        return 1ll * (x + 1) * (y + 1) + 1ll * (r - x) * m - calc(x + 1, r + 1) +
               1ll * (n - r - 1) * (m - y - 1) - flag;
      }
    };

    for (int i = 0, p = 0; i < n; ++i) {
      while (p + 1 < m && sum(i, p, 0) <= sum(i, p + 1, 0)) {
        ++p;
      }
      ans0 = std::max(ans0, sum(i, p, 0));
    }
    for (int i = 0, p = 0; i < n; ++i) {
      while (p + 1 < m && sum(i, p, 1) <= sum(i, p + 1, 1)) {
        ++p;
      }
      ans1 = std::max(ans1, sum(i, p, 1));
    }
    return ans0 != ans1 + 1;
  };

  int l = a[0] + b[0] - 1, r = a[sx] + b[sy];
  while(l + 1 < r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  std::cout << r << "\n";
}