#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> p[i];
  }
  std::vector<int> sta;
  std::vector<int> f(n + 1);
  std::vector<int> g(n + 1);
  f[0] = 0;
  for (int i = 1; i <= n; ++i) {
    if (f[i - 1] >= i) {
      f[i] = std::max(f[i - 1], i + p[i]);
    } else {
      f[i] = f[i - 1];
    }
    g[i] = -1;
    int j = std::lower_bound(f.begin(), f.begin() + i, i - p[i] - 1)
            - f.begin();
    if (j < i) {
      auto it = std::lower_bound(sta.begin(), sta.end(), j + 1);
      int v = it == sta.end() ? i - 1 : *it + p[*it];
      if (v > f[i]) {
        f[i] = v;
        g[i] = j;
      }
    }
    while (!sta.empty() && i + p[i] >= sta.back() + p[sta.back()]) {
      sta.pop_back();
    }
    sta.push_back(i);
  }
  if (f[n] < n) {
    std::cout << "NO\n";
    return;
  }
  int now = n;
  std::string ans(n, 'R');
  while (now > 0) {
    if (g[now] >= 0) {
      for (int i = g[now]; i + 1 < now; ++i) {
        ans[i] = 'R';
      }
      ans[now - 1] = 'L';
      now = g[now];
    } else {
      ans[now - 1] = 'R';
      --now;
    }
  }
  std::cout << "YES\n";
  std::cout << ans << "\n";
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