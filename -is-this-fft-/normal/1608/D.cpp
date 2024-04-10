#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 998244353; // change if needed
// const int MOD = 1e9 + 7; 

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

const int MAX_N = 3e5 + 5;

Modint fact [MAX_N];
Modint ifact [MAX_N];

Modint choose (int n, int k) {
  if (n - k < 0 || k < 0) {
    return Modint(0);
  }
  
  return fact[n] * ifact[k] * ifact[n - k];
}

Modint ncexpr (int n, int k) {
  return choose(2 * n, n + k);
}

int main () {
  fact[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = fact[i - 1] * i;
  }

  for (int i = 0; i < MAX_N; i++) {
    ifact[i] = inv(fact[i]);
  }

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int cost = 0;
  int a = 0, b = 0, c = 0;
  bool awbbw = true, awb = true, abw = true;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    if (s == string("??")) {
      c++;
    } else if (s == string("W?")) {
      a++;
      abw = false;
    } else if (s == string("?W")) {
      a++;
      awb = false;
    } else if (s == string("B?")) {
      b++;
      awb = false;
    } else if (s == string("?B")) {
      b++;
      abw = false;
    } else if (s == string("WW")) {
      awbbw = false;
      awb = false;
      abw = false;
      cost++;
    } else if (s == string("BB")) {
      awbbw = false;
      awb = false;
      abw = false;
      cost--;
    } else if (s == string("BW")) {
      awb = false;
    } else if (s == string("WB")) {
      abw = false;
    }
  }

  Modint ans (0);
  if (awbbw) {
    // sub the # of ways to make everything WB or BW
    ans -= exp(Modint(2), c);

    // add the # of ways to make everything into WB
    if (awb) {
      ans += Modint(1);
    }

    // add the # of ways to make everything into BW
    if (abw) {
      ans += Modint(1);
    }
  }
  
  int mn = min(a, b);
  c += mn;
  a -= mn;
  b -= mn;

  for (int i = 0; i <= max(a, b); i++) {
    if (a != 0) {
      ans += choose(a, i) * ncexpr(c, -(cost + i));
    } else {
      ans += choose(b, i) * ncexpr(c, -(cost - i));
    }
  }
  
  cout << ans << endl;
}