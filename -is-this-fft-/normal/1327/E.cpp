#include <iostream>

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

Modint tpow [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  tpow[0] = Modint(1);
  for (int i = 1; i <= MAX_N; i++) {
    tpow[i] = Modint(10) * tpow[i - 1];
  }
  
  int n;
  cin >> n;

  for (int i = 1; i <= n - 1; i++) {
    Modint ans (0);
    // middles
    if (i <= n - 2)
      ans += Modint(n - i - 1) * Modint(10) * Modint(9)
	* Modint(9) * tpow[n - i - 2];
    // left + right end
    ans += Modint(2) * Modint(10) * Modint(9) * tpow[n - i - 1];
    cout << ans << " ";
  }
  cout << 10 << endl;
}