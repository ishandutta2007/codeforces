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

int query(int u) {
  std::cout << "? " << u + 1 << std::endl;
  int x;
  std::cin >> x;
  --x;
  return x;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> d(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> d[i];
    }
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int x, int y) {
      return d[x] > d[y];
    });
    std::vector<bool> vis(n);
    disjoint_set D(n);
    for (int u : p) {
      if (!vis[u]) {
        vis[u] = true;
        for (int i = 0; i < d[u]; ++i) {
          int v = query(u);
          D.merge(u, v);
          if (vis[v]) {
            break;
          }
          vis[v] = true;
        }
      }
    }
    std::cout << "!";
    for (int i = 0; i < n; ++i) {
      std::cout << " " << D.find(i) + 1;
    }
    std::cout << std::endl;
  }
}