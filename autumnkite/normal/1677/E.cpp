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

class seg_tree {
  int n;
  fenwick_tree<int> c;
  fenwick_tree<long long> ci;

  void add(int x, int v) {
    c.modify(x, v);
    ci.modify(x, 1ll * x * v);
  }

  long long query(int x) {
    return 1ll * c.query(x) * x - ci.query(x);
  }

public:
  seg_tree(int t_n) : n(t_n), c(n), ci(n) {}

  void add(int l, int r, int v) {
    add(l, v);
    if (r < n) {
      add(r, -v);
    }
  }

  long long query(int l, int r) {
    return query(r) - query(l);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::vector<int> pos(n + 1);
  for (int i = 0; i < n; ++i) {
    pos[a[i]] = i;
  }
  std::vector<std::vector<int>> d(n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) {
      d[j].push_back(i);
    }
  }

  std::vector<int> L(n), R(n);
  std::vector<int> sta;
  for (int i = 0; i < n; ++i) {
    while (!sta.empty() && a[sta.back()] < a[i]) {
      sta.pop_back();
    }
    L[i] = sta.empty() ? 0 : sta.back() + 1;
    sta.push_back(i);
  }
  sta.clear();
  for (int i = n - 1; i >= 0; --i) {
    while (!sta.empty() && a[sta.back()] < a[i]) {
      sta.pop_back();
    }
    R[i] = sta.empty() ? n - 1 : sta.back() - 1;
    sta.push_back(i);
  }

  std::vector<std::vector<std::pair<int, int>>> M(n);
  for (int i = 0; i < n; ++i) {
    if (R[i] - i < i - L[i]) {
      int p = L[i] - 1;
      for (int x : d[a[i]]) {
        if (x != a[i] / x && pos[x] < i && pos[a[i] / x] < i) {
          p = std::max(p, std::min(pos[x], pos[a[i] / x]));
        }
      }
      for (int j = i; j <= R[i]; ++j) {
        if (a[i] % a[j] == 0 && pos[a[i] / a[j]] < j) {
          p = std::max(p, pos[a[i] / a[j]]);
        }
        if (L[i] <= p) {
          M[j].emplace_back(L[i], std::min(p, i) + 1);
        }
      }
    } else {
      int p = R[i] + 1;
      for (int x : d[a[i]]) {
        if (x != a[i] / x && pos[x] > i && pos[a[i] / x] > i) {
          p = std::min(p, std::max(pos[x], pos[a[i] / x]));
        }
      }
      for (int j = i; j >= L[i]; --j) {
        if (a[i] % a[j] == 0 && pos[a[i] / a[j]] > j) {
          p = std::min(p, pos[a[i] / a[j]]);
        }
        if (p <= R[i]) {
          M[j].emplace_back(std::max(p, i), R[i] + 1);
        }
      }
    }
  }
  
  std::vector<std::vector<std::tuple<int, int, int, int>>> Q(n);
  for (int i = 0; i < q; ++i) {
    int l, r;
    std::cin >> l >> r;
    --l;
    Q[r - 1].emplace_back(l, r, i, 1);
    if (l) {
      Q[l - 1].emplace_back(l, r, i, -1);
    }
  }
  std::vector<long long> ans(q);
  seg_tree T(n);
  for (int i = 0; i < n; ++i) {
    for (auto [l, r] : M[i]) {
      T.add(l, r, 1);
    }
    for (auto [l, r, id, v] : Q[i]) {
      ans[id] += v * T.query(l, r);
    }
  }
  for (int i = 0; i < q; ++i) {
    std::cout << ans[i] << "\n";
  }
}