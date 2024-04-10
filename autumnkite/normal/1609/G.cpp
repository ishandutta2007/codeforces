#include <bits/stdc++.h>

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

  template<typename Tp>
  size_type lower_bound(size_type u, size_type l, size_type r, 
                        size_type L, size_type R,
                        Val &pre, const Tp &v) {
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

  template<typename Tp>
  size_type upper_bound(size_type u, size_type l, size_type r, 
                        size_type L, size_type R,
                        Val &pre, const Tp &v) {
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

  template<typename Tp>
  size_type lower_bound(size_type l, size_type r, Val E, const Tp &v) {
    return lower_bound(1, 0, n, l, r, E, v);
  }

  template<typename Tp>
  size_type upper_bound(size_type l, size_type r, Val E, const Tp &v) {
    return upper_bound(1, 0, n, l, r, E, v);
  }
};

struct node {
  int l, r;
  long long max, sum, sumi;

  node() : l(), r(), max(), sum(), sumi() {}

  node(int i, long long x) : l(i), r(i + 1), max(x), sum(x), sumi(x * i) {}

  node operator+(const node &rhs) const {
    node res;
    res.l = l, res.r = rhs.r;
    res.max = std::max(max, rhs.max);
    res.sum = sum + rhs.sum;
    res.sumi = sumi + rhs.sumi;
    return res;
  }

  node operator+(long long d) const {
    node res = *this;
    res.max += d;
    res.sum += (r - l) * d;
    res.sumi += 1ll * (r - l) * (l + r - 1) / 2 * d;
    return res;
  }

  bool operator<(long long v) const {
    return max < v;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<long long> a(n - 1), b(m - 1);
  long long sa, sb;
  std::cin >> sa;
  long long la = sa;
  for (int i = 0; i < n - 1; ++i) {
    std::cin >> a[i];
    a[i] -= la;
    la += a[i];
  }
  std::cin >> sb;
  long long lb = sb;
  for (int i = 0; i < m - 1; ++i) {
    std::cin >> b[i];
    b[i] -= lb;
    lb += b[i];
  }

  lazy_seg_tree<node, std::plus<>, long long> T(m - 1);
  for (int i = 0; i < m - 1; ++i) {
    T.modify(i, node(i, b[i]));
  }

  while (q--) {
    int op, k, d;
    std::cin >> op >> k >> d;
    if (op == 1) {
      k = n - k;
      if (k == 0) {
        sa += d;
        ++k;
      }
      for (int i = k - 1; i < n - 1; ++i) {
        a[i] += d;
      }
    } else {
      k = m - k;
      if (k == 0) {
        sb += d;
        ++k;
      }
      T.modify(k - 1, m - 1, d);
    }
    long long ans = (sa + sb) * (n + m - 1);
    int lst = 0;
    for (int i = 0; i < n - 1; ++i) {
      int p = T.lower_bound(0, m - 1, node(), a[i]);
      if (lst < p) {
        auto res = T.query(lst, p);
        ans += res.sum * (m - 1 + n - 1 - i) - res.sumi;
        lst = p;
      }
      ans += a[i] * (m - 1 - lst + n - 1 - i);
    }
    auto res = T.query(lst, m - 1);
    ans += res.sum * (m - 1) - res.sumi;
    std::cout << ans << "\n";
  }
}