#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  int q;
  std::cin >> q;
  std::vector<std::pair<int, int>> S;
  for (int i = 0; i < q; ++i) {
    int x, y;
    std::cin >> x >> y;
    S.emplace_back(x, y);
  }
  std::sort(S.begin(), S.end());

  std::set<std::pair<int, int>> vis;
  std::vector<std::pair<int, int>> Q;
  Q.emplace_back(1, 1);
  vis.emplace(1, 1);
  int now = 0;
  while (1) {
    ++now;
    std::vector<std::pair<int, int>> R;
    for (auto p : Q) {
      auto [x, y] = p;
      int t = x + y + std::binary_search(S.begin(), S.end(), p);
      std::pair<int, int> px(std::min(t, n), y), py(x, std::min(t, m));
      if (!vis.count(px)) {
        if (px == std::make_pair(n, m)) {
          std::cout << now << "\n";
          return 0;
        }
        R.push_back(px);
      }
      if (!vis.count(py)) {
        if (py == std::make_pair(n, m)) {
          std::cout << now << "\n";
          return 0;
        }
        R.push_back(py);
      }
    }
    std::sort(R.begin(), R.end());
    Q.clear();
    for (auto p : R) {
      while (!Q.empty() && Q.back().first <= p.first
                        && Q.back().second <= p.second) {
        Q.pop_back();
      }
      Q.push_back(p);
    }
  }
}