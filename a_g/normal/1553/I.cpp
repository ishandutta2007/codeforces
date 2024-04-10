#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 1e5+2;

int fact[N], invfact[N];

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int b = inversemod(q%p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
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

void vector_add(vector<int>& a, vector<int>& b) {
  if (a.size() < b.size()) a.resize(b.size());
  for (int i = 0; i < (int)b.size(); i++) {
    a[i] += b[i];
    if (a[i] >= MOD) a[i] -= MOD;
  }
}

bool steps[N];
int m = 0;

// left side = 0 bit
// right side = 1 bit
array<vector<int>, 4> solve(int l, int r) {
  array<vector<int>, 4> ans;
  for (int i = 0; i < 4; i++) ans[i].resize(1);
  if (l == r) {
    ans[0][0] = 1-steps[l];
    ans[3][0] = 2*steps[l];
    return ans;
  }
  int m = (l+r)/2;
  
  array<vector<int>, 4> left = solve(l, m);
  array<vector<int>, 4> right = solve(m+1, r);
  for (int maskl = 0; maskl < 4; maskl++) {
    if (left[maskl].size() == 1 && left[maskl][0] == 0) continue;
    for (int maskr = 0; maskr < 4; maskr++) {
      if (right[maskr].size() == 1 && right[maskr][0] == 0) continue;
      // case 1: don't connect the endpoints
      int newmask = (maskl&1)|(maskr&2);
      vector<int> term = multiply(left[maskl], right[maskr]);
      vector_add(ans[newmask], term);

      // case 2: connect the endpoints
      newmask = 0;
      if ((maskl&1) == 1 || l == m) newmask |= 1;
      if ((maskr&2) == 2 || r == m+1) newmask |= 2;
      term.insert(term.begin(), 0);
      if ((maskl&2) == 0 && (maskr&1) == 0) {
        for (int& x: term) {
          x *= 2;
          if (x >= MOD) x -= MOD;
        }
      }
      if ((maskl&2) == 2 && (maskr&1) == 1) {
        for (int& x: term) {
          x = 1LL*x*(MOD+1)/2 % MOD;
        }
      }
      vector_add(ans[newmask], term);
    }
  }
  return ans;
};

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

  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  bool ok = 1;
  for (int i = 0; i < n;) {
    if (i+a[i] > n) {
      ok = 0;
      break;
    }
    for (int j = i; j < i+a[i]; j++) {
      if (a[j] != a[i]) {
        ok = 0;
      }
    }
    if (!ok) break;
    steps[m++] = a[i] > 1;
    i += a[i];
  }
  if (!ok) {
    cout << "0\n";
    return 0;
  }
  n = m;

  array<vector<int>, 4> dp = solve(0, m-1);
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    for (int k = 0; k < (int)dp[i].size(); k++) {
      ans += 1LL*(k&1 ? -1 : 1)*fact[n-k]*dp[i][k] % MOD;
      if (ans >= MOD) ans -= MOD;
      if (ans < 0) ans += MOD;
    }
  }
  cout << ans << '\n';
}