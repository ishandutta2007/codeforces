#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    std::string s;
    std::cin >> s;
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    int m = s.size();
    std::vector<int> f(m + 1, m + 1);
    std::vector<std::pair<int, int>> g(m + 1);

    auto upd = [&](int &a, int b) {
      if (b < a) {
        a = b;
        return true;
      } else {
        return false;
      }
    };

    f[0] = 0;
    for (int i = 0; i < m; ++i) {
      if (f[i] != m + 1) {
        for (int j = 0; j <= i; ++j) {
          for (int k = 0; k < n; ++k) {
            if (s.substr(j, a[k].size()) == a[k]) {
              if (upd(f[j + a[k].size()], f[i] + 1)) {
                g[j + a[k].size()] = std::make_pair(i, k);
              }
            }
          }
        }
      }
    }
    if (f[m] == m + 1) {
      std::cout << -1 << "\n";
      continue;
    }
    std::cout << f[m] << "\n";
    int now = m;
    while (now > 0) {
      int k = g[now].second;
      std::cout << k + 1 << " " << now - a[k].size() + 1 << "\n";
      now = g[now].first;
    }
  }
}