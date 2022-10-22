#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

struct fenwick {
  int n;
  vector<int> a;

  fenwick(int n): n(n), a(n) {}

  void add(int i, int v) {
    for (int j = i; j < n; j = j | (j + 1)) {
      a[j] += v;
    }
  }

  int query(int i) {
    int res = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
      res += a[i];
    }
    return res;
  }

  int query(int l, int r) {
    return query(r) - query(l - 1);
  }

  void xset(int l, int r) {
    assert(l <= r);
    int s = query(l, r);
    if (s == r - l + 1) {
      return;
    }
    if (l == r) {
      add(l, 1);
      return;
    }
    int m = (l + r) / 2;
    xset(l, m);
    xset(m + 1, r);
  }

  bool full(int l, int r) {
    assert(l <= r);
    return query(l, r) == r - l + 1;
  }

  int left(int i) {
    int l = i - 1;
    int r = n;

    while (l + 1 < r) {
      int m = (l + r) / 2;
      if (full(i, m)) {
        //cout << "full " << i + 1 + 1 << " " << m + 1 << "\n";
        l = m;
      } else {
        r = m;
      }
    }

    return l;
  }

  int right(int i) {
    if (i < 0) {
      return 0;
    }

    int l = -1;
    int r = i + 1;

    while (l + 1 < r) {
      int m = (l + r) / 2;
      if (!full(m, i)) {
        l = m;
      } else {
        r = m;
      }
    }

    return r;
  }
};

const int INF = 1e9;

struct segtree {
  int n;
  vector<int> tree;

  segtree() {}
  segtree(int n): n(n), tree(n * 4 + 100, INF) {}

  int query(int t, int l, int r, int x, int y) {
    if (x > r || y < l) {
      return INF;
    }

    if (l >= x && r <= y) {
      return tree[t];
    }

    int m = (l + r) / 2;
    return min(query(t * 2 + 1, l, m, x, y), query(t * 2 + 2, m + 1, r, x, y));
  }

  void change(int t, int l, int r, int index, int value) {
    if (l == r) {
      tree[t] = min(tree[t], value);
      return;
    }

    int m = (l + r) / 2;
    if (index <= m) {
      change(t * 2 + 1, l, m, index, value);
    } else {
      change(t * 2 + 2, m + 1, r, index, value);
    }
    tree[t] = min(tree[t * 2 + 1], tree[t * 2 + 2]);
  }

  int query(int l, int r) {
    return query(0, 0, n - 1, l, r);
  }

  void change(int i, int v) {
    change(0, 0, n - 1, i, v);
  }
};

void solve(bool read) {
  int n, q;
  cin >> n >> q;

  fenwick f(n);
  segtree s(n);

  for (int qi = 0; qi < q; ++qi) {
    int t;
    cin >> t;

    if (t == 0) {
      int l, r, x;
      cin >> l >> r >> x;
      --l; --r;

      if (x == 0) {
        f.xset(l, r);
      } else {
        s.change(l, min(s.query(l, l), r));
      }
    } else {
      int i;
      cin >> i;
      --i;

      if (f.query(i, i) == 1) {
        cout << "NO\n";
        continue;
      }

      int r = f.left(i + 1);
      int l = f.right(i - 1);

      //cout << "query " << i + 1 << " range " << l + 1 << " " << r + 1 << endl;

      int minR = s.query(l, r);
      if (minR <= r) {
        cout << "YES\n";
      } else {
        cout << "N/A\n";
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  //cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  //solve(false);

  return 0;
}