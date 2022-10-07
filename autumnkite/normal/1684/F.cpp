#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    std::vector<int> R(n);
    for (int i = 0; i < n; ++i) {
      R[i] = i + 1;
    }
    for (int i = 0; i < m; ++i) {
      int l, r;
      std::cin >> l >> r;
      --l;
      R[l] = std::max(R[l], r);
    }
    for (int i = 1; i < n; ++i) {
      R[i] = std::max(R[i], R[i - 1]);
    }

    std::vector<int> val = a;
    std::sort(val.begin(), val.end());
    val.erase(std::unique(val.begin(), val.end()), val.end());
    for (int i = 0; i < n; ++i) {
      a[i] = std::lower_bound(val.begin(), val.end(), a[i]) - val.begin();
    }
    std::vector<std::vector<int>> pos(val.size());
    for (int i = 0; i < n; ++i) {
      pos[a[i]].push_back(i);
    }

    auto find = [&](int i, int x) {
      auto it = std::lower_bound(pos[x].begin(), pos[x].end(), i);
      if (it == pos[x].begin()) {
        return -1;
      } else {
        return *--it;
      }
    };

    std::vector<int> f(n);
    std::vector<bool> vis(val.size());
    for (int i = 0, j = 0; i < n; ++i) {
      while (vis[a[i]]) {
        vis[a[j]] = false;
        ++j;
      }
      vis[a[i]] = true;
      f[i] = j;
    }

    int j = 0;
    for (int i = 0; i < n; ++i) {
      if (f[R[i] - 1] > i) {
        j = std::max(j, f[R[i] - 1]);
      }
    }
    int ans = j;
    for (int i = 0; i < n; ++i) {
      ans = std::min(ans, j - i);
      int x = find(i, a[i]);
      if (x != -1 && R[x] > i) {
        break;
      }
      j = std::max(j, find(R[i], a[i]) + 1);
    }
    std::cout << ans << "\n";
  }
}