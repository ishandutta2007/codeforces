#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<long long> a(n), b(n), c(n), l(n), r(n);
    std::map<long long, std::vector<int>> mp;
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i] >> b[i] >> c[i];
      l[i] = std::max(a[i], c[i]) - c[i];
      r[i] = std::min(a[i], a[i] + b[i] - c[i]);
      mp[a[i] + b[i] - c[i]].push_back(i);
    }
    int ans = 0;
    std::vector<long long> x(n);
    for (auto [s, p] : mp) {
      std::sort(p.begin(), p.end(), [&](int i, int j) {
        return r[i] < r[j] || (r[i] == r[j] && l[i] < l[j]);
      });
      int lst = -1;
      for (int i : p) {
        if (lst < l[i]) {
          lst = r[i];
          ++ans;
        }
        x[i] = lst;
      }
    }
    std::cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
      std::cout << a[i] - x[i] << " " << c[i] - a[i] + x[i] << "\n";
    }
  }
}