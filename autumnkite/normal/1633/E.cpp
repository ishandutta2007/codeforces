#include <bits/stdc++.h>

class disjoint_set {
public:
  typedef std::size_t size_type;

protected:
  std::vector<size_type> fa;

public:
  disjoint_set(size_type n = 0) : fa(n) {
    std::iota(fa.begin(), fa.end(), 0);
  }

  size_type find(size_type x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
  }

  bool merge(size_type x, size_type y) {
    x = find(x), y = find(y);
    if (x == y) {
      return false;
    }
    fa[y] = x;
    return true;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::tuple<int, int, int>> edge;
  for (int i = 0; i < m; ++i) {
    int x, y, w;
    std::cin >> x >> y >> w;
    --x, --y;
    edge.emplace_back(w * 2, x, y);
  }
  std::vector<int> val;
  for (auto [w1, x1, y1] : edge) {
    for (auto [w2, x2, y2] : edge) {
      val.push_back((w1 + w2) / 2);
    }
  }
  val.push_back(0);
  std::sort(val.begin(), val.end());
  val.erase(std::unique(val.begin(), val.end()), val.end());

  std::vector<std::pair<long long, long long>> ans(val.size());
  for (int i = 0; i < (int)val.size(); ++i) {
    int r = val[i];
    std::sort(edge.begin(), edge.end(), [&](const auto &a, const auto &b) {
      auto wa = std::get<0>(a), wb = std::get<0>(b);
      auto ra = std::abs(r - wa), rb = std::abs(r - wb);
      if (ra != rb) {
        return ra < rb;
      }
      return wa > wb;
    });
    disjoint_set D(n);
    for (auto [w, u, v] : edge) {
      if (D.merge(u, v)) {
        if (r >= w) {
          ans[i].first += 1;
          ans[i].second -= w;
        } else {
          ans[i].first -= 1;
          ans[i].second += w;
        }
      }
    }
  }

  int p, q, a, b, c;
  std::cin >> p >> q >> a >> b >> c;
  int now = 0;
  long long res = 0;
  for (int i = 0; i < q; ++i) {
    if (i < p) {
      std::cin >> now;
    } else {
      now = (1ll * now * a + b) % c;
    }
    int k = std::upper_bound(val.begin(), val.end(), now * 2) - val.begin() - 1;
    res ^= ans[k].first * now + ans[k].second / 2;
  }
  std::cout << res << "\n";
}