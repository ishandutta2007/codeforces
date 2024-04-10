#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7; // change if needed

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

const int MAX_N = 2e5 + 5;

class Fenwick {
  vector<Modint> tree;

public:
  Fenwick (int _n = 0) : tree(vector<Modint> (_n, Modint(1))) {}

  void add (int idx, Modint val) {
    for (int i = idx; i < (int) tree.size(); i += i & -i) {
      tree[i] *= val;
    }
  }

  Modint get (int idx) {
    Modint prod (1);
    for (int i = idx; i > 0; i -= i & -i) {
      prod *= tree[i];
    }
    return prod;
  }

  Modint get (int l, int r) {
    return get(r) * inv(get(l - 1));
  }
};

Fenwick fenwick;
int arr [MAX_N];
pair<int, int> qs [MAX_N];
vector<int> qs_at [MAX_N];
Modint ans [MAX_N];

const int MAX_P = 1e6 + 5;
int cur [MAX_P];
int factor [MAX_P];
Modint ecoef [MAX_P];
Modint iecoef [MAX_P];

int main () {
  for (int i = 2; i < MAX_P; i++) {
    if (factor[i] == 0) {
      ecoef[i] = Modint(1) - inv(Modint(i));
      iecoef[i] = inv(ecoef[i]);
      for (int j = i; j < MAX_P; j += i) {
        factor[j] = i;
      }
    }
  }
  
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  fenwick = Fenwick(MAX_N);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    fenwick.add(i, arr[i]);
  }

  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    int l, r;
    cin >> l >> r;
    qs[i] = make_pair(l, r);
    qs_at[r].push_back(i);
  }

  for (int r = 1; r <= n; r++) {
    int x = arr[r];
    while (x != 1) {
      int p = factor[x];
      while (x % p == 0) {
        x /= p;
      }
      if (cur[p] != 0) {
        fenwick.add(cur[p], iecoef[p]);
      }
      cur[p] = r;
      fenwick.add(cur[p], ecoef[p]);
    }

    for (int q : qs_at[r]) {
      int l = qs[q].first;
      ans[q] = fenwick.get(l, r);
    }
  }

  for (int i = 0; i < qc; i++) {
    cout << ans[i] << '\n';
  }
}