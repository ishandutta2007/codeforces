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

template<typename T>
struct max {
  const T &operator()(const T &a, const T &b) const {
    return a < b ? b : a;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    std::vector<long long> pre(n + 1);
    for (int i = 0; i < n; ++i) {
      pre[i + 1] = pre[i] + a[i];
    }
    std::vector<long long> val(pre);
    std::sort(val.begin(), val.end());
    val.erase(std::unique(val.begin(), val.end()), val.end());

    auto find = [&](int i) -> int {
      return std::lower_bound(val.begin(), val.end(), pre[i]) - val.begin();
    };

    std::vector<int> f(n + 1);
    fenwick_tree<int, max<int>> T(val.size(), -n * 2);
    T.modify(find(0), f[0]);
    for (int i = 0; i < n; ++i) {
      int p = find(i + 1);
      f[i + 1] = std::max(T.query(p) + i + 1, f[i] - (a[i] < 0));
      T.modify(p, f[i + 1] - (i + 1));
    }
    std::cout << f[n] << "\n";
  }
}