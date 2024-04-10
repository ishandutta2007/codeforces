// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 10000005;
const int mod = 998244353;
const int inv2 = (mod + 1) / 2;

inline int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}

int pw[N], ppw[N], ippw[N];

void init(int n) {
  pw[0] = 1; rep(i, 1, n) pw[i] = 2 * pw[i - 1] % mod;
  ppw[0] = 1;
  rep(i, 1, n) ppw[i] = 1ll * ppw[i - 1] * (mod + 1 - pw[i]) % mod;
  ippw[n] = qpow(ppw[n]);
  per(i, n, 1) ippw[i - 1] = 1ll * ippw[i] * (mod + 1 - pw[i]) % mod;
//  rep(i, 1, 20) {
//    int base = 1, res = 1;
//    rep(j, 1, i) {
//      base = 2 * base % mod;
//      res = 1ll * res * qpow(mod + 1 - base) % mod;
//    } 
//    assert(ippw[i] == res);
//  }
}

int n, k, x;

/* x != 0
\sum_{i<k} \binom{n}{i}_q * \prod_{j<i} (2^k-2^{j+1})
*/

void solve() {
  n = read(), k = read(), x = read();
  if (x == 0) {
    int ans = 1;
    for (int i = 0; i < n && i <= k; i++) {
      ans = 1ll * ans * (pw[k] + mod - pw[i]) % mod;
    }
    print(ans, '\n');
  } else {
    int ans = 1, coef1 = 1, coef2 = 1, base = qpow(2, n);
    for (int i = 1; i < k; i++) {
      coef1 = 1ll * coef1 * (mod + 1 - base) % mod;
      base = 1ll * inv2 * base % mod;
      coef2 = 1ll * coef2 * (pw[k] + mod - pw[i]) % mod;
      ans = (ans + 1ll * coef1 * ippw[i] % mod * coef2) % mod;
    }
    print(ans, '\n');
  }
} 

int main() {
  init(N - 5);
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}