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

class Fenwick {
  int n;
  vector<Modint> tree;

public:
  Fenwick (int _n) : n(_n), tree(_n, Modint(0)) {}

  void add (int pos, Modint val) {
    for (int i = pos; i < n; i += i & -i) {
      tree[i] += val;
    }
  }

  Modint get (int pos) {
    Modint ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
      ans += tree[i];
    }
    return ans;
  }

  Modint at (int pos) {
    return get(pos) - get(pos - 1);
  }

  void set (int pos, Modint val) {
    auto cur = at(pos);
    add(pos, val - cur);
  }
};

const int MAX_N = 1e5 + 5;
const int MAX_A = 1e6 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  Fenwick fen (MAX_A + 5);
  for (int i = n - 1; i >= 0; i--) {
    auto cur = Modint(arr[i]) * (Modint(1) + fen.get(MAX_A - arr[i]));
    fen.set(MAX_A - arr[i], cur);
  }

  cout << fen.get(MAX_A + 2) << '\n';
}