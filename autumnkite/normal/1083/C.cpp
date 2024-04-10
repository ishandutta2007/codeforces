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

class tree {
  int n;
  std::vector<int> fa;
  std::vector<std::vector<int>> E;
  std::vector<int> size, dep, son, top;

  void dfs1(int u) {
    size[u] = 1;
    son[u] = -1;
    for (int v : E[u]) {
      dep[v] = dep[u] + 1;
      dfs1(v);
      size[u] += size[v];
      if (son[u] == -1 || size[v] > size[son[u]]) {
        son[u] = v;
      }
    }
  }

  void dfs2(int u, int tp) {
    top[u] = tp;
    if (son[u] != -1) {
      dfs2(son[u], tp);
    }
    for (int v : E[u]) {
      if (v != son[u]) {
        dfs2(v, v);
      }
    }
  }

  int LCA(int u, int v) const {
    while (top[u] != top[v]) {
      if (dep[top[u]] > dep[top[v]]) {
        u = fa[top[u]];
      } else {
        v = fa[top[v]];
      }
    }
    return dep[u] < dep[v] ? u : v;
  }

public:
  tree(std::vector<int> t_fa)
  : n(t_fa.size()), fa(t_fa), E(n),
    size(n), dep(n), son(n), top(n) {
    for (int i = 1; i < n; ++i) {
      E[fa[i]].push_back(i);
    }
    dfs1(0);
    dfs2(0, 0);
  }

  int dist(int u, int v) const {
    return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
  }

  struct path {
    int x, y, len;
    bool is_path;

    path()
    : x(-1), y(-1), len(-1), is_path(false) {}

    path(int u)
    : x(u), y(u), len(0), is_path(true) {}

    path(int t_x, int t_y, int t_len, bool t_is_path)
    : x(t_x), y(t_y), len(t_len), is_path(t_is_path) {}

    bool operator<(const path &rhs) const {
      return !is_path < !rhs.is_path;
    }
  };

  path add(path p, int u) const {
    if (!p.is_path) {
      return p;
    }
    int lenx = dist(u, p.x), leny = dist(u, p.y);
    if (lenx + leny == p.len) {
      return p;
    } else if (lenx + p.len == leny) {
      return path(u, p.y, leny, true);
    } else if (leny + p.len == lenx) {
      return path(u, p.x, lenx, true);
    } else {
      return path();
    }
  }

  path add(path p, path q) const {
    if (!p.is_path || !q.is_path) {
      return path();
    } else {
      return add(add(p, q.x), q.y);
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
  }
  std::vector<int> fa(n, -1);
  for (int i = 1; i < n; ++i) {
    std::cin >> fa[i];
    --fa[i];
  }

  tree T(fa);
  std::vector<int> id(n);
  for (int i = 0; i < n; ++i) {
    id[p[i]] = i;
  }
  seg_tree<tree::path, 
           std::function<tree::path(tree::path, tree::path)>>
  S(id.begin(), id.end(), [&](const tree::path &a, const tree::path &b) {
    return T.add(a, b);
  });
  int q;
  std::cin >> q;
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int x, y;
      std::cin >> x >> y;
      --x, --y;
      S.modify(p[x], y);
      S.modify(p[y], x);
      std::swap(p[x], p[y]);
      std::swap(id[p[x]], id[p[y]]);
    } else {
      std::cout << S.upper_bound(0, n, tree::path(id[0]), tree::path(id[0]))
                << "\n";
    }
  }
}