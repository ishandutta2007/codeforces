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

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      --a[i];
    }
    std::vector<int> c(n);
    fenwick_tree<int> T(n);
    std::vector<long long> ans(n + 1);
    for (int i = 0; i < n; ++i) {
      c[i] = 2 * a[i] - i;
      ans[0] += i - T.query(a[i]);
      T.modify(a[i], 1);
    }
    std::sort(c.begin(), c.end());
    for (int i = 0; i < n; ++i) {
      ans[i + 1] = ans[i] + c[i];
    }
    for (int i = 1; i <= n; ++i) {
      ans[i] -= 1ll * i * (i - 1) / 2;
    }
    for (auto x : ans) {
      std::cout << x << " ";
    }
    std::cout << "\n";
  }
}