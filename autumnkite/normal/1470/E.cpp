#include <bits/stdc++.h>

long long calc(int n, int x) {
  x = std::min(x, n);
  long long ans = 1;
  long long now = 1;
  for (int i = 1; i <= x; ++i) {
    now *= n - i;
    now /= i;
    ans += now;
  }
  return ans;
}

void solve() {
  int n, c, q;
  std::cin >> n >> c >> q;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    --a[i];
  }
  std::vector<std::vector<int>> id(n);
  for (int i = 0; i < n; ++i) {
    id[i].resize(std::min(c + 1, n - i));
    std::iota(id[i].begin(), id[i].end(), i);
    std::sort(id[i].begin(), id[i].end(), [&](int x, int y) {
      return a[x] < a[y];
    });
  }
  std::vector sum(c + 1, std::vector(n + 1, 0ll));
  for (int k = 0; k <= c; ++k) {
    for (int i = 0; i < n; ++i) {
      long long s = 0;
      for (int j : id[i]) {
        if (j == i) {
          break;
        }
        if (j - i <= k) {
          s += calc(n - j - 1, k - j + i);
        }
      }
      sum[k][i + 1] = sum[k][i] + s;
    }
  }

  auto find = [&](int p, int c, long long k) {
    k += sum[c][p];
    int l = p, r = n + 1;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (sum[c][mid] <= k && k < sum[c][mid] + calc(n - mid, c)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return l;
  };

  auto query = [&]() {
    int x;
    long long k;
    std::cin >> x >> k;
    --x, --k;
    if (k >= calc(n, c)) {
      std::cout << -1 << "\n";
      return;
    }
    int p = 0;
    int r = c;

    while (p < n) {
      int t = find(p, r, k);
      if (p <= x && x < t) {
        std::cout << a[x] + 1 << "\n";
        return;
      }
      k -= sum[r][t] - sum[r][p];
      p = t;
      if (p == n) {
        return;
      }
      for (int i : id[p]) {
        if (i - p <= r) {
          long long v = calc(n - i - 1, r - i + p);
          if (k < v) {
            r -= i - p;
            if (p <= x && x <= i) {
              std::cout << a[i - x + p] + 1 << "\n";
              return;
            }
            p = i + 1;
            break;
          }
          k -= v;
        }
      }
    }
  };

  while (q--) {
    query();
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}