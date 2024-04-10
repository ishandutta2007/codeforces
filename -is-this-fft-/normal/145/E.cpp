#include <iostream>
#include <vector>

using namespace std;

struct Seg {
  int c0, c1, m01, m10;

  Seg (int _c0 = 0, int _c1 = 0, int _m01 = 0, int _m10 = 0)
    : c0(_c0), c1(_c1), m01(_m01), m10(_m10) {}

  void flip () {
    swap(c0, c1);
    swap(m01, m10);
  }
};

Seg merge (const Seg& left, const Seg& right) {
  return Seg(left.c0 + right.c0, left.c1 + right.c1,
             max(left.m01 + right.c1, left.c0 + right.m01),
             max(left.m10 + right.c0, left.c1 + right.m10));
}

Seg from (int num) {
  if (num == 4) {
    return Seg(1, 0, 1, 1);
  } else {
    return Seg(0, 1, 1, 1);
  }
}

class Segtree {
  int n;
  vector<Seg> tree;
  vector<int> lfend;
  vector<int> rgend;
  vector<int> lazy;

  void propagate (int u) {
    if (!lazy[u]) return;

    tree[u].flip();
    if (u < n) {
      lazy[2 * u] ^= lazy[u];
      lazy[2 * u + 1] ^= lazy[u];
    }

    lazy[u] = 0;
  }

public:
  Segtree (vector<int> init) {
    n = 1;
    while (n < (int) init.size()) {
      n *= 2;
    }

    tree = vector<Seg> (2 * n);
    lfend = vector<int> (2 * n);
    rgend = vector<int> (2 * n);
    lazy = vector<int> (2 * n, 0);

    for (int i = n; i < 2 * n; i++) {
      if (i - n < (int) init.size()) {
        tree[i] = from(init[i - n]);
      } else {
        tree[i] = Seg();
      }

      lfend[i] = i - n;
      rgend[i] = i - n;
    }

    for (int i = n - 1; i > 0; i--) {
      tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }

  void flip (int ql, int qr, int u = 1) {
    propagate(u);

    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) return;
    if (ql == lfend[u] && qr == rgend[u]) {
      lazy[u] ^= 1;
      propagate(u);
      return;
    }

    flip(ql, qr, 2 * u);
    flip(ql, qr, 2 * u + 1);
    tree[u] = merge(tree[2 * u], tree[2 * u + 1]);
  }

  int count () {
    propagate(1);
    return tree[1].m01;
  }
};

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, qc;
  cin >> n >> qc;

  vector<int> init (n);
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;

    init[i] = c - '0';
  }

  Segtree tree (init);
  for (int i = 0; i < qc; i++) {
    string type;
    cin >> type;

    if (type[0] == 'c') {
      cout << tree.count() << '\n';
    } else {
      int l, r;
      cin >> l >> r;
      l--; r--;
      tree.flip(l, r);
    }
  }
}