#include <bits/stdc++.h>

template<unsigned P>
class modint {
  static_assert(1 <= P);

  using mint = modint<P>;

protected:
  unsigned v;

public:
  modint() : v() {}

  template<typename T, 
           typename std::enable_if<
                    std::is_signed<T>::value
                    && std::is_integral<T>::value,
                    bool>::type = true>
  modint(T _v) {
    long long tmp = _v % static_cast<long long>(P);
    if (tmp < 0) {
      tmp += P;
    }
    v = tmp;
  }

  template<typename T, 
           typename std::enable_if<
                    std::is_unsigned<T>::value
                    && std::is_integral<T>::value,
                    bool>::type = true>
  modint(T _v) {
    v = _v % P;
  }

  unsigned val() const {
    return v;
  }

  static constexpr unsigned mod() {
    return P;
  }

  static mint raw(unsigned v) {
    mint res;
    res.v = v;
    return res;
  }

  mint &operator+=(const mint &rhs) {
    v < P - rhs.v ? v += rhs.v : v -= P - rhs.v;
    return *this;
  }

  mint &operator++() {
    v + 1 < P ? ++v : v = 0;
    return *this;
  }

  mint operator++(int) {
    mint tmp = *this;
    v + 1 < P ? ++v : v = 0;
    return tmp;
  }

  mint &operator-=(const mint &rhs) {
    v < rhs.v ? v += P - rhs.v : v -= rhs.v;
    return *this;
  }

  mint &operator--() {
    v == 0 ? v = P - 1 : --v;
    return *this;
  }

  mint operator--(int) {
    mint tmp = *this;
    v == 0 ? v = P - 1 : --v;
    return tmp;
  }

  mint operator-() const {
    mint res;
    res.v = v == 0 ? 0 : P - v;
    return res;
  }

  mint &operator*=(const mint &rhs) {
    v = static_cast<unsigned long long>(v) * rhs.v % P;
    return *this;
  }

  mint pow(unsigned long long b) const {
    mint a(*this), s(1);
    for (; b; b >>= 1) {
      if (b & 1) {
        s *= a;
      }
      a *= a;
    }
    return s;
  }

  mint inv() const {
    return pow(P - 2);
  }

  friend mint operator+(const mint &lhs, const mint &rhs) {
    return mint(lhs) += rhs;
  }

  friend mint operator-(const mint &lhs, const mint &rhs) {
    return mint(lhs) -= rhs;
  }

  friend mint operator*(const mint &lhs, const mint &rhs) {
    return mint(lhs) *= rhs;
  }

  friend bool operator==(const mint &lhs, const mint &rhs) {
    return lhs.v == rhs.v;
  }

  friend bool operator!=(const mint &lhs, const mint &rhs) {
    return lhs.v != rhs.v;
  }

  friend std::istream &operator>>(std::istream &in, mint &x) {
    return in >> x.v;
  }

  friend std::ostream &operator<<(std::ostream &out, const mint &x) {
    return out << x.v;
  }
};

template<typename Val,
         typename VV = std::plus<>,
         typename Tag = Val,
         typename VT = std::plus<>,
         typename TT = std::plus<>,
         typename Comp = std::less<>>
class lazy_seg_tree {
public:
  typedef std::size_t size_type;

private:
  constexpr static size_type enlarge(size_type n) {
    size_type res = 1;
    while (res < n) {
      res <<= 1;
    }
    return res;
  }

protected:
  const size_type n, en;

  VV fun_vv;
  VT fun_vt;
  TT fun_tt;
  Comp comp;

  std::vector<Val> val;
  std::vector<Tag> tag;

  void up(size_type u) {
    val[u] = fun_vv(val[u << 1], val[u << 1 | 1]);
  }

  void apply(size_type u, const Tag &v) {
    val[u] = fun_vt(val[u], v);
    tag[u] = fun_tt(tag[u], v);
  }

  void down(size_type u) {
    apply(u << 1, tag[u]);
    apply(u << 1 | 1, tag[u]);
    tag[u] = Tag();
  }

  template<typename T>
  void build(size_type u, size_type l, size_type r, 
             const std::vector<T> &a) {
    if (l + 1 == r) {
      val[u] = Val(a[l]);
      return;
    }
    size_type mid = (l + r) >> 1;
    build(u << 1, l, mid, a);
    build(u << 1 | 1, mid, r, a);
    up(u);
  }

  void modify(size_type u, size_type l, size_type r, 
              size_type x, const Val &v) {
    if (l + 1 == r) {
      val[u] = v;
      return;
    }
    size_type mid = (l + r) >> 1;
    down(u);
    if (x < mid) {
      modify(u << 1, l, mid, x, v);
    } else {
      modify(u << 1 | 1, mid, r, x, v);
    }
    up(u);
  }

  void modify(size_type u, size_type l, size_type r, 
              size_type L, size_type R, const Tag &v) {
    if (L <= l && r <= R) {
      apply(u, v);
      return;
    }
    size_type mid = (l + r) >> 1;
    down(u);
    if (L < mid) {
      modify(u << 1, l, mid, L, R, v);
    }
    if (mid < R) {
      modify(u << 1 | 1, mid, r, L, R, v);
    }
    up(u);
  }

  Val query(size_type u, size_type l, size_type r, 
            size_type L, size_type R) {
    if (L <= l && r <= R) {
      return val[u];
    }
    size_type mid = (l + r) >> 1;
    down(u);
    if (R <= mid) {
      return query(u << 1, l, mid, L, R);
    } else if (L >= mid) {
      return query(u << 1 | 1, mid, r, L, R);
    } else {
      return fun_vv(query(u << 1, l, mid, L, R), 
                    query(u << 1 | 1, mid, r, L, R));
    }
  }

  size_type lower_bound(size_type u, size_type l, size_type r, 
                        size_type L, size_type R,
                        Val &pre, const Val &v) {
    if (L <= l && r <= R) {
      const Val &tmp = fun_vv(pre, val[u]);
      if (comp(tmp, v)) {
        pre = tmp;
        return r;
      }
    }
    if (l + 1 == r) {
      return l;
    }
    size_type mid = (l + r) >> 1;
    down(u);
    if (R <= mid) {
      return lower_bound(u << 1, l, mid, L, R, pre, v);
    } else if (L >= mid) {
      return lower_bound(u << 1 | 1, mid, r, L, R, pre, v);
    } else {
      size_type res = lower_bound(u << 1, l, mid, L, R, pre, v);
      if (res < mid) {
        return res;
      } else {
        return lower_bound(u << 1 | 1, mid, r, L, R, pre, v);
      }
    }
  }

  size_type upper_bound(size_type u, size_type l, size_type r, 
                        size_type L, size_type R,
                        Val &pre, const Val &v) {
    if (L <= l && r <= R) {
      const Val &tmp = fun_vv(pre, val[u]);
      if (!comp(v, tmp)) {
        pre = tmp;
        return r;
      }
    }
    if (l + 1 == r) {
      return l;
    }
    size_type mid = (l + r) >> 1;
    down(u);
    if (R <= mid) {
      return upper_bound(u << 1, l, mid, L, R, pre, v);
    } else if (L >= mid) {
      return upper_bound(u << 1 | 1, mid, r, L, R, pre, v);
    } else {
      size_type res = upper_bound(u << 1, l, mid, L, R, pre, v);
      if (res < mid) {
        return res;
      } else {
        return upper_bound(u << 1 | 1, mid, r, L, R, pre, v);
      }
    }
  }

public:
  lazy_seg_tree() : lazy_seg_tree(0) {}

  lazy_seg_tree(size_type _n)
  : n(_n), en(enlarge(n)), val(en << 1), tag(en << 1) {}

  template<typename T>
  lazy_seg_tree(const std::vector<T> &a)
  : n(a.size()), en(enlarge(n)), val(en << 1), tag(en << 1) {
    if (n) {
      build(1, 0, n, a);
    }
  }

  size_type size() const {
    return n;
  }

  void modify(size_type x, const Val &v) {
    modify(1, 0, n, x, v);
  }

  void modify(size_type l, size_type r, const Tag &v) {
    if (l < r) {
      modify(1, 0, n, l, r, v);
    }
  }

  Val query(size_type l, size_type r) {
    if (l < r) {
      return query(1, 0, n, l, r);
    } else {
      return Val();
    }
  }

  size_type lower_bound(size_type l, size_type r, Val E, const Val &v) {
    return lower_bound(1, 0, n, l, r, E, v);
  }

  size_type upper_bound(size_type l, size_type r, Val E, const Val &v) {
    return upper_bound(1, 0, n, l, r, E, v);
  }
};

using mint = modint<1000000007>;

struct cover {
  mint operator()(const mint &sum, bool cov) {
    if (cov) {
      return mint();
    } else {
      return sum;
    }
  }
};

template<typename T>
struct max {
  const T &operator()(const T &a, const T &b) const {
    return std::max(a, b);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<std::vector<std::pair<int, int>>> ins(n + 1), ers(n + 1);
  for (int i = 0; i < q; ++i) {
    int sx, sy, tx, ty;
    std::cin >> sx >> sy >> tx >> ty;
    --sx, --sy;
    ins[sx].emplace_back(sy, ty);
    ers[tx].emplace_back(sy, ty);
  }

  lazy_seg_tree<mint, std::plus<>, bool, cover, std::logical_or<>> T(m);
  lazy_seg_tree<int, max<int>> S(m);
  for (auto p : ins[0]) {
    S.modify(m - p.second, m - p.first, 1);
  }
  T.modify(0, mint::raw(1));

  for (int i = 1; i < n; ++i) {
    std::sort(ins[i].begin(), ins[i].end(), [&](auto x, auto y) {
      return x.first > y.first;
    });
    for (auto p : ins[i]) {
      int x = p.second;
      if (x < m) {
        T.modify(x, T.query(m - S.upper_bound(m - 1 - x, m, 0, 0), x + 1));
      }
      T.modify(p.first, p.second, true);
      S.modify(m - p.second, m - p.first, 1);
    }
    for (auto p : ers[i]) {
      S.modify(m - p.second, m - p.first, -1);
    }
  }
  std::cout << T.query(m - S.upper_bound(0, m, 0, 0), m) << "\n";
}