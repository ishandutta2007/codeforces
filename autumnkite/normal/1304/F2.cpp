#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> a[i][j];
    }
  }
  a.emplace_back(m, 0);

  auto trans = [&](const std::vector<int> &a,
                   const std::vector<int> &b,
                   const std::vector<int> &f) {
    std::vector<int> sa(m + 1), sb(m + 1);
    for (int i = 0; i < m; ++i) {
      sa[i + 1] = sa[i] + a[i];
      sb[i + 1] = sb[i] + b[i];
    }
    auto calc = [&](int j) {
      return f[j] - sa[j + k];
    };
    std::deque<int> Q;
    std::vector<int> g(m - k + 1);
    int now = 0;
    for (int i = 0; i <= m - k; ++i) {
      while (!Q.empty() && calc(Q.back()) < calc(i)) {
        Q.pop_back();
      }
      Q.push_back(i);
      if (Q.front() <= i - k) {
        Q.pop_front();
      }
      if (i >= k) {
        now = std::max(now, f[i - k]);
      }
      g[i] = calc(Q.front()) + sb[i + k] - sb[i] + sa[i + k];
      g[i] = std::max(g[i], now + sb[i + k] - sb[i] + sa[i + k] - sa[i]);
    }
    return g;
  };

  std::vector<int> f(m - k + 1);
  for (int i = n - 1; i >= 0; --i) {
    auto A = a[i + 1], B = a[i];
    auto g0 = trans(A, B, f);
    std::reverse(A.begin(), A.end());
    std::reverse(B.begin(), B.end());
    std::reverse(f.begin(), f.end());
    auto g1 = trans(A, B, f);
    std::reverse(g1.begin(), g1.end());
    for (int j = 0; j <= m - k; ++j) {
      f[j] = std::max(g0[j], g1[j]);
    }
  }
  std::cout << *std::max_element(f.begin(), f.end()) << "\n";
}