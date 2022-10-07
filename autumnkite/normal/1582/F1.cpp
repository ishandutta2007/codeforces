#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  int m = std::__lg(std::max(1, *std::max_element(a.begin(), a.end()))) + 1;
  std::vector<std::vector<int>> pos(1 << m);
  for (int i = 0; i < n; ++i) {
    pos[a[i]].push_back(i);
  }
  std::vector<int> f(1 << m, n);
  f[0] = 0;
  for (int i = 0; i < (1 << m); ++i) {
    std::vector<int> g(f);
    for (int S = 0; S < (1 << m); ++S) {
      auto it = std::lower_bound(pos[i].begin(), pos[i].end(), f[S]);
      if (it != pos[i].end()) {
        g[S ^ i] = std::min(g[S ^ i], *it);
      }
    }
    f.swap(g);
  }
  std::vector<int> ans;
  for (int S = 0; S < (1 << m); ++S) {
    if (f[S] < n) {
      ans.push_back(S);
    }
  }
  std::cout << ans.size() << "\n";
  for (int x : ans) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}