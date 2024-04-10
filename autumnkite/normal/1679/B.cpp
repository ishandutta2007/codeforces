#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  long long sum = std::accumulate(a.begin(), a.end(), 0ll);
  int lst = -1;
  std::vector<int> sta;
  std::vector<bool> vis(n);

  auto get = [&](int i) {
    if (vis[i] || lst == -1) {
      return a[i];
    } else {
      return lst;
    }
  };

  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int i, x;
      std::cin >> i >> x;
      --i;
      sum += x - get(i);
      vis[i] = true;
      sta.push_back(i);
      a[i] = x;
    } else {
      int x;
      std::cin >> x;
      lst = x;
      while (!sta.empty()) {
        vis[sta.back()] = false;
        sta.pop_back();
      }
      sum = 1ll * x * n;
    }
    std::cout << sum << "\n";
  }
}