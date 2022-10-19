#include <bits/stdc++.h>
using namespace std;

// sum from l = 1 to k of S(k, l) * n!/(n-l)! * (n+1)^(n-l)

const int MOD = 998244353;
const int N = 1e5+5;
int fact[N];
int invfact[N];

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

int expmod(long long a, long long b, int m) {
  int ans = 1;
  a %= m;
  if (a == 0) return 0;
  while (b) {
    if (b&1) ans = 1LL*ans*a % m;
    b >>= 1;
    a = 1LL*a*a % m;
  }
  return ans;
}

const int root = 31; // primitive (2^k)th root
const int root_1 = inversemod(root, MOD);
const int root_pw = 1 << 23;

// source: cp-algorithms
void fft(vector<int> & a, bool invert) {
  int n = a.size();

  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;

    if (i < j) swap(a[i], a[j]);
  }

  for (int len = 2; len <= n; len <<= 1) {
    int wlen = invert ? root_1 : root;
    for (int i = len; i < root_pw; i <<= 1) wlen = (int)(1LL * wlen * wlen % MOD);

    for (int i = 0; i < n; i += len) {
      int w = 1;
      for (int j = 0; j < len / 2; j++) {
        int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % MOD);
        a[i+j] = u + v < MOD ? u + v : u + v - MOD;
        a[i+j+len/2] = u - v >= 0 ? u - v : u - v + MOD;
        w = (int)(1LL * w * wlen % MOD);
      }
    }
  }

  if (invert) {
    int n_1 = inversemod(n, MOD);
    for (int & x : a) x = (int)(1LL * x * n_1 % MOD);
  }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
  vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < a.size() + b.size()) n <<= 1;
  fa.resize(n);
  fb.resize(n);

  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++) fa[i] = 1LL * fa[i] * fb[i] % MOD;
  fft(fa, true);
  fa.resize(a.size()+b.size()-1);
  return fa;
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

  int n, k;
  cin >> n >> k;
  vector<int> a(k+1);
  vector<int> b(k+1);
  for (int i = 0; i <= k; i++) {
    a[i] = i&1 ? MOD-invfact[i] : invfact[i];
    b[i] = 1LL * invfact[i] * expmod(i, k, MOD) % MOD;
  }

  vector<int> S = multiply(a, b);
  int ans = 0;
  int p = ((n+1)%MOD ? inversemod(n+1, MOD) : 0);
  int u = expmod(n+1, n, MOD);
  for (int l = 1; l <= k; l++) {
    u = 1LL * u * p % MOD;
    u = 1LL * (n+1-l) * u % MOD;
    ans += 1LL * S[l] * u % MOD;
    ans %= MOD;
  }
  cout << ans << '\n';
}