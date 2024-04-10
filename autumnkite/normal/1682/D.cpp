#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      char c;
      std::cin >> c;
      a[i] = c - '0';
    }

    int sum = std::accumulate(a.begin(), a.end(), 0);
    if (sum & 1 || !sum) {
      std::cout << "NO\n";
      continue;
    }

    std::vector<std::pair<int, int>> ans;
    std::set<int> S;
    std::vector<int> pr(n), nx(n);
    for (int i = 0; i < n; ++i) {
      pr[i] = (i + n - 1) % n;
      nx[i] = (i + 1) % n;
      if (a[i]) {
        S.insert(i);
      }
    }

    auto change = [&](int u) {
      a[u] ^= 1;
      if (a[u]) {
        S.insert(u);
      } else {
        S.erase(u);
      }
    };

    for (int k = 0; k < n - 1; ++k) {
      int u = *S.begin();
      int v0 = pr[u], v1 = nx[u];
      if (!a[v0]) {
        change(u);
        change(v0);
        ans.emplace_back(u, v0);
      } else {
        change(u);
        change(v1);
        ans.emplace_back(u, v1);
      }
      nx[v0] = v1;
      pr[v1] = v0;
    }
    std::cout << "YES\n";
    for (auto [x, y] : ans) {
      std::cout << x + 1 << " " << y + 1 << "\n";
    }
  }
}