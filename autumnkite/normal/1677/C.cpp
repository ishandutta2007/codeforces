#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      --a[i];
    }
    for (int i = 0; i < n; ++i) {
      std::cin >> b[i];
      --b[i];
    }

    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      p[a[i]] = b[i];
    }
    std::vector<bool> vis(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        int len = 0;
        for (int j = i; !vis[j]; j = p[j]) {
          vis[j] = true;
          ++len;
        }
        cnt += len & 1;
      }
    }

    int m = (n - cnt) / 2;
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
      ans += (n - i - 1) - i;
    }
    std::cout << ans * 2 << "\n";
  }
}