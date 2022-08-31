#include <iostream>

using namespace std;

typedef long long ll;

int MOD = 1;

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

const int MAX_N = 4e6 + 5;

Modint suff [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n >> MOD;

  suff[n] = Modint(1);
  for (int i = n - 1; i >= 1; i--) {
    Modint cur = suff[i + 1];
    for (int k = 2; i * k <= n; k++) {
      int L = i * k;
      int R = min(n + 1, (i + 1) * k);
      cur += suff[L] - suff[R];
    }
    suff[i] = suff[i + 1] + cur;
  }

  cout << suff[1] - suff[2] << endl;
}