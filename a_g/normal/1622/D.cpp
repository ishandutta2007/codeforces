#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
const int N = 1e4+5;
int fact[N];
int invfact[N];
int inv[N];

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int k = q/p;
  int b = inversemod(q-k*p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int binommod(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * (1LL*invfact[k]*invfact[n-k] % MOD) % MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL*i*fact[i-1] % MOD;
  }
  invfact[N-1] = inversemod(fact[N-1], MOD);
  for (int i = N-1; i >= 1; i--) {
    invfact[i-1] = 1LL*i*invfact[i] % MOD;
  }

  inv[1] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
  }

  int n, k;
  string s;
  cin >> n >> k >> s;
  if (count(s.begin(), s.end(), '1') < k) {
    cout << 1 << endl;
    return 0;
  }
  vector<int> b;
  int curr = 0;
  for (char c: s) {
    if (c == '0') curr++;
    else {
      b.push_back(curr);
      curr = 0;
    }
  }
  b.push_back(curr);

  int ans = 1;
  for (int m = 1; m <= k; m++) {
    int l = accumulate(b.begin(), b.begin()+m+1, 0);
    for (int i = 0; i < (int)b.size() - m; i++) {
      for (int u: {
          binommod(l+m, m),
          -binommod(l+m-b[i]-1, m-1),
          -binommod(l+m-b[i+m]-1, m-1),
          (m == 1 ? 1 : binommod(l+m-b[i]-b[i+m]-2, m-2)),
          }) {
        ans = (ans + u) % MOD;
      }
      if (i < (int)b.size()-m-1) {
        l -= b[i];
        l += b[i+m+1];
      }
    }
  }
  cout << (ans+MOD)%MOD << endl;
}