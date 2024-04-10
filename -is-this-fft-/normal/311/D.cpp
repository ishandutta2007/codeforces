#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef long long ll;

const int MOD = 95542721; 

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

Modint cb (Modint x) {
  return x * x * x;
}

const int ORBIT = 48;

typedef deque<Modint> Seg;

void apply (int upd, Seg &seg) {
  upd %= ORBIT;
  if (upd == 0) {
    return;
  }

  for (int i = 0; i < upd; i++) {
    auto f = seg.front();
    seg.pop_front();
    seg.push_back(f);
  }
}

Seg gen (Modint base) {
  Seg ans;
  for (int i = 0; i < ORBIT; i++) {
    ans.push_back(base);
    base = cb(base);
  }
  return ans;
}

Seg merge (const Seg &p, const Seg &q) {
  Seg ans (ORBIT);
  for (int i = 0; i < ORBIT; i++) {
    ans[i] = p[i] + q[i];
  }
  return ans;
}

class Segtree {
  int n;
  vector<Seg> seg;
  vector<int> upd;
  vector<int> lfend;
  vector<int> rgend;

  void propagate (int u) {
    if (upd[u] == 0) {
      return;
    }

    apply(upd[u], seg[u]);
    if (u < n) {
      upd[2 * u] += upd[u];
      upd[2 * u + 1] += upd[u];
    }
    upd[u] = 0;
  }
  
public:
  Segtree (vector<Modint> _init) {
    n = 1;
    while (n < (int) _init.size()) {
      n *= 2;
    }

    seg = vector<Seg> (2 * n);
    upd = vector<int> (2 * n, 0);
    lfend = vector<int> (2 * n);
    rgend = vector<int> (2 * n);

    for (int i = n; i < 2 * n; i++) {
      if (i - n < (int) _init.size()) {
        seg[i] = gen(_init[i - n]);
      } else {
        seg[i] = gen(Modint(0));
      }

      lfend[i] = i - n;
      rgend[i] = i - n;
    }

    for (int i = n - 1; i > 0; i--) {
      seg[i] = merge(seg[2 * i], seg[2 * i + 1]);
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }

  Modint query (int ql, int qr, int u = 1) {
    propagate(u);
    
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) {
      return Modint(0);
    }

    if (ql == lfend[u] && qr == rgend[u]) {
      return seg[u][0];
    }

    return query(ql, qr, 2 * u) + query(ql, qr, 2 * u + 1);
  }

  void update (int ql, int qr, int u = 1) {
    propagate(u);
    
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) {
      return;
    }

    if (ql == lfend[u] && qr == rgend[u]) {
      upd[u]++;
      propagate(u);
      return;
    }

    update(ql, qr, 2 * u);
    update(ql, qr, 2 * u + 1);
    seg[u] = merge(seg[2 * u], seg[2 * u + 1]);
  }
};

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<Modint> init;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    init.push_back(Modint(x));
  }

  int qc;
  cin >> qc;
  
  Segtree tree (init);
  for (int i = 0; i < qc; i++) {
    int t, l, r;
    cin >> t >> l >> r;
    l--; r--;
    
    if (t == 1) {
      cout << tree.query(l, r) << '\n';
    } else {
      tree.update(l, r);
    }
  }
}