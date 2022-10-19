#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 250007;

vector<ll> fact(maxn);
vector<ll> invfact(maxn); 

ll inversemod(ll p, ll q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  ll k = q/p;
  ll b = inversemod(q-k*p, p);
  ll a = (1-b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

const int MOD = 998244353;
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
  return fa;
}

ll binommod(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * (invfact[k]*invfact[n-k] % MOD) % MOD;
}

ll expmod(ll a, ll b, int m) {
  int res = 1;
  a = a % m; 
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) {
      res = (res*a) % m;
    }
    b = b>>1;
    a = (a*a) % m;
  }
  return res;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = i*fact[i-1] % MOD;
  }
  invfact[maxn-1] = expmod(fact[maxn-1], MOD-2, MOD);
  for (int i = maxn-1; i >= 1; i--) {
    invfact[i-1] = i*invfact[i] % MOD;
  }

  int n;
  cin >> n;
  vector<int> children(n, -1);
  children[0] = 0;
  for (int i = 0; i < n-1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    children[x]++;
    children[y]++;
  }
  vector<int> counts(n);
  for (int i: children) counts[i]++;
  vector<int> poly = {1};
  int deg = 0;
  for (int c = n-1; c >= 1; c--) {
    if (counts[c]) {
      // multiply by (1+cx)^k
      int k = counts[c];
      vector<int> q(k+1);
      ll u = 1;
      for (int i = 0; i <= k; i++) {
        q[i] = binommod(k, i) * u % MOD;
        u = c * u % MOD;
      }
      poly = multiply(poly, q);
      deg += k;
      poly.resize(deg+1);
    }
  }
  ll ans = 0;
  poly.resize(n);
  for (int i = 0; i < n; i++) {
    ans += fact[n-i] * (i&1 ? -1 : 1) * poly[i] % MOD;
    ans %= MOD;
  }
  cout << (ans+MOD)%MOD << endl;
}