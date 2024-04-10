#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> p(n * m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        char c;
        std::cin >> c;
        int id = i * m + j;
        p[id] = -1;
        if (c == 'L' && j > 0) {
          p[id] = id - 1;
        }
        if (c == 'R' && j + 1 < m) {
          p[id] = id + 1;
        }
        if (c == 'U' && i > 0) {
          p[id] = id - m;
        }
        if (c == 'D' && i + 1 < n) {
          p[id] = id + m;
        }
      }
    }
    std::vector<int> vis(n * m, -1), s(n * m), lst(n * m);
    for (int i = 0; i < n * m; ++i) {
      if (vis[i] == -1) {
        int u = i;
        int v = -1;
        for (; u != -1 && vis[u] == -1; u = p[u]) {
          vis[u] = i;
          lst[u] = v;
          v = u;
        }
        if (u != -1 && vis[u] == i) {
          int len = 0;
          int x = u;
          do {
            x = p[x];
            ++len;
          } while (x != u);
          do {
            s[v] = len;
            u = v;
            v = lst[v];
          } while (u != x);
        }
        while (v != -1) {
          s[v] = (u == -1 ? 0 : s[u]) + 1;
          u = v;
          v = lst[v];
        }
      }
    }
    int id = std::max_element(s.begin(), s.end()) - s.begin();
    std::cout << id / m + 1 << " " << id % m + 1 << " " << s[id] << "\n";
  }
}