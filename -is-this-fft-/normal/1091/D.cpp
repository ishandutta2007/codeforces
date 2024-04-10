#include <iostream>
#include <vector>

using namespace std;

typedef long long llong;
const int MOD = 998244353;
struct modint {
  llong val;

  modint () {
    val = 0;
  }

  modint (llong _val) {
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

modint operator^ (modint p, int q) {
  modint pows [30];

  pows[0] = p;
  for (int i = 1; i < 30; i++) {
    pows[i] = pows[i - 1] * pows[i - 1];
  }

  modint ans (1);
  for (int i = 0; i < 30; i++) {
    if (q & 1 << i) {
      ans = ans * pows[i];
    }
  }

  return ans;
}

modint operator/ (modint p, modint q) {
  return p * (q ^ (MOD - 2));
}

const int maxn = 1000005;
modint fact [maxn];

int main () {
  fact[0] = modint(1);
  for (int i = 1; i < maxn; i++) {
    fact[i] = fact[i - 1] * modint(i);
  }

  int n;
  cin >> n;

  modint ans = fact[n];
  modint addend = modint(1);
  for (int i = 0; i < n; i++) {
    addend = addend * (n - i);
    ans = ans + fact[n] - addend;
  }
  cout << ans.val << endl;
}