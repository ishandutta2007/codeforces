#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i] >> b[i];
  }
  int ma = *std::max_element(a.begin(), a.end());
  int mb = *std::max_element(b.begin(), b.end());

  using frac = std::pair<int, int>;

  auto comp = [&](frac a, frac b) {
    return 1ll * a.first * b.second < 1ll * b.first * a.second;
  };

  frac ans(0, 0);
  std::vector<int> ansp;
  for (int t = 1; t <= ma && t <= mb; ++t) {
    std::vector<std::pair<int, int>> c(ma);
    for (int i = 0; i < ma; ++i) {
      c[i].second = i + 1;
    }
    for (int i = 0; i < n; ++i) {
      c[a[i] - 1].first += std::min(b[i], t);
    }
    std::nth_element(c.begin(), c.begin() + ma - t, c.end());
    frac s(0, t);
    std::vector<int> p;
    for (int i = ma - t; i < ma; ++i) {
      s.first += c[i].first;
      p.push_back(c[i].second);
    }
    if (ansp.empty() || comp(ans, s)) {
      ans = s;
      ansp = p;
    }
  }

  std::vector<std::pair<int, int>> c(ma);
  for (int i = 0; i < ma; ++i) {
    c[i].second = i + 1;
  }
  for (int i = 0; i < n; ++i) {
    c[a[i] - 1].first += b[i];
  }
  std::sort(c.begin(), c.end());
  int idx = -1;
  int sum = 0;
  for (int i = ma - 1; i >= 0; --i) {
    sum += c[i].first;
    frac s(sum, ma - i);
    if (ma - i >= mb && comp(ans, s)) {
      ans = s;
      idx = i;
    }
  }
  if (idx != -1) {
    ansp.clear();
    for (int i = idx; i < ma; ++i) {
      ansp.push_back(c[i].second);
    }
  }
  std::cout << ans.second << "\n";
  for (int x : ansp) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}