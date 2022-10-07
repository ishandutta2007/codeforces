#include <bits/stdc++.h>

constexpr int INF = std::numeric_limits<int>::max() / 2;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, q;
  std::cin >> n >> q;
  std::vector<std::array<int, 2>> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i][0] >> a[i][1];
  }
  a.push_back({0, INF});
  a.push_back({INF, 0});
  n += 2;
  std::sort(a.begin(), a.end());

  std::array<std::vector<int>, 2> id;
  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i < n; ++i) {
      id[k].push_back(i);
    }
    std::sort(id[k].begin(), id[k].end(), [&](int i, int j) {
      return std::pair(a[i][k], a[i][!k]) < std::pair(a[j][k], a[j][!k]);
    });
    id[k].erase(std::unique(id[k].begin(), id[k].end(), [&](int i, int j) {
      return a[i][k] == a[j][k];
    }), id[k].end());
  }

  std::array<std::vector<int>, 2> p;
  std::array<int, 2> lst = {0, 0};
  std::array it = {id[0].begin(), id[1].begin()};
  while (it[0] != id[0].end() && it[1] != id[1].end()) {
    for (int k = 0; k < 2; ++k) {
      while (it[k] != id[k].end() && a[*it[k]][k] < lst[k]) {
        ++it[k];
      }
    }
    std::array<int, 2> c = {a[*it[1]][1] + lst[0] - lst[1], 
                            a[*it[0]][0] - lst[0] + lst[1]};
    int k = c[0] <= a[*it[0]][0];
    if (a[*it[k]][!k] >= c[!k]) {
      ++it[k];
    } else {
      p[k].push_back(a[*it[k]][k]);
      lst[!k] = c[!k], lst[k] = a[*it[k]][k] + 1;
      ++it[k];
      if (it[!k] != id[!k].begin()) {
        --it[!k];
      }
    }
  }

  while (q--) {
    std::array<int, 2> q;
    std::cin >> q[0] >> q[1];
    if (std::binary_search(a.begin(), a.end(), q)) {
      std::cout << "LOSE\n";
      continue;
    }

    auto calc = [&](int k) {
      auto it = std::lower_bound(p[k].begin(), p[k].end(), q[k]);
      if (it != p[k].end() && *it == q[k]) {
        return true;
      }
      q[k] -= it - p[k].begin();
      return false;
    };

    if (calc(0) || calc(1) || q[0] != q[1]) {
      std::cout << "WIN\n";
    } else {
      std::cout << "LOSE\n";
    }
  }
}