#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;

    if (n == 2) {
      std::cout << -1 << "\n";
      continue;
    }
    if ((n & -n) == n) {
      --n;
    }

    std::vector<std::pair<int, int>> ans;
    std::vector<int> val;

    auto solve = [&](auto &self, int n, int k) -> void {
      if (n <= 2) {
        for (int i = 0; i < n; ++i) {
          val.push_back(1 << (k + i));
        }
        return;
      }
      if ((n & -n) == n) {
        val.push_back(n << k);
        --n;
      }
      int p = 1 << std::__lg(n);
      val.push_back(p << k);
      for (int i = 1; i <= n - p; ++i) {
        ans.emplace_back((p - i) << k, (p + i) << k);
        val.push_back(p << (k + 1));
      }
      self(self, 2 * p - n - 1, k);
      self(self, n - p, k + 1);
    };

    solve(solve, n, 0);
    int X = 1 << (std::__lg(n) + 1);
    std::sort(val.begin(), val.end());
    int pos = 0, v = 0;
    for (int i = 1; i < (int)val.size(); ++i) {
      if (val[i] < X && val[i] == val[i - 1]) {
        v = val[i];
        pos = i;
        break;
      }
    }
    if (pos > 0) {
      ans.emplace_back(v, v);
      val.erase(val.begin() + pos);
      val[pos - 1] *= 2;
      for (int x : val) {
        while (x < X) {
          ans.emplace_back(0, x);
          ans.emplace_back(x, x);
          x *= 2;
        }
      }
      ans.emplace_back(0, X);
    }
    std::cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
      std::cout << x << " " << y << "\n";
    }
  }
}