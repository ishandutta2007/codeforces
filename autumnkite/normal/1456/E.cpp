#include <bits/stdc++.h>

constexpr long long INF = std::numeric_limits<long long>::max() / 2;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<long long> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i] >> b[i];
  }
  std::vector<long long> c(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> c[i];
  }

  int tot = m * (n + 1) * (n + 1) * 16;
  std::vector<long long> f(tot, -1);

  auto ID = [&](int i, int l, int r, int sl, int sr) {
    return i * (n + 1) * (n + 1) * 16 + l * (n + 1) * 16
           + (r + 1) * 16 + sl * 4 + sr;
  };

  auto solve = [&](auto &self, int i, int l, int r,
                   int sl, int sr) -> long long {
    if (i == m) {
      return l > r ? 0 : INF;
    }
    long long &now = f[ID(i, l, r, sl, sr)];
    if (now != -1) {
      return now;
    }
    now = INF;

    auto get = [&](int x, int sx) {
      return ((sx & 1 ? b[x] : a[x]) >> i) ^ (sx >> 1);
    };

    now = std::min(now, self(self, i + 1, l, r, sl & 1, sr & 1) +
                        (0 < l && r < n - 1 &&
                         (get(l - 1, sl) ^ get(r + 1, sr)) & 1 ? c[i] : 0));
    for (int k = l; k <= r; ++k) {
      for (int t = 0; t < 2; ++t) {
        if (!i) {
          now = std::min(now, self(self, i, l, k - 1, sl, t) +
                              self(self, i, k + 1, r, t, sr));
        }
        long long tmp = get(k, t | 2);
        if ((a[k] >> i) < tmp && tmp < (b[k] >> i)) {
          now = std::min(now, self(self, i, l, k - 1, sl, t | 2) +
                              self(self, i, k + 1, r, t | 2, sr));
        }
      }
    }
    return now;
  };

  std::cout << solve(solve, 0, 0, n - 1, 0, 0) << "\n";
}