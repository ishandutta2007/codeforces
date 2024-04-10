// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("popcnt")
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
ll read() {
  ll x = 0, f = 0; char ch = getchar();
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

const int mod = 998244353;
const int inv2 = (mod + 1) / 2;

inline void add(int &x, int y) {
  x += y; if (x >= mod) x -= mod;
}

int C[54][54];
int n, m, k;

ll d[53], a[53]; int len;
void ins(ll x) {
  for (int i = m - 1; i >= 0; i--) {
    if (x >> i & 1) {
      if (!d[i]) { d[i] = x, k++; return ; }
      x ^= d[i];
    }
  }
}
int cnt[54], ans[54];
void dfs(int u, ll now) {
  if (u == len) {
    cnt[__builtin_popcountll(now)]++;
    return ;
  }
  dfs(u + 1, now);
  dfs(u + 1, now ^ a[u]);
}

int main() {
  n = read(), m = read();
  for (int i = 0; i <= m; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  }
  for (int i = 1; i <= n; i++) {
    ll x = read();
    ins(x);
  }
  if (k <= 26) {
    for (int i = 0; i <= m - 1; i++) {
      if (d[i]) a[len++] = d[i];
    }
    dfs(0, 0);
    for (int i = 0; i <= m; i++) ans[i] = cnt[i];
  } else {
    for (int i = m - 1; i >= 0; i--) {
      if (!d[i]) continue;
      for (int j = i - 1; j >= 0; j--) {
        if (d[i] >> j & 1)
          d[i] ^= d[j];
      }
    }
    for (int i = 0; i <= m - 1; i++) {
      if (d[i]) continue;
      ll zip = 1ll << i;
      for (int j = 0; j <= m - 1; j++)
        if (d[j] >> i & 1)
          zip |= 1ll << j;
      a[len++] = zip;
    }
    dfs(0, 0);
    for (int c = 0; c <= m; c++) {
      for (int a = 0; a <= m; a++) {
        int coef = 0;
        for (int b = 0; b <= c && b <= a; b++) {
          int cf = 1ll * C[a][b] * C[m - a][c - b] % mod;
          if (b & 1) coef = (coef + mod - cf) % mod;
          else coef = (coef + cf) % mod;
        }
        ans[c] = (ans[c] + 1ll * cnt[a] * coef) % mod;
      }
    }
    int mul = 1;
    rep(i, 1, m - k) mul = 1ll * inv2 * mul % mod;
    for (int c = 0; c <= m; c++) {
      ans[c] = 1ll * ans[c] * mul % mod;
    }
  }
  int mul = 1;
  rep(i, 1, n - k) mul = 2ll * mul % mod;
  rep(c, 0, m) {
    ans[c] = 1ll * ans[c] * mul % mod;
    print(ans[c], " \n"[c == m]);
  }
  return 0;
}