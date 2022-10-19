#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct LL {
  ll value;

  LL() : value(0) {}

  explicit LL(ll value) : value(value) {}

  LL(const LL& a, const LL& b) {
    value = max(a.value, b.value);
  }
};

struct Add {
  ll value;

  Add() : value(0) {}

  explicit Add(ll value) : value(value) {}

  Add(const Add& a, const Add& b) {
    value = a.value + b.value;
  }
};

void apply(LL& e, const Add& m, int l, int r) {
  e.value += m.value;
  (void) l, (void) r;
}

template<typename E, typename M>
struct ST {
  static constexpr int inf = 1e9;
  int base;
  vector<E> t;
  vector<M> upd;

  static int calc_base(int n) {
    int x = 1;
    while (x < n) {
      x *= 2;
    }
    return x;
  }

  ST() : base(0) {}
  ST(int n) : base(calc_base(n)), t(base * 2), upd(base * 2) {}

  void push(int v, int cl, int cr) {
    int cc = (cl + cr) / 2;
    apply(t[v * 2 + 0], upd[v], cl, cc);
    apply(t[v * 2 + 1], upd[v], cc, cr);
    upd[v * 2 + 0] = M(upd[v * 2 + 0], upd[v]);
    upd[v * 2 + 1] = M(upd[v * 2 + 1], upd[v]);
    upd[v] = M();
  }

  E get(int l, int r, int v = 1, int cl = 0, int cr = inf) {
    cr = min(cr, base);
    if (l <= cl && cr <= r) {
      return t[v];
    }
    if (r <= cl || cr <= l) {
      return E();
    }
    push(v, cl, cr);
    int cc = (cl + cr) / 2;
    return E(get(l, r, v * 2, cl, cc), get(l, r, v * 2 + 1, cc, cr));
  }

  void put(int l, int r, const M& x, int v = 1, int cl = 0, int cr = inf) {
    cr = min(cr, base);
    if (l <= cl && cr <= r) {
      apply(t[v], x, cl, cr);
      upd[v] = M(upd[v], x);
      return;
    }
    if (r <= cl || cr <= l) {
      return;
    }
    push(v, cl, cr);
    int cc = (cl + cr) / 2;
    put(l, r, x, v * 2 + 0, cl, cc);
    put(l, r, x, v * 2 + 1, cc, cr);
    t[v] = E(t[v * 2], t[v * 2 + 1]);
  }

  E& raw_data(int pos) {
    return t[base + pos];
  }

  void build() {
    for (int i = base - 1; i > 0; --i) {
      t[i] = E(t[i * 2], t[i * 2 + 1]);
    }
  }

  void set(int pos, const E& val, int v = 1, int cl = 0, int cr = inf) {
    cr = min(cr, base);
    if (cl + 1 == cr) {
      assert(v == pos + base);
      t[v] = val;
      return;
    }
    push(v, cl, cr);
    int cc = (cl + cr) / 2;
    if (pos < cc) {
      set(pos, val, v * 2, cl, cc);
    } else {
      set(pos, val, v * 2 + 1, cc, cr);
    }
    t[v] = E(t[v * 2], t[v * 2 + 1]);
  }
};

const int S = 1e6 + 100;
ST<LL, Add> tree(S);
ST<LL, Add> sumd(S);

void add_seg(int t, int d, int sgn = 1) {
  tree.put(t, t + 1, Add(t * sgn));
  tree.put(0, t + 1, Add(d * sgn));
  sumd.put(0, t, Add(d * sgn));
}

void del_seg(int t, int d) {
  add_seg(t, d, -1);
}

ll ask(int t) {
  ll to = tree.get(0, t + 1).value;
  to -= sumd.get(t, t + 1).value;
  return max(0ll, to - t);
}

signed main() {
#ifdef LOCAL
  assert(freopen("k.in", "r", stdin));
#endif
  int q;
  cin >> q;
  vector<pair<int, int>> adds;
  for (int i = 0; i < q; ++i) {
    char c;
    int t;
    cin >> c >> t;
    adds.emplace_back(-1, -1);
    if (c == '?') {
      cout << ask(t) << '\n';
    } else if (c == '+') {
      int d;
      cin >> d;
      add_seg(t, d);
      adds.pop_back();
      adds.emplace_back(t, d);
    } else if (c == '-') {
      del_seg(adds[t - 1].first, adds[t - 1].second);
    }
  }
}