#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 998244353;

struct Modint {
  ll val;
  
  Modint (ll _val = 0)
    : val(_val % MOD) {}

  Modint operator+ (Modint other) const {
    return Modint(val + other.val);
  }

  void operator+= (Modint other) {
    val += other.val;
    val %= MOD;
  }

  Modint operator- () const {
    return Modint(MOD - val);
  }

  Modint operator- (Modint other) const {
    return Modint(val + MOD - other.val);
  }

  void operator-= (Modint other) {
    val += MOD - other.val;
    val %= MOD;
  }

  Modint operator* (Modint other) const {
    return Modint(val * other.val);
  }

  void operator*= (Modint other) {
    val *= other.val;
    val %= MOD;
  }

  bool operator== (Modint other) const {
    return val == other.val;
  }

  bool operator!= (Modint other) const {
    return val != other.val;
  }
};

Modint exp (Modint a, int k) {
  if (k == 0) {
    return Modint(1);
  } else if (k % 2 == 0) {
    Modint half = exp(a, k / 2);
    return half * half;
  } else {
    return a * exp(a, k - 1);
  }
}

Modint inv (Modint a) {
  return exp(a, MOD - 2);
}

ostream& operator<< (ostream& out, Modint p) {
  out << p.val;
  return out;
}

class Segtree {
  int n;
  vector<int> lfend;
  vector<int> rgend;
  vector<Modint> tree;
  vector<Modint> lazy;

  Modint eff (int u) {
    return tree[u] * lazy[u];
  }

  void propagate (int u) {
    if (lazy[u] == Modint(1)) {
      return;
    }

    tree[u] *= lazy[u];
    if (u < n) {
      lazy[2 * u] *= lazy[u];
      lazy[2 * u + 1] *= lazy[u];
    }
    lazy[u] = Modint(1);
  }
  
public:
  Segtree (int _n) {
    n = 1;
    while (n < _n) {
      n *= 2;
    }

    tree = vector<Modint> (2 * n, 0);
    lazy = vector<Modint> (2 * n, 1);
    lfend = rgend = vector<int> (2 * n);
    
    for (int i = n; i < 2 * n; i++) {
      lfend[i] = i - n;
      rgend[i] = i - n;
    }

    for (int i = n - 1; i > 0; i--) {
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }

  void update (int u, int ql, int qr, Modint val) {
    propagate(u);

    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) return;
    if (ql == lfend[u] && qr == rgend[u]) {
      lazy[u] *= val;
      return;
    }

    update(2 * u, ql, qr, val);
    update(2 * u + 1, ql, qr, val);
    tree[u] = eff(2 * u) + eff(2 * u + 1);
  }

  void set (int u, int pos, Modint val) {
    propagate(u);

    if (lfend[u] == pos && rgend[u] == pos) {
      tree[u] = val;
      return;
    }

    if (pos <= rgend[2 * u]) {
      set(2 * u, pos, val);
    } else {
      set(2 * u + 1, pos, val);
    }

    tree[u] = eff(2 * u) + eff(2 * u + 1);
  }

  Modint get () {
    return eff(1);
  }
};

#include <bits/extc++.h>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>,
  rb_tree_tag, tree_order_statistics_node_update>;

// cur.order_of_key(2)
// the number of elements in the set less than 2
// *cur.find_by_order(1)
// the 1-st smallest number in the set(0-based)


const int MAX_N = 2e5 + 5;
const Modint BASE = Modint(6942069);
const Modint IBASE = inv(Modint(BASE));
Modint bpow [MAX_N];

class Hasher {
  int n;
  Segtree hshtree;
  ordered_set<int> positions;

public:
  Hasher (int _n) : n(_n), hshtree(_n) {
  }

  void insert (int pos, int val) {
    int pw = positions.order_of_key(pos);
    hshtree.update(1, pos + 1, n - 1, BASE);
    positions.insert(pos);
    hshtree.set(1, pos, Modint(val) * bpow[pw]);
  }

  void erase (int pos) {
    hshtree.update(1, pos + 1, n - 1, IBASE);
    positions.erase(pos);
    hshtree.set(1, pos, Modint(0));
  }

  Modint get () {
    return hshtree.get();
  }
};

int A [MAX_N], B [MAX_N];
int iB [MAX_N];

int main () {
  bpow[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    bpow[i] = bpow[i - 1] * BASE;
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> B[i];
    iB[B[i]] = i;
  }

  Modint ahsh (0), add (0);
  for (int i = 0; i < n; i++) {
    ahsh += Modint(A[i]) * bpow[i];
    add += bpow[i];
  }

  Hasher H (m);
  for (int i = 1; i <= n; i++) {
    H.insert(iB[i], i);
  }

  int ans = 0;
  if (ahsh == H.get()) {
    ans++;
  }

  for (int i = n + 1; i <= m; i++) {
    H.insert(iB[i], i);
    H.erase(iB[i - n]);
    ahsh += add;

    if (ahsh == H.get()) {
      ans++;
    }
  }

  cout << ans << endl;
}