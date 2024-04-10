#include <bits/stdc++.h>

template<typename Val, 
         typename VV = std::plus<Val>>
class fenwick_tree {
public:
  typedef std::size_t size_type;

protected:
  const Val E;

  size_type n;
  std::vector<Val> val;

  VV fun;

public:
  fenwick_tree() : fenwick_tree(0) {}

  fenwick_tree(size_type _n)
  : E(), n(_n), val(n + 1, E) {}

  fenwick_tree(size_type _n, const Val &_E)
  : E(_E), n(_n), val(n + 1, E) {}

  size_type size() const {
    return n;
  }

  void modify(size_type x, const Val &v) {
    for (++x; x <= n; x += x & -x) {
      val[x] = fun(val[x], v);
    }
  }

  Val query(size_type x) {
    Val s = E;
    for (; x; x ^= x & -x) {
      s = fun(s, val[x]);
    }
    return s;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, q;
  std::cin >> n >> q;
  std::vector<int> cntX(n), cntY(n);
  fenwick_tree<int> X(n), Y(n);
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int x, y;
      std::cin >> x >> y;
      --x, --y;
      ++cntX[x];
      ++cntY[y];
      X.modify(x, cntX[x] == 1);
      Y.modify(y, cntY[y] == 1);
    } else if (op == 2) {
      int x, y;
      std::cin >> x >> y;
      --x, --y;
      --cntX[x];
      --cntY[y];
      X.modify(x, -(cntX[x] == 0));
      Y.modify(y, -(cntY[y] == 0));
    } else {
      int sx, sy, tx, ty;
      std::cin >> sx >> sy >> tx >> ty;
      --sx, --sy;
      if (X.query(tx) - X.query(sx) == tx - sx ||
          Y.query(ty) - Y.query(sy) == ty - sy) {
        std::cout << "Yes\n";
      } else {
        std::cout << "No\n";
      }
    }
  }
}