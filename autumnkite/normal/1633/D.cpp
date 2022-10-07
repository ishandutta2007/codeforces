#include <bits/stdc++.h>

const int M = 1000;

int dis[M + 1];

void init() {
  for (int i = 1; i <= M; ++i) {
    dis[i] = i;
  }
  dis[1] = 0;
  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= i; ++j) {
      int k = i + i / j;
      if (k <= M) {
        dis[k] = std::min(dis[k], dis[i] + 1);
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  init();
  int T;
  std::cin >> T;
  while (T--) {
    int n, lim;
    std::cin >> n >> lim;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      a[i] = dis[a[i]];
    }
    for (int i = 0; i < n; ++i) {
      std::cin >> b[i];
    }
    std::vector<int> f(1);
    for (int i = 0; i < n; ++i) {
      std::vector<int> g(f.size() + a[i]);
      for (int j = 0; j < (int)f.size(); ++j) {
        g[j] = std::max(g[j], f[j]);
        g[j + a[i]] = std::max(g[j + a[i]], f[j] + b[i]);
      }
      f.swap(g);
    }
    f.resize(lim + 1);
    std::cout << *std::max_element(f.begin(), f.end()) << "\n";
  }
}