#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  using state = std::pair<long long, int>;
  std::vector<state> c(n);
  int m = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> c[i].first;
    c[i].second = __builtin_popcountll(c[i].first);
    m = std::max(m, c[i].second + 1);
  }

  auto solve = [&](auto &self, int l, int r) -> long long {
    if (l + 1 == r) {
      return 1;
    }
    int mid = (l + r) >> 1;
    long long res = self(self, l, mid) + self(self, mid, r);
    std::vector<state> a(c.begin() + l, c.begin() + mid);
    std::vector<state> b(c.begin() + mid, c.begin() + r);
    std::reverse(a.begin(), a.end());
    std::vector<state> amin(a), amax(a), bmin(b), bmax(b);
    for (std::size_t i = 1; i < a.size(); ++i) {
      amin[i] = std::min(amin[i], amin[i - 1]);
      amax[i] = std::max(amax[i], amax[i - 1]);
    }
    for (std::size_t i = 1; i < b.size(); ++i) {
      bmin[i] = std::min(bmin[i], bmin[i - 1]);
      bmax[i] = std::max(bmax[i], bmax[i - 1]);
    }
    std::vector<int> cnt(b.size() + 1);
    for (std::size_t i = 0; i < b.size(); ++i) {
      cnt[i + 1] = cnt[i] + (bmin[i].second == bmax[i].second);
    }
    std::vector<int> c1(m), c2(m);
    for (std::size_t i = 0, pmin = 0, pmax = 0; i < a.size(); ++i) {
      while (pmin < b.size() && bmin[pmin] >= amin[i]) {
        --c1[bmin[pmin].second];
        ++c2[bmax[pmin].second];
        ++pmin;
      }
      while (pmax < b.size() && bmax[pmax] <= amax[i]) {
        ++c1[bmin[pmax].second];
        --c2[bmax[pmax].second];
        ++pmax;
      }
      if (amin[i].second == amax[i].second) {
        res += std::min(pmin, pmax);
      }
      res += cnt[b.size()] - cnt[std::max(pmin, pmax)];
      if (pmin < pmax) {
        res += c1[amax[i].second];
      } else {
        res += c2[amin[i].second];
      }
    }
    return res;
  };

  std::cout << solve(solve, 0, n) << "\n";
}