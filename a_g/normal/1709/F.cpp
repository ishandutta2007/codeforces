#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int b = inversemod(q%p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int add(int x, int y) {
  x += y;
  return (x >= MOD ? x-MOD : x);
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

vector<int> op(vector<int>& poly, int k) {
  // given gen func, add c_{empty}
  int m = poly.size();
  vector<int> sums(m+1);
  for (int i = 0; i < m; i++) {
    sums[i+1] = add(sums[i], poly[i]);
  }
  vector<int> ans(m);
  for (int i = 0; i < m; i++) {
    // c_{empty} = i -> poly[i]+poly[i+1]+...+poly[m-1]
    // c_{empty} = i+1, ..., k -> (k-i)*poly[i]
    ans[i] = (1LL*(k-i)*poly[i]+sums[m]-sums[i]) % MOD;
    if (ans[i] < 0) ans[i] += MOD;
  }
  ans.resize(min(m, k+1));
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k, f;
  cin >> n >> k >> f;

  vector<int> poly(k+1, 0);
  poly[k] = 1;
  while (n--) {
    poly = op(poly, k);
    poly = multiply(poly, poly);
  }
  cout << (f < (int)poly.size() ? poly[f] : 0) << '\n';
}