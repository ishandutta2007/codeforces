#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;
const int MOD = 998244353;

int inv[N];
int h[N], g[N];
// key idea: assume there is a weight function g such that if f(a_1, ..., a_n) =
// sum of g(a_i), then expectation of f decreases by 1 for any input except in the
// ending configuration. Assume each term contributes -1/n to the expected
// change, work out the equations. h is the first order differece of g and we
// can get an equation with h(x) and h(x-1).

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  inv[1] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
  }

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int m = accumulate(a.begin(), a.end(), 0);

  int z = inv[n] * (1LL * m * (n-1) % MOD) % MOD;

  for (int i = 0; i < m; i++) {
    int d = inv[m-i];
    h[i+1] = (-1LL * z * d + (1LL* (n-1) * i % MOD) * (1LL * d * h[i] % MOD)) % MOD;
    g[i+1] = (g[i] + h[i+1]) % MOD;
  }
  int ans = -g[m];
  for (int val: a) {
    ans = (ans + g[val]) % MOD;
  }
  cout << (ans+MOD)%MOD << endl;
}