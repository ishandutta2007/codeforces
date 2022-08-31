#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7; 

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
  vector<Modint> tree;
  vector<int> lfend;
  vector<int> rgend;

public:
  Segtree (int _n) {
    n = 1;
    while (n < _n) {
      n *= 2;
    }

    tree = vector<Modint> (2 * n, Modint(0));
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

  Modint query (int ql, int qr, int u = 1) {
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) return Modint(0);
    if (ql == lfend[u] && qr == rgend[u]) return tree[u];
    return query(ql, qr, 2 * u) + query(ql, qr, 2 * u + 1);
  }

  void set (int u, Modint val) {
    tree[n + u] = val;
    for (int v = (n + u) / 2; v != 0; v /= 2) {
      tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
  }
};

const int MAX_N = 2e5 + 5;

ll A [MAX_N];
ll B [MAX_N];
ll pref [MAX_N];

pair<int, int> qs [MAX_N];
vector<int> outq [MAX_N];

Modint initsum [MAX_N];
Modint initcnt [MAX_N];
Modint possum [MAX_N];
Modint poscnt [MAX_N];

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

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + B[i];
  }

  Segtree sums (n + 5), cnts (n + 5);
  for (int i = 1; i < n; i++) {
    sums.set(i, Modint(pref[i]) * Modint(A[i + 1] - A[i]));
    cnts.set(i, Modint(A[i + 1] - A[i]));
  }

  for (int i = 0; i < qc; i++) {
    cin >> qs[i].first >> qs[i].second;
    outq[qs[i].first - 1].push_back(i);

    initsum[i] = sums.query(qs[i].first, qs[i].second - 1);
    initcnt[i] = cnts.query(qs[i].first, qs[i].second - 1);
  }

  vector<pair<ll, int>> bypref;
  for (int i = 0; i < n; i++) {
    bypref.push_back(make_pair(pref[i], i));
  }

  sort(bypref.begin(), bypref.end());

  for (auto pr : bypref) {
    int pos = pr.second;

    for (int q : outq[pos]) {
      possum[q] = sums.query(qs[q].first, qs[q].second - 1);
      poscnt[q] = cnts.query(qs[q].first, qs[q].second - 1);
    }
    
    sums.set(pos, 0);
    cnts.set(pos, 0);
  }

  for (int i = 0; i < qc; i++) {
    Modint ans = possum[i] * 2 - initsum[i] -
      Modint(pref[qs[i].first - 1]) * (poscnt[i] * 2 - initcnt[i]);
    cout << ans << '\n';
  }
}