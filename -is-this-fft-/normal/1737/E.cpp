#include <iostream>
#include <vector>

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

const int MAX_N = 1e6 + 6;

Modint tpow [MAX_N];

class Fenwick {
  vector<Modint> tree;

public:
  Fenwick (int _n) : tree(_n, Modint(0)) {}

  void add (int idx, Modint val) {
    for (int i = idx; i < (int) tree.size(); i += i & -i) {
      tree[i] += val;
    }
  }

  Modint get (int idx) {
    idx = min(idx, (int) tree.size() - 1);
    Modint ans = 0;
    for (int i = idx; i > 0; i -= i & -i) {
      ans += tree[i];
    }
    return ans;
  }
};

void solve () { 
  int n;
  cin >> n;

  if (n == 1) {
    cout << 1 << '\n';
    return;
  }
  
  vector<Modint> ans (n + 1);
  Fenwick seqc (n + 1);
  for (int i = n; i > 1; i--) {
    Modint seqs;
    if (i == n) {
      seqs = 1;
    } else {
      seqs = seqc.get(2 * i - 1);
    }
    seqc.add(i, seqs);

    Modint ways;
    if (i == n) {
      ways = 1;
    } else {
      ways = seqs * tpow[n - i - 1]; // not counting itself or the last one
    }

    int len = (i + 1) / 2;
    if (i == n) {
      len--;
    }

    ans[i] = ways * tpow[len];
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }
}

int main () {
  Modint i2 = inv(2);
  tpow[0] = 1;
  for (int i = 1; i < MAX_N; i++) {
    tpow[i] = tpow[i - 1] * i2;
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}