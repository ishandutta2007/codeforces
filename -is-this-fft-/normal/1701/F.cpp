#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct Seg {
  ll cnt, sum, sumsq;

  Seg (ll _cnt = 0, ll _sum = 0, ll _sumsq = 0) : cnt(_cnt), sum(_sum), sumsq(_sumsq) {}

  void apply (ll add) {
    sumsq += 2 * add * sum + add * add * cnt;
    sum += add * cnt;
  }
};

Seg merge (const Seg& s, const Seg& t) {
  return Seg(s.cnt + t.cnt, s.sum + t.sum, s.sumsq + t.sumsq);
}

class Segtree {
  int n;
  vector<Seg> tree;
  vector<ll> lazy;
  vector<int> lfend;
  vector<int> rgend;

  void propagate (int u) {
    if (lazy[u] == 0) return;

    tree[u].apply(lazy[u]);
    if (u < n) {
      lazy[2 * u] += lazy[u];
      lazy[2 * u + 1] += lazy[u];
    }
    lazy[u] = 0;
  }
  
public:
  Segtree () {}
  
  Segtree (int _n) {
    n = 1;
    while (n < _n) {
      n *= 2;
    }

    tree = vector<Seg> (2 * n, Seg());
    lazy = vector<ll> (2 * n, 0LL);
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

    propagate(u);

    if (ql > qr) return Seg();
    if (ql == lfend[u] && qr == rgend[u]) return tree[u];
    return merge(query(ql, qr, 2 * u), query(ql, qr, 2 * u + 1));
  }

  void update (int ql, int qr, ll val, int u = 1) {
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    propagate(u);

    if (ql > qr) return;
    if (ql == lfend[u] && qr == rgend[u]) {
      lazy[u] += val;
      propagate(u);
      return;
    }

    update(ql, qr, val, 2 * u);
    update(ql, qr, val, 2 * u + 1);

    tree[u] = merge(tree[2 * u], tree[2 * u + 1]);
  }

  void act (int ql, int qr, bool on, int u = 1) {
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    propagate(u);

    if (ql > qr) return;
    if (ql == lfend[u] && qr == rgend[u]) {
      if (on) {
        tree[u] = Seg(1, 0, 0);
      } else {
        tree[u] = Seg(0, 0, 0);
      }
      return;
    }

    act(ql, qr, on, 2 * u);
    act(ql, qr, on, 2 * u + 1);

    tree[u] = merge(tree[2 * u], tree[2 * u + 1]);    
  }
};

const int MAX_A = 2e5 + 5;

int D;
bool active [MAX_A];
Segtree tree;

void activate (int x) {
  tree.update(max(0, x - D), x - 1, 1);
  ll add = tree.query(x + 1, min(MAX_A - 1, x + D)).cnt;
  tree.act(x, x, 1);
  tree.update(x, x, add);
  active[x] = true;
}

void deactivate (int x) {
  tree.update(max(0, x - D), x - 1, -1);
  tree.act(x, x, 0);
  active[x] = false;
}

ll solve () {
  auto seg = tree.query(1, MAX_A - 1);
  return (seg.sumsq - seg.sum) / 2;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int qc;
  cin >> qc >> D;

  tree = Segtree(MAX_A);

  for (int i = 0; i < qc; i++) {
    int x;
    cin >> x;

    if (active[x])
      deactivate(x);
    else
      activate(x);

    cout << solve() << '\n';
  }
}