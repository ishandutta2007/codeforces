#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9 + 5;

struct Seg {
  int f0, f1, m1;

  int& at (int pos) {
    return pos == 0 ? f0 : f1;
  }
};

Seg merge (const Seg &p, const Seg &q) {
  return Seg {.f0 = min(p.f0, q.f0), .f1 = min(p.f1, q.f1), .m1 = max(p.m1, q.m1)};
}

class Segtree {
  int n;
  vector<Seg> tree;
  vector<int> lazy;
  vector<int> lfend;
  vector<int> rgend;

  void propagate (int u) {
    if (lazy[u] == -1) return;

    tree[u].at(lazy[u]) = lfend[u];
    tree[u].at(!lazy[u]) = INF;
    lazy[u] == 1 ? tree[u].m1 = rgend[u] : tree[u].m1 = -1;

    if (u < n) {
      lazy[2 * u] = lazy[u];
      lazy[2 * u + 1] = lazy[u];
    }

    lazy[u] = -1;
  }
  
public:
  Segtree (int _n) {
    n = 1;
    while (n < _n) {
      n *= 2;
    }

    tree = vector<Seg> (2 * n);
    lazy = vector<int> (2 * n, -1);
    lfend = vector<int> (2 * n);
    rgend = vector<int> (2 * n);

    for (int i = n; i < 2 * n; i++) {
      tree[i] = Seg {.f0 = i - n, .f1 = INF, .m1 = -1};
      lfend[i] = i - n;
      rgend[i] = i - n;
    }

    for (int i = n - 1; i > 0; i--) {
      tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }

  void update (int ql, int qr, int val, int u = 1) {
    propagate(u);

    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) return;
    if (ql == lfend[u] && qr == rgend[u]) {
      lazy[u] = val;
      propagate(u);
      return;
    }

    update(ql, qr, val, 2 * u);
    update(ql, qr, val, 2 * u + 1);
    tree[u] = merge(tree[2 * u], tree[2 * u + 1]);
  }

  Seg query (int ql, int qr, int u = 1) {
    propagate(u);

    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) return Seg {.f0 = INF, .f1 = INF, .m1 = -1};
    if (ql == lfend[u] && qr == rgend[u]) return tree[u];
    return merge(query(ql, qr, 2 * u), query(ql, qr, 2 * u + 1));
  }
};

const int MAX_V = 3e5 + 5;

int cur [MAX_V];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, qc;
  cin >> n >> qc;

  for (int i = 0; i < n; i++) {
    cin >> cur[i];
  }
  
  Segtree tree (MAX_V);
  for (int i = 0; i < n; i++) {
    int val = cur[i];
    // add 2**val
    auto seg = tree.query(val, MAX_V - 1);
    tree.update(seg.f0, seg.f0, 1);
    if (val < seg.f0) {
      tree.update(val, seg.f0 - 1, 0);
    }
  }
  
  for (int i = 0; i < qc; i++) {
    int pos, val;
    cin >> pos >> val;
    pos--;

    {
      // subtract 2**sub
      int sub = cur[pos];
      auto seg = tree.query(sub, MAX_V - 1);
      tree.update(seg.f1, seg.f1, 0);
      if (sub < seg.f1) {
        tree.update(sub, seg.f1 - 1, 1);
      }
    }

    cur[pos] = val;

    {
      // add 2**val
      auto seg = tree.query(val, MAX_V - 1);
      tree.update(seg.f0, seg.f0, 1);
      if (val < seg.f0) {
        tree.update(val, seg.f0 - 1, 0);
      }
    }

    cout << tree.query(0, MAX_V - 1).m1 << '\n';
  }
}