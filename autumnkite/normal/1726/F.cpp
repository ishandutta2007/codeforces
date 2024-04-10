#include <bits/stdc++.h>

class dynamic_seg_tree {
public:
  static int n;
  static int cnt;

  struct node {
    int ls, rs, v;

    node() : ls(), rs(), v() {}

    node(int t_v) : ls(), rs(), v(t_v) {}
  };

  static node nd[20000000];

protected:
  int rt;
  
  void up(int u) {
    nd[u].v = nd[nd[u].ls].v + nd[nd[u].rs].v;
  }

  void add(int &u, int l, int r, int x, int v) {
    nd[cnt] = nd[u];
    u = cnt++;
    if (l + 1 == r) {
      nd[u].v += v;
      return;
    }
    int mid = l + ((r - l) >> 1);
    if (x < mid) {
      add(nd[u].ls, l, mid, x, v);
    } else {
      add(nd[u].rs, mid, r, x, v);
    }
    up(u);
  }

  int query(int u, int l, int r, int L, int R) const {
    if (!u) {
      return 0;
    }
    if (L <= l && r <= R) {
      return nd[u].v;
    }
    int mid = l + ((r - l) >> 1);
    if (R <= mid) {
      return query(nd[u].ls, l, mid, L, R);
    } else if (L >= mid) {
      return query(nd[u].rs, mid, r, L, R);
    } else {
      return query(nd[u].ls, l, mid, L, R) + query(nd[u].rs, mid, r, L, R);
    }
  }

public:
  dynamic_seg_tree() : rt() {}

  void add(int x, int v) {
    add(rt, 0, n, x, v);
  }

  int query(int l, int r) const {
    if (l < r) {
      return query(rt, 0, n, l, r);
    } else {
      return 0;
    }
  }
};

int dynamic_seg_tree::n, dynamic_seg_tree::cnt = 1;
dynamic_seg_tree::node dynamic_seg_tree::nd[20000000];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> g(n), c(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> g[i] >> c[i];
    c[i] = (m - c[i]) % m;
  }
  std::vector<int> d(n - 1), x(n);
  for (int i = 0; i < n - 1; ++i) {
    std::cin >> d[i];
    x[i + 1] = (x[i] + d[i]) % m;
  }
  for (int i = 0; i < n; ++i) {
    c[i] = (c[i] + m - x[i]) % m;
  }

  dynamic_seg_tree::n = m;
  std::vector<dynamic_seg_tree> T(n + 1);
  for (int i = 0; i < n; ++i) {
    T[i + 1] = T[i];
    if (c[i] + g[i] >= m) {
      T[i + 1].add(c[i], 1);
      T[i + 1].add(0, 1);
      T[i + 1].add(c[i] + g[i] - m, -1);
    } else {
      T[i + 1].add(c[i], 1);
      T[i + 1].add(c[i] + g[i], -1);
    }
  }

  std::vector<int> nxt(n);
  for (int i = 0; i < n; ++i) {
    int v = T[i].query(0, c[i] + 1);
    int l = i, r = n + 1;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (T[mid].query(0, c[i] + 1) - v >= mid - i) {
        l = mid;
      } else {
        r = mid;
      }
    }
    nxt[i] = l;
  }
  std::vector<long long> f(n);
  for (int i = n - 1; i >= 0; --i) {
    if (nxt[i] < n) {
      f[i] = f[nxt[i]] + (c[nxt[i]] - c[i] + m) % m;
    }
  }

  auto calc = [&](int v) -> long long {
    int l = 0, r = n + 1;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (T[mid].query(0, v + 1) >= mid) {
        l = mid;
      } else {
        r = mid;
      }
    }
    if (l == n) {
      return 0;
    }
    return f[l] + (c[l] - v + m) % m;
  };

  long long ans = f[0];
  for (int i = 0; i < n; ++i) {
    ans = std::min(ans, calc(c[i]));
    ans = std::min(ans, calc((c[i] + g[i] - 1) % m));
  }
  std::cout << ans + std::accumulate(d.begin(), d.end(), 0ll) << "\n";
}
/*
2 4
2 2
2 0
0
*/