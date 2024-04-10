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

int pw[85 * 85], C[85][85];
int tot[85][85], f[85][85], bad[85][85];
int n, k, mod;

inline void add(int &x, int y) {
  x += y; if (x >= mod) x -= mod;
}
inline void sub(int &x, int y) {
  x -= y; if (x < 0) x += mod;
}

int down(int x, int y) {
  int ans = 1;
  for (int i = x; i >= x - y + 1; i--) ans = 1ll * ans * i % mod;
  return ans;
}

void init(int n) {
  pw[0] = 1;
  for (int i = 1; i <= n * n; i++) pw[i] = 2 * pw[i - 1] % mod;
  for (int i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= j; k++) {
        int coef = 1ll * C[j][k] * pw[i * k] % mod;
        if ((j - k) & 1) sub(tot[i][j], coef); else add(tot[i][j], coef);
        coef = 1ll * C[j][k] * down(pw[k] - 1, i) % mod;
        if ((j - k) & 1) sub(f[i][j], coef); else add(f[i][j], coef);
      }
      // printf("tot[%d][%d] = %d, f[%d][%d] = %d\n", i, j, tot[i][j], i, j, f[i][j]);
    }
  }
}

int main() {
  n = read(), k = read(), mod = read();
  init(80);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int ii = 0; ii < i; ii++) {
        for (int jj = 0; jj < j; jj++) {
          if ((n & 1) && i == n && ii == n - 1) continue;
          int ff = 1ll * C[i][ii] * C[j][jj] % mod * f[i - ii][j - jj] % mod * pw[(i - ii) * jj] % mod;
          add(bad[i][j], 1ll * ff * (tot[ii][jj] + mod - bad[ii][jj]) % mod); 
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= k; i++) {
    add(ans, 1ll * C[k][i] * (tot[n][i] + mod - bad[n][i]) % mod);
  }
  print(ans, '\n');
  return 0;
}