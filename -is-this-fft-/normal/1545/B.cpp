#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 998244353; // change if needed

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

Modint fact [MAX_N];
Modint ifact [MAX_N];

void solve () {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int zc = 0, fpc = 0;
  vector<int> stk;
  for (char c : s) {
    if (!stk.empty() && stk.back() == '1' && c == '1') {
      stk.pop_back();
      fpc++;
    } else {
      stk.push_back(c);
    }

    if (c == '0') {
      zc++;
    }
  }

  cout << fact[zc + fpc] * ifact[zc] * ifact[fpc] << '\n';
}

int main () {
  fact[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = Modint(i) * fact[i - 1];
  }

  for (int i = 0; i < MAX_N; i++) {
    ifact[i] = inv(fact[i]);
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}