#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9 + 5;

class Segtree {
  int n;
  vector<int> tree;
  vector<int> lfend;
  vector<int> rgend;

public:
  Segtree (int _n) {
    n = 1;
    while (n < _n) {
      n *= 2;
    }

    tree = vector<int> (2 * n, INF);
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

  int query (int ql, int qr, int u = 1) {
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) return INF;
    if (ql == lfend[u] && qr == rgend[u]) return tree[u];
    return min(query(ql, qr, 2 * u), query(ql, qr, 2 * u + 1));
  }

  void set (int idx, int val) {
    tree[n + idx] = val;
    for (int u = (n + idx) / 2; u != 0; u /= 2) {
      tree[u] = min(tree[2 * u], tree[2 * u + 1]);
    }
  }
};

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  Segtree tree (m);
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;

    tree.set(i, n - a);
  }

  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    int xs, ys, xt, yt, K;
    cin >> xs >> ys >> xt >> yt >> K;
    xs = n - xs;
    xt = n - xt;
    ys--; yt--;

    xs %= K;
    xt %= K;
    if (xs != xt) {
      cout << "NO" << '\n';
      continue;
    }

    if (ys % K != yt % K) {
      cout << "NO" << '\n';
      continue;
    }

    int l = min(ys, yt);
    int r = max(ys, yt);
    int mn = tree.query(l, r);
    if (mn <= xs) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }
}