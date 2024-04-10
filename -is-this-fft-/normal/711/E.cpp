#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 1e6 + 3;

struct modint {
  ll val;

  modint () {
    val = 0;
  }

  modint (ll _val) {
    val = _val;
  }
};

modint operator+ (modint p, modint q) {
  return modint((p.val + q.val) % MOD);
}

modint operator- (modint p, modint q) {
  return modint((p.val - q.val + MOD) % MOD);
}

modint operator- (modint p) {
  return modint(0) - p;
}

modint operator* (modint p, modint q) {
  return modint((p.val * q.val) % MOD);
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

const int SMOD = MOD - 1;

int main () {
  ll N, K;
  cin >> N >> K;

  if (N <= 60) {
    if ((1LL << N) < K) {
      cout << 1 << " " << 1 << endl;
      return 0;
    }
  }

  modint mt = exp(modint(2), N);
  mt = exp(mt, K);

  // count the powers in the denominator
  int denpow = ((N % SMOD) * ((K - 1) % SMOD)) % SMOD;
  for (int i = 1; i < 60; i++) {
    denpow += SMOD - ((K - 1) / (1LL << i)) % SMOD;
    denpow %= SMOD;
  }

  modint numer (1);
  if (K >= MOD) {
    numer = 0;
  } else {
    modint tpn = exp(modint(2), N);
    for (int i = 1; i < K; i++) {
      numer = numer * (tpn - modint(i)) * inv(i & -i);
    }
  }

  modint denom = exp(modint(2), denpow);

  cout << (denom - numer).val << " " << denom.val << endl;
}