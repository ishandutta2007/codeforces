#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long double ld;

const ld INF = 1e18;

struct Seg {
  ld mn, mx, diff;

  Seg () : mn(INF), mx(-INF), diff(0) {
  }

  Seg (ld val) : mn(val), mx(val), diff(0) {
  }

  Seg (ld _mn, ld _mx, ld _diff) : mn(_mn), mx(_mx), diff(_diff) {
  }
};

Seg merge (Seg l, Seg r) {
  return Seg(min(l.mn, r.mn), max(l.mx, r.mx),
             max({l.diff, r.diff, r.mx - l.mn}));
}

class Segtree {
  int n;
  vector<Seg> tree;
  vector<int> lfend;
  vector<int> rgend;

  void update (int u) {
    if (u == 0) return;
    tree[u] = merge(tree[2 * u], tree[2 * u + 1]);
    update(u / 2);
  }

public:
  Segtree (int _n) {
    n = 1;
    while (n < _n) {
      n *= 2;
    }

    tree = vector<Seg> (2 * n, Seg());
    lfend = vector<int> (2 * n);
    rgend = vector<int> (2 * n);

    for (int i = n; i < 2 * n; i++) {
      lfend[i] = i - n;
      rgend[i] = i - n;
    }

    for (int i = n - 1; i > 0; i--) {
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }

  Seg query (int ql, int qr, int u = 1) {
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) {
      return Seg();
    }

    if (ql == lfend[u] && qr == rgend[u]) {
      return tree[u];
    }

    return merge(query(ql, qr, 2 * u),
                 query(ql, qr, 2 * u + 1));
  }

  void set (int pos, Seg val) {
    tree[n + pos] = val;
    update((n + pos) / 2);
  }
};

const int MAX_N = 2e5 + 5;

int X [MAX_N];
ld P [MAX_N];
ld arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, qc, C;
  cin >> n >> qc >> C;

  for (int i = 0; i < n; i++) {
    cin >> X[i];
  }

  for (int i = 0; i < n - 1; i++) {
    int p;
    cin >> p;

    P[i] = (ld) C * (ld) p / 100;
  }

  for (int i = 1; i < n; i++) {
    arr[i] = P[i - 1] + arr[i - 1];
  }

  for (int i = 0; i < n; i++) {
    arr[i] = -arr[i] + (ld) X[i] / 2;
  }

  Segtree tree (n);
  for (int i = 0; i < n; i++) {
    tree.set(i, arr[i]);
  }

  ld ans = 0;
  for (int i = 0; i < qc; i++) {
    int l, r;
    cin >> l >> r;
    l--; r--;

    ans += tree.query(l, r).diff;
  }

  cout << fixed << setprecision(12) << ans << endl;
}