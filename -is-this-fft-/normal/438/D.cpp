#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct Seg {
  pair<ll, int> mx = make_pair(-1, -1); // <max, idx of max>
  ll sum = 0;
};

Seg op (const Seg &s, const Seg &t) {
  Seg ans;
  ans.mx = max(s.mx, t.mx);
  ans.sum = s.sum + t.sum;
  return ans;
}

class Segtree {
  vector<Seg> tree;
  vector<int> lfend;
  vector<int> rgend;
  int len;

  void update (int u) {
    if (u == 0) return;
    tree[u] = op(tree[2 * u], tree[2 * u + 1]);
    update(u / 2);
  }

public:
  Segtree (int _len) {
    len = 1;
    while (len < _len) {
      len *= 2;
    }

    tree = vector<Seg> (2 * len);
    lfend = vector<int> (2 * len);
    rgend = vector<int> (2 * len);

    for (int i = len; i < 2 * len; i++) {
      tree[i].mx = make_pair(0, i - len);
      tree[i].sum = 0;
      lfend[i] = i - len;
      rgend[i] = i - len;
    }

    for (int i = len - 1; i >= 1; i--) {
      tree[i] = op(tree[2 * i], tree[2 * i + 1]);
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }

  Seg query (int ql, int qr, int u = 1) {
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) return Seg();
    if (ql == lfend[u] && qr == rgend[u]) return tree[u];
    return op(query(ql, qr, 2 * u), query(ql, qr, 2 * u + 1));
  }

  void set (int u, ll val) {
    tree[u + len].mx = make_pair(val, u);
    tree[u + len].sum = val;
    update((u + len) / 2);
  }

  void mod (int l, int r, int k) {
    while (true) {
      auto mx = query(l, r);
      if (mx.mx.first < k) return;
      set(mx.mx.second, mx.mx.first % k);
    }
  }
};

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, qc;
  cin >> n >> qc;

  Segtree tree (n + 1);
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;

    tree.set(i, a);
  }

  for (int i = 0; i < qc; i++) {
    int type;
    cin >> type;

    if (type == 1) {
      int l, r;
      cin >> l >> r;

      cout << tree.query(l, r).sum << '\n';
    } else if (type == 2) {
      int l, r, x;
      cin >> l >> r >> x;

      tree.mod(l, r, x);
    } else if (type == 3) {
      int k, x;
      cin >> k >> x;

      tree.set(k, x);
    }
  }
}