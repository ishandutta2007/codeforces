#include <bits/stdc++.h>

template<typename Val, 
         typename VV = std::plus<>,
         typename Comp = std::less<>>
class seg_tree {
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

  VV vv;
  Comp comp;

  std::vector<Val> val;

  void up(size_type u) {
    val[u] = vv(val[u << 1], val[u << 1 | 1]);
  }

  template<typename Iter>
  void build(size_type u, size_type l, size_type r, Iter &it) {
    if (l + 1 == r) {
      val[u] = Val(*it);
      ++it;
      return;
    }
    size_type mid = (l + r) >> 1;
    build(u << 1, l, mid, it);
    build(u << 1 | 1, mid, r, it);
    up(u);
  }

  void modify(size_type u, size_type l, size_type r, 
              size_type x, const Val &v) {
    if (l + 1 == r) {
      val[u] = v;
      return;
    }
    size_type mid = (l + r) >> 1;
    if (x < mid) {
      modify(u << 1, l, mid, x, v);
    } else {
      modify(u << 1 | 1, mid, r, x, v);
    }
    up(u);
  }

  Val query(size_type u, size_type l, size_type r, 
            size_type L, size_type R) {
    if (L <= l && r <= R) {
      return val[u];
    }
    size_type mid = (l + r) >> 1;
    if (R <= mid) {
      return query(u << 1, l, mid, L, R);
    } else if (L >= mid) {
      return query(u << 1 | 1, mid, r, L, R);
    } else {
      return vv(query(u << 1, l, mid, L, R), 
                query(u << 1 | 1, mid, r, L, R));
    }
  }

  size_type lower_bound(size_type u, size_type l, size_type r, 
                        size_type L, size_type R,
                        Val &pre, const Val &v) {
    if (L <= l && r <= R) {
      const Val &tmp = vv(pre, val[u]);
      if (comp(tmp, v)) {
        pre = tmp;
        return r;
      }
    }
    if (l + 1 == r) {
      return l;
    }
    size_type mid = (l + r) >> 1;
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
      const Val &tmp = vv(pre, val[u]);
      if (!comp(v, tmp)) {
        pre = tmp;
        return r;
      }
    }
    if (l + 1 == r) {
      return l;
    }
    size_type mid = (l + r) >> 1;
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
  seg_tree() : seg_tree(0) {}

  seg_tree(size_type t_n, VV t_vv = VV(), Comp t_comp = Comp())
  : n(t_n), en(enlarge(n)), 
    vv(t_vv), comp(t_comp), val(en << 1) {}

  template<typename Iter>
  seg_tree(Iter first, Iter last, VV t_vv = VV(), Comp t_comp = Comp())
  : seg_tree(last - first, t_vv, t_comp) {
    if (n) {
      build(1, 0, n, first);
    }
  }

  size_type size() const {
    return n;
  }

  VV func_vv() const {
    return vv;
  }

  Comp func_comp() const {
    return comp;
  }

  void modify(size_type x, const Val &v) {
    modify(1, 0, n, x, v);
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

template<typename T>
struct min {
  const T &operator()(const T &a, const T &b) const {
    return std::min(a, b);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, q;
  std::cin >> n >> q;
  std::vector<int> x(n), w(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> x[i] >> w[i];
  }

  std::vector<int> sta;
  std::vector<int> l(n), r(n);
  sta.clear();
  for (int i = 0; i < n; ++i) {
    while (!sta.empty() && w[sta.back()] > w[i]) {
      sta.pop_back();
    }
    l[i] = sta.empty() ? -1 : sta.back();
    sta.push_back(i);
  }
  sta.clear();
  for (int i = n - 1; i >= 0; --i) {
    while (!sta.empty() && w[sta.back()] > w[i]) {
      sta.pop_back();
    }
    r[i] = sta.empty() ? n : sta.back();
    sta.push_back(i);
  }

  std::vector<std::vector<std::pair<int, int>>> Ql(n), Qr(n);
  for (int i = 0; i < q; ++i) {
    int l, r;
    std::cin >> l >> r;
    --l, --r;
    Ql[l].emplace_back(r, i);
    Qr[r].emplace_back(l, i);
  }

  std::vector<long long> ans(q, 4e18);

  auto dis = [&](int i, int j) {
    return 1ll * (x[j] - x[i]) * (w[i] + w[j]);
  };

  std::vector<long long> tmp(n, 4e18);
  
  seg_tree<long long, min<long long>> Tr(tmp.begin(), tmp.end());
  for (int i = 0; i < n; ++i) {
    if (l[i] != -1) {
      Tr.modify(l[i], std::min(Tr.query(l[i], l[i] + 1), dis(l[i], i)));
    }
    for (auto [l, id] : Qr[i]) {
      ans[id] = std::min(ans[id], Tr.query(l, i));
    }
  }
  
  seg_tree<long long, min<long long>> Tl(tmp.begin(), tmp.end());
  for (int i = n - 1; i >= 0; --i) {
    if (r[i] != n) {
      Tl.modify(r[i], std::min(Tl.query(r[i], r[i] + 1), dis(i, r[i])));
    }
    for (auto [r, id] : Ql[i]) {
      ans[id] = std::min(ans[id], Tl.query(i + 1, r + 1));
    }
  }

  for (int i = 0; i < q; ++i) {
    std::cout << ans[i] << "\n";
  }
}