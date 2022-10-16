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

const int N = 21;
const int mod = 31607;

struct FastMod {
  typedef unsigned long long ULL;
  typedef __uint128_t LLL;
  ULL b, m;
  void init(ULL b) { this->b = b, m = ULL((LLL(1) << 64) / b); }
  ULL operator()(ULL a){
    ULL q = (ULL)((LLL(m) * a) >> 64);
    ULL r = a - q * b;
    return r >= b ? r - b : r;
  }
} M;
inline int mul(int a, int b) { return M(1ull * a * b); }

inline int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1; 
  }  
  return res;
} 

// row[i]: 
// fuck[i]: 
 
int a[N][N], ia[N][N], cov[N][N], row[N], fuck[N];
int n, ans;

void dfs(int col, int ie) { //  col  
  if (col == n) {
    int coef = 1;
    rep(i, 0, n - 1) coef = mul(mul(coef,row[i]), mod + 1 - fuck[i]);
    if (ie) ans = (ans + mod - coef) % mod;
    else ans = (ans + coef) % mod;
    return ;
  }
  // 
  dfs(col + 1, ie);
  // 
  rep(i, 0, n - 1) {
    if (cov[i][col]++ == 0) {
      row[i] = mul(row[i], a[i][col]);
      fuck[i] = mul(fuck[i], ia[i][col]); 
    }
  } 
  dfs(col + 1, ie ^ 1);
  rep(i, 0, n - 1) {
    if (--cov[i][col] == 0) {
      row[i] = mul(row[i], ia[i][col]);
      fuck[i] = mul(fuck[i], a[i][col]);
    }
  } 
}

int main() {
  M.init(mod);
  n = read();
  rep(i, 0, n - 1) {
    row[i] = 1, fuck[i] = 1;
    rep(j, 0, n - 1) {
      a[i][j] = 1ull * read() * qpow(10000) % mod;
      ia[i][j] = qpow(a[i][j]);
      fuck[i] = 1ull * fuck[i] * a[i][j] % mod;
    }
  }
  rep(p, 0, 1) {
    rep(q, 0, 1) {
      if (p) {
        rep(i, 0, n - 1) {
          if (cov[i][i]++ == 0) {
            row[i] = 1ull * row[i] * a[i][i] % mod;
            fuck[i] = 1ull * fuck[i] * ia[i][i] % mod; 
          }
        } 
      }
      if (q) {
        rep(i, 0, n - 1) {
          if (cov[i][n - 1 - i]++ == 0) {
            row[i] = 1ull * row[i] * a[i][n - 1 - i] % mod;
            fuck[i] = 1ull * fuck[i] * ia[i][n - 1 - i] % mod;
          }
        }
      }
      dfs(0, p ^ q);
      if (p) {
        rep(i, 0, n - 1) {
          if (--cov[i][i] == 0) {
            row[i] = 1ull * row[i] * ia[i][i] % mod;
            fuck[i] = 1ull * fuck[i] * a[i][i] % mod; 
          }
        } 
      }
      if (q) {
        rep(i, 0, n - 1) {
          if (--cov[i][n - 1 - i] == 0) {
            row[i] = 1ull * row[i] * ia[i][n - 1 - i] % mod;
            fuck[i] = 1ull * fuck[i] * a[i][n - 1 - i] % mod;
          }
        }
      }
    }
  }
  print((mod + 1 - ans) % mod, '\n');
  return 0;
}