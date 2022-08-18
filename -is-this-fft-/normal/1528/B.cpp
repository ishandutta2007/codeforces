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

int divc [MAX_N];
Modint dp [MAX_N];

int main () {
  for (int i = 1; i < MAX_N; i++) {
    for (int j = 2 * i; j < MAX_N; j += i) {
      divc[j]++;
    }
  }
  
  int n;
  cin >> n;

  dp[0] = Modint(1);
  dp[1] = Modint(1);
  Modint csum = Modint(2);
  for (int i = 2; i <= n; i++) {    
    dp[i] = csum + divc[i];
    csum += dp[i];
  }

  cout << dp[n] << endl;
}