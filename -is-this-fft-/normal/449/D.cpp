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

const int MAX_LG = 20;
const int MAX_A = 1 << MAX_LG;

Modint tpow [MAX_A + 1];
int dp [MAX_A];
Modint sgn [2] = {Modint(1), Modint(MOD - 1)};

int main () {
  tpow[0] = Modint(1);
  for (int i = 1; i <= MAX_A; i++) {
    tpow[i] = tpow[i - 1] * Modint(2);
  }
  
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    dp[x]++;
  }

  for (int k = 0; k < MAX_LG; k++) {
    int E = 1 << k;
    for (int i = MAX_A - 1; i >= 0; i--) {
      if (!(i & E)) {
        dp[i] += dp[i + E];
      }
    }
  }

  Modint ans (0);
  for (int i = 0; i < MAX_A; i++) {
    ans += sgn[__builtin_popcount(i) % 2] * tpow[dp[i]];
  }
  cout << ans << endl;
}