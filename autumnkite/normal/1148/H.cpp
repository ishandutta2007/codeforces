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

struct node {
  long long sum, suml, sumr;

  node() : sum(), suml(), sumr() {}

  node(long long t_sum, long long t_suml, long long t_sumr)
    : sum(t_sum), suml(t_suml), sumr(t_sumr) {}
  
  node(int Ll, int Lr, int Rl, int Rr)
    : sum(Rr - Rl), suml(1ll * (Rr - Rl) * Ll), sumr(1ll * (Rr - Rl) * Lr) {}

  node operator+(const node &rhs) const {
    return node(sum + rhs.sum, suml + rhs.suml, sumr + rhs.sumr);
  }

  node operator-(const node &rhs) const {
    return node(sum - rhs.sum, suml - rhs.suml, sumr - rhs.sumr);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  long long ans = 0;
  seg_tree<int, min<int>, std::greater<int>> T(n + 1);
  std::vector<int> lst(n + 1, -1);
  std::vector<std::vector<std::tuple<int, int, int, int>>> tp(n + 1);
  std::vector<std::vector<node>> sum(n + 1, std::vector<node>(1));

  auto insert = [&](int k, int Ll, int Lr, int Rl, int Rr) {
    // std::cerr << k << " " << Ll << " " << Lr << " " << Rl << " " << Rr << "\n";
    tp[k].emplace_back(Ll, Lr, Rl, Rr);
    sum[k].push_back(sum[k].back() + node(Ll, Lr, Rl, Rr));
  };

  for (int q = 1; q <= n; ++q) {
    int v, l, r, k;
    std::cin >> v >> l >> r >> k;
    v = (v + ans) % (n + 1);
    l = (l + ans) % q;
    r = (r + ans) % q;
    k = (k + ans) % (n + 1);
    if (l > r) {
      std::swap(l, r);
    }
    ++r;
    int L = T.query(v, v + 1), R = !v ? q - 1 : T.query(0, v);
    T.modify(v, q);
    if (L < R) {
      if (lst[v] < q - 1) {
        insert(v, L, R, lst[v], q - 1);
      }
      lst[v] = -1;
      int t = v, now = R;
      while (true) {
        t = T.upper_bound(t, n + 1, now, now);
        if (t > n) {
          break;
        }
        int p = T.query(t, t + 1);
        if (p < L) {
          if (lst[v] < q - 1) {
            insert(t, p, L, lst[t], q - 1);
          }
          lst[t] = q - 1;
          break;
        } else {
          lst[t] = q - 1;
          now = p;
        }
      }
    }
    int t = v == 0;
    int p = T.query(t, t + 1);
    insert(t, p, q, lst[t] == -1 ? q - 1 : lst[t], q);
    lst[t] = q;
    ans = 0;
    int x = std::lower_bound(tp[k].begin(), tp[k].end(), l,
            [&](const auto &v, int p) {
              return std::get<1>(v) < p;
            }) - tp[k].begin();
    int y = std::lower_bound(tp[k].begin(), tp[k].end(), l,
            [&](const auto &v, int p) {
              return std::get<0>(v) < p;
            }) - tp[k].begin();
    int z = std::lower_bound(tp[k].begin(), tp[k].end(), r,
            [&](const auto &v, int p) {
              return std::get<3>(v) < p;
            }) - tp[k].begin();
    x = std::min(x, z);
    y = std::min(y, z);
    {
      auto tmp = sum[k][y] - sum[k][x];
      ans += tmp.sumr - tmp.sum * l;
    }
    // std::cerr << ans << "\n";
    {
      auto tmp = sum[k][z] - sum[k][y];
      ans += tmp.sumr - tmp.suml;
    }
    // std::cerr << ans << "\n";
    if (z < (int)tp[k].size()) {
      auto [Ll, Lr, Rl, Rr] = tp[k][z];
      ans += 1ll * (std::max(Lr, l) - std::max(Ll, l))
                 * (std::min(Rr, r) - std::min(Rl, r));
    }
    // std::cerr << ans << "\n";
    if (lst[k] != -1) {
      int Ll = T.query(k, k + 1), Lr = !k ? q : T.query(0, k);
      int Rl = lst[k], Rr = q;
      // std::cerr << Ll << " " << Lr << " " << Rl << " " << Rr << "\n";
      ans += 1ll * (std::max(Lr, l) - std::max(Ll, l))
                 * (std::min(Rr, r) - std::min(Rl, r));
    }
    std::cout << ans << "\n";
    // std::cerr << "\n";
  }
}
/*
5
0 0 0 1
0 1 0 5
5 2 1 0
5 2 1 0
2 4 3 3
*/