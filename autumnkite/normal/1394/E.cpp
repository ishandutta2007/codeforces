#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int q;
  std::cin >> q;
  std::vector<int> a;
  std::vector<std::vector<int>> L, R;
  std::vector<std::unordered_map<int, int>> f;

  auto DP = [&](auto &self, int l, int r) -> int {
    if (l > r) {
      return 0;
    }
    if (f[r].count(l)) {
      return f[r][l];
    }
    int ans = 0;
    if (!L[l].empty() && l + L[l][0] - 1 <= r) {
      ans = std::max(ans, self(self, l + L[l][0] / 2, r) + 1);
    }
    if (!R[r].empty() && r - R[r][0] + 1 >= l) {
      ans = std::max(ans, self(self, l, r - R[r][0] / 2) + 1);
    }
    return f[r][l] = ans;
  };

  int cnt = 0;
  while (q--) {
    int v;
    std::cin >> v;
    std::vector<int> tmp;
    if (!a.empty()) {
      if (a.back() == v) {
        tmp.push_back(2);
      }
      for (int p : R.back()) {
        if ((int)a.size() > p && a[a.size() - p - 1] == v) {
          tmp.push_back(p + 2);
        }
      }
    }
    L.emplace_back();
    R.push_back(tmp);
    a.push_back(v);
    f.emplace_back();
    for (int p : tmp) {
      L[a.size() - p].push_back(p);
    }
    if (!tmp.empty()) {
      int p = tmp[0] / 2;
      if ((int)a.size() >= 3 * p) {
        bool ok = true;
        for (int i = 0; i < p; ++i) {
          ok &= a[a.size() - 3 * p + i] == a[a.size() - p + i];
        }
        if (ok) {
          for (int i = 0; i < 2 * p; ++i) {
            for (int x : R.back()) {
              L[a.size() - x].pop_back();
            }
            L.pop_back();
            R.pop_back();
            a.pop_back();
            f.pop_back();
          }
          ++cnt;
        }
      }
    }
    std::cout << DP(DP, 0, (int)a.size() - 1) + 2 * cnt << " \n"[q == 0];
  }
}