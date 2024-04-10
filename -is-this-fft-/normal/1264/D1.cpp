#include <iostream>

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

const int MAX_N = 1e6 + 5;

Modint fact [MAX_N];
Modint ifact [MAX_N];

Modint choose (int n, int k) {
  return fact[n] * ifact[k] * ifact[n - k];
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

  string s;
  cin >> s;
  
  int ls = 0, rf = 0, lq = 0, rq = 0;
  for (char c : s) {
    if (c == ')') {
      rf++;
    } else if (c == '?') {
      rq++;
    }
  }

  int n = s.size();
  Modint ans (0);
  for (int i = 0; i <= n; i++) {
    for (int k = max(ls, rf); k <= min(ls + lq, rf + rq); k++) {
      ans += choose(lq, k - ls) * choose(rq, k - rf) * k;
    }

    if (i == n) {
      break;
    }

    if (s[i] == '(') {
      ls++;
    } else if (s[i] == ')') {
      rf--;
    } else {
      lq++;
      rq--;
    }
  }

  cout << ans << '\n';
}