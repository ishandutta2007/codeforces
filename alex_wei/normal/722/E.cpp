#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using uint = unsigned int;
using ld = long double;
// using lll = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
inline ll read() {
  ll x = 0, sgn = 0;
  char s = getchar();
  while(!isdigit(s)) sgn |= s == '-', s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return sgn ? -x : x;
}
inline void print(ll x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
constexpr int N = 2e5 + 5;
constexpr int K = 2e3 + 5;
constexpr int C = 22;
constexpr int mod = 1e9 + 7;
void add(int &x, int y) {x += y, x >= mod && (x -= mod);}
int ksm(int a, int b) {
  int s = 1;
  while(b) {
    if(b & 1) s = 1ll * s * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return s;
}
int fc[N], ifc[N], coef[K][K];
int bin(int n, int m) {return 1ll * fc[n] * ifc[m] % mod * ifc[n - m] % mod;}
int n, m, k, s, ans, f[C + 1][K];
pii x[K];
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  for(int i = fc[0] = 1; i < N; i++) fc[i] = 1ll * fc[i - 1] * i % mod;
  ifc[N - 1] = ksm(fc[N - 1], mod - 2);
  for(int i = N - 2; ~i; i--) ifc[i] = 1ll * ifc[i + 1] * (i + 1) % mod;
  cin >> n >> m >> k >> s;
  for(int i = 1; i <= k; i++) cin >> x[i].fi >> x[i].se;
  sort(x + 1, x + k + 1);
  f[0][0] = 1, x[0] = {1, 1}, x[++k] = {n, m};
  for(int i = 0; i <= k; i++) 
    for(int j = i + 1; j <= k; j++) {
      pii u = x[i], v = x[j];
      if(u.fi > v.fi || u.se > v.se) continue;
      coef[i][j] = bin(v.fi - u.fi + v.se - u.se, v.fi - u.fi);
    }
  for(int i = 1; i < C; i++) {
    for(int j = 1; j <= k; j++) {
      for(int l = 0; l < j; l++) {
        add(f[i][j], 1ll * f[i - 1][l] * coef[l][j] % mod);
        add(f[i][j], mod - 1ll * f[i][l] * coef[l][j] % mod);
      }
    }
  }
  f[C][k] = coef[0][k];
  for(int i = 1; i < C; i++) add(f[C][k], mod - f[i][k]);
  for(int i = 1; i <= C; i++, s -= s >> 1) add(ans, 1ll * s * f[i][k] % mod);
  cout << 1ll * ans * ksm(coef[0][k], mod - 2) % mod << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/10/10
author: Alex_Wei
start coding at 
finish debugging at 
*/