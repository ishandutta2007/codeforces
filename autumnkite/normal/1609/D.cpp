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

  disjoint_set D(n);
  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    int x, y;
    std::cin >> x >> y;
    --x, --y;
    cnt += !D.merge(x, y);
    std::vector<int> size(n);
    for (int x = 0; x < n; ++x) {
      ++size[D.find(x)];
    }
    std::sort(size.begin(), size.end(), std::greater<int>());
    int ans = 0;
    for (int j = 0; j <= cnt; ++j) {
      ans += size[j];
    }
    std::cout << ans - 1 << "\n";
  }
}