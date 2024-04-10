#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct Seq {
  ll l, r;

  Seq (ll _l = 0, ll _r = 0) : l(_l), r(_r) {}
};

struct SeqCmp {
  Seq operator() (Seq p, Seq q) {
    return Seq(p.l + max(0LL, q.l - p.r), q.r + max(0LL, p.r - q.l));
  }
};

struct Min {
  ll operator() (ll p, ll q) {
    return min(p, q);
  }
};

template<typename T, typename TComp>
class Segtree {
  int n;
  TComp comp;
  T id;
  vector<T> tree;
  vector<int> lfend;
  vector<int> rgend;

  void update (int pos) {
    if (pos == 0) return;
    tree[pos] = comp(tree[2 * pos], tree[2 * pos + 1]);
    update(pos / 2);
  }
  
public:
  Segtree (int _n, T _id) {
    n = 1;
    comp = TComp();
    id = _id;
    while (n < _n) {
      n *= 2;
    }

    tree = vector<T> (2 * n, id);
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

  void set (int pos, T val) {
    tree[n + pos] = val;
    update((n + pos) / 2);
  }

  T query (int ql, int qr, int u = 1) {
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) return id;
    if (ql == lfend[u] && qr == rgend[u]) return tree[u];
    return comp(query(ql, qr, 2 * u), query(ql, qr, 2 * u + 1));
  }
};

const ll INF = 1e18 + 200;
const int MAX_N = 1e5 + 5;

ll A [MAX_N];
ll B [MAX_N];
ll pref [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, qc;
  cin >> n >> qc;

  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> B[i];
  }

  Segtree<ll, Min> prefs (n + 5, INF);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + B[i] - A[i];
    prefs.set(i, pref[i]);
  }

  Segtree<Seq, SeqCmp> seqs (n + 5, Seq());
  for (int i = 1; i <= n; i++) {
    if (A[i] > B[i]) {
      seqs.set(i, Seq(0, A[i] - B[i]));
    }

    if (B[i] > A[i]) {
      seqs.set(i, Seq(B[i] - A[i], 0));
    }
  }

  for (int i = 0; i < qc; i++) {
    int l, r;
    cin >> l >> r;

    if (pref[r] - pref[l - 1] != 0) {
      cout << -1 << '\n';
    } else if (prefs.query(l, r) < pref[l - 1]) {
      cout << -1 << '\n';
    } else {
      cout << seqs.query(l, r).l << '\n';
    }
  }
}