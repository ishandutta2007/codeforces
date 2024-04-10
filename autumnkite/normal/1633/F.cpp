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

struct node {
  int cnt[2];
  long long sum[2];

  node() : cnt(), sum() {}

  node(bool x, int v) : cnt(), sum() {
    ++cnt[x];
    sum[x] += v;
  }

  node operator+(const node &rhs) const {
    node res;
    for (int i = 0; i < 2; ++i) {
      res.cnt[i] = cnt[i] + rhs.cnt[i];
      res.sum[i] = sum[i] + rhs.sum[i];
    }
    return res;
  }

  node operator+(const bool &rhs) const {
    node res(*this);
    if (rhs) {
      std::swap(res.cnt[0], res.cnt[1]);
      std::swap(res.sum[0], res.sum[1]);
    }
    return res;
  }
};

class tree {
  int n, cnt;
  std::vector<std::vector<std::pair<int, int>>> E;
  std::vector<int> fa, fi, dep, size, son, top, dfn, nd;
  lazy_seg_tree<node, std::plus<>, bool, std::plus<>, std::bit_xor<>> T;

  void dfs(int u) {
    size[u] = 1;
    son[u] = -1;
    for (auto [v, id] : E[u]) {
      if (v != fa[u]) {
        fa[v] = u, fi[v] = id;
        dep[v] = dep[u] + 1;
        dfs(v);
        size[u] += size[v];
        if (son[u] == -1 || size[v] > size[son[u]]) {
          son[u] = v;
        }
      }
    }
  }

  void dfs(int u, int tp) {
    top[u] = tp;
    dfn[u] = nd.size();
    nd.push_back(u);
    if (son[u] != -1) {
      dfs(son[u], tp);
    }
    for (auto [v, id] : E[u]) {
      if (v != fa[u] && v != son[u]) {
        dfs(v, v);
      }
    }
  }

public:
  tree(std::vector<std::pair<int, int>> edge)
      : n(edge.size() + 1), cnt(), E(n), fa(n, -1), fi(n, -1),
        dep(n), size(n), son(n), top(n), dfn(n), T(n) {
    for (int i = 0; i < n - 1; ++i) {
      auto [u, v] = edge[i];
      E[u].emplace_back(v, i + 1);
      E[v].emplace_back(u, i + 1);
    }
    dfs(0);
    dfs(0, 0);
    ++cnt;
    T.modify(0, node(1, 0));
  }

  void activate(int u) {
    ++cnt;
    T.modify(dfn[u], node(0, fi[u]));
    while (u != -1) {
      T.modify(dfn[top[u]], dfn[u] + 1, true);
      u = fa[top[u]];
    }
  }

  long long get_sum() {
    auto tmp = T.query(0, n);
    if (2 * tmp.cnt[1] == cnt) {
      return tmp.sum[1];
    } else {
      return 0;
    }
  }

  std::vector<int> match() {
    auto tmp = T.query(0, n);
    std::vector<int> res;
    if (2 * tmp.cnt[1] == cnt) {
      for (int i = 1; i < n; ++i) {
        if (T.query(dfn[i], dfn[i] + 1).cnt[1]) {
          res.push_back(fi[i]);
        }
      }
      std::sort(res.begin(), res.end());
    }
    return res;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> edge;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    edge.emplace_back(u, v);
  }

  tree T(edge);
  while (true) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int x;
      std::cin >> x;
      --x;
      T.activate(x);
      std::cout << T.get_sum() << std::endl;
    } else if (op == 2) {
      auto res = T.match();
      std::cout << res.size();
      for (int id : res) {
        std::cout << " " << id;
      }
      std::cout << std::endl;
    } else {
      return 0;
    }
  }
}