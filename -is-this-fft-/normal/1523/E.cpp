#include <iostream>

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

typedef long long ll;

const int MAX_N = 2e5 + 5;

Modint fact [MAX_N];
Modint ifact [MAX_N];

Modint choose (ll n, int k) {
  if (n < 0) return Modint(0);
  if (k < 0) return Modint(0);
  if (k > n) return Modint(0);
  return fact[n] * ifact[k] * ifact[n - k];
}

Modint prob [MAX_N];

void solve () {
  int n, K;
  cin >> n >> K;

  prob[0] = Modint(1);
  for (int i = 1; i <= n; i++) {
    // prob that the machine lasts at least this many turns
    prob[i] = choose((ll) n - (ll) (i - 1) * (ll) (K - 1), i) * inv(choose(n, i));
  }

  for (int i = 0; i < n; i++) {
    prob[i] -= prob[i + 1];
  }

  Modint ans (0);
  for (int i = 0; i <= n; i++) {
    ans += Modint(i + 1) * prob[i];
  }
  cout << ans << '\n';
}

int main () {
  fact[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = fact[i - 1] * Modint(i);
  }

  for (int i = 0; i < MAX_N; i++) {
    ifact[i] = inv(fact[i]);
  }
  
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}