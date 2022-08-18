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

Modint fact [MAX_N];
Modint invfact [MAX_N];

Modint choose (int n, int r) {
  return fact[n] * invfact[r] * invfact[n - r];
}

Modint Kpow [MAX_N];
Modint Km2pow [MAX_N];

int arr [MAX_N];

int main () {
  fact[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = fact[i - 1] * Modint(i);
  }

  for (int i = 0; i < MAX_N; i++) {
    invfact[i] = inv(fact[i]);
  }
  
  ios::sync_with_stdio(false);

  int n, K;
  cin >> n >> K;

  if (K == 1) {
    cout << 0 << endl;
    return 0;
  }

  Kpow[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    Kpow[i] = Kpow[i - 1] * Modint(K);
  }

  Km2pow[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    Km2pow[i] = Km2pow[i - 1] * Modint(K - 2);
  }

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int m = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] != arr[(i + 1) % n]) {
      m++;
    }
  }

  Modint ans (0);
  for (int i = 0; 2 * i <= m; i++) {
    ans += choose(m, i) * choose(m - i, i) * Km2pow[m - 2 * i];
  }
  ans *= Kpow[n - m];
  ans = Kpow[n] - ans;
  ans *= inv(Modint(2));

  cout << ans << endl;
}