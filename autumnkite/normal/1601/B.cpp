#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }
  std::vector<int> b(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> b[i];
  }

  std::set<int> S;
  for (int i = 0; i <= n; ++i) {
    S.insert(i);
  }
  std::vector<int> dis(n + 1, n + 1), pre(n + 1, -1), tmp(n + 1);
  std::vector<int> Q;
  dis[n] = 0;
  Q.push_back(n);
  for (int i = 0; i < (int)Q.size(); ++i) {
    int u = Q[i];
    auto it = S.lower_bound(u - a[u]);
    while (it != S.end() && *it <= u) {
      int v = *it + b[*it];
      if (dis[v] == n + 1) {
        dis[v] = dis[u] + 1;
        pre[v] = u;
        tmp[v] = *it;
        Q.push_back(v);
      }
      it = S.erase(it);
    }
  }
  if (dis[0] == n + 1) {
    std::cout << -1 << "\n";
  } else {
    std::vector<int> ans;
    for (int u = 0; u != n; u = pre[u]) {
      ans.push_back(tmp[u]);
    }
    std::reverse(ans.begin(), ans.end());
    std::cout << ans.size() << "\n";
    for (int x : ans) {
      std::cout << x << " ";
    }
    std::cout << "\n";
  }
}