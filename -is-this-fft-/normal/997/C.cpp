#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 998244353;

struct modint {
  ll val;

  modint () {
    val = 0;
  }

  modint (ll _val) {
    val = _val % MOD;
  }
};

modint operator+ (modint p, modint q) {
  return modint(p.val + q.val);
}

modint operator- (modint p) {
  return modint(MOD - p.val);
}

modint operator- (modint p, modint q) {
  return p + (-q);
}

modint operator* (modint p, modint q) {
  return modint(p.val * q.val);
}

modint exp (modint p, ll k) {
  if (k == 0) {
    return modint(1);
  } else if (k % 2 == 0) {
    modint half = exp(p, k / 2);
    return half * half;
  } else {
    return p * exp(p, k - 1);
  }
}

modint inv (modint p) {
  return exp(p, MOD - 2);
}

ostream& operator<< (ostream &out, const modint &p) {
  out << p.val;
  return out;
}

const int MAX_N = 1e6 + 5;

modint pow3 [MAX_N];
modint invpow3 [MAX_N];
modint fact [MAX_N];
modint invfact [MAX_N];
modint pow2 [MAX_N];
modint invpow2 [MAX_N];

modint choose (int n, int k) {
  return fact[n] * invfact[k] * invfact[n - k];
}

modint even (int n) {
  if (n % 2 == 0) {
    return modint(1);
  } else {
    return modint(MOD - 1);
  }
}

int main () {
  modint inv3 = inv(modint(3));
  modint inv2 = inv(modint(2));
  pow3[0] = modint(1);
  invpow3[0] = modint(1);
  pow2[0] = modint(1);
  invpow2[0] = modint(1);
  fact[0] = modint(1);
  invfact[0] = modint(1);
  for (int i = 1; i < MAX_N; i++) {
    pow3[i] = pow3[i - 1] * modint(3);
    invpow3[i] = invpow3[i - 1] * inv3;
    fact[i] = fact[i - 1] * modint(i);
    invfact[i] = invfact[i - 1] * inv(modint(i));
    pow2[i] = pow2[i - 1] * modint(2);
    invpow2[i] = invpow2[i - 1] * inv2;
  }
  
  ll N;
  cin >> N;

  modint wrwg (0);
  if (N >= 2) {
    modint cp3 = exp(modint(3), N * (N - 2));
    for (int i = 2; i <= N; i++) {
      wrwg = wrwg + choose(N, i) * (pow2[i] - 2) * exp(pow3[N] - 2, N - i);
      cp3 = cp3 * invpow3[N];
    }
    wrwg = wrwg * modint(2);
  }
  
  modint wrwgwb (0);
  if (N >= 3) {
    modint cp3 = exp(modint(3), N * (N - 3));
    for (int i = 3; i <= N; i++) {
      wrwgwb = wrwgwb + choose(N, i) * (pow3[i] - modint(3) * (pow2[i] - 2) - 3) *
        exp(pow3[N] - 3, N - i);
    }
    wrwgwb = wrwgwb * modint(2);
  }

  modint wrwgnb = wrwg - wrwgwb;

  modint wr (0);
  for (int i = 0; i <= N; i++) {
    wr = wr + choose(N, i) * even(i) * exp(modint(3), (N - i) * N)
      * exp(modint(1) - invpow3[N - i], N);
  }
  wr = exp(modint(3), N * N) - wr;

  modint wrngnb = wr - wrwgwb - wrwgnb - wrwgnb;

  cout << 3 * wrngnb + 3 * wrwgnb + wrwgwb << endl;
}