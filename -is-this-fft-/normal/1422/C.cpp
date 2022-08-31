#include <iostream>
#include <algorithm>

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

ll pairc (ll n) {
  return (n * (n + 1)) / 2;
}

int main () {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());

  Modint ans (0);
  Modint pow (1);
  Modint ser (0);
  for (int i = 0; i < (int) s.size(); i++) {
    int cur = s[i] - '0';
    ans += Modint(cur) * ser;
    int rem = (int) s.size() - i - 1;
    ans += Modint(cur) * Modint(pairc(rem)) * pow;
    
    ser += Modint(i + 1) * pow;
    pow *= Modint(10);
  }

  cout << ans << endl;
}