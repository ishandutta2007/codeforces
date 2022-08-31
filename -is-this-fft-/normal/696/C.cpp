#include <iostream>

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

Modint exp (Modint a, ll k) {
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

int main () {
  ios::sync_with_stdio(false);

  int k;
  cin >> k;

  bool even = 0;

  Modint tpow (2);
  for (int i = 0; i < k; i++) {
    ll ai;
    cin >> ai;

    tpow = exp(tpow, ai);
    if (ai % 2 == 0) even = 1;
  }

  Modint inv2 = inv(Modint(2));
  Modint numer;
  if (even) {
    numer = Modint(1) - tpow * inv2 * inv2;
    numer *= inv(Modint(1) - Modint(4));
    numer *= Modint(2);
    numer += Modint(1);
  } else {
    numer = Modint(1) - tpow * inv2;
    numer *= inv(Modint(1) - Modint(4));
  }

  Modint denom = tpow * inv2;

  cout << numer << "/" << denom << endl;
}