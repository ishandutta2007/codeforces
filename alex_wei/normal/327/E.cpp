#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
constexpr int N = 24 + 5;
constexpr int mod = 1e9 + 7;
int k, x, y, n, a[N], fc[N];
int sL[1 << 12], sR[1 << 12];
gp_hash_table<ll, int> f[N][N];
unordered_map<int, int> g[N];
ll hsh(int x, int y) {return 1ll * x * mod + y;}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  for(int i = fc[0] = 1; i < N; i++) fc[i] = 1ll * fc[i - 1] * i % mod;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  cin >> k;
  if(!k) cout << fc[n] << endl, exit(0);
  x = read(), y = k == 2 ? read() : x;
  if(x > y) swap(x, y);
  y -= x;
  int L = n + 1 >> 1, R = n - L;
  for(int S = 1; S < 1 << L; S++)
    sL[S] = min(mod, sL[S ^ (S & -S)] + a[__builtin_ctz(S & -S)]);
  for(int S = 1; S < 1 << R; S++)
    sR[S] = min(mod, sR[S ^ (S & -S)] + a[L + __builtin_ctz(S & -S)]);
  int mL = (1 << L) - 1, mR = (1 << R) - 1, ans = fc[n];
  auto solve2 = [&]() {
    for(int S = 0; S < 1 << R; S++) {
      if(sR[S] > x) continue;
      int C = mR ^ S;
      for(int T = C; ; T = C & (T - 1)) {
        int ppS = __builtin_popcount(S);
        int ppT = __builtin_popcount(T);
        if(sR[T] <= y) f[ppS][ppT][hsh(sR[S], sR[T])]++;
        if(!T) break;
      }
    }
    for(int S = 0; S < 1 << L; S++) {
      int C = mL ^ S;
      if(sL[S] > x) continue;
      for(int T = C; ; T = C & (T - 1)) {
        int ppS = __builtin_popcount(S);
        int ppT = __builtin_popcount(T);
        if(sL[T] > y) continue;
        for(int c = 0; c <= R; c++)
          for(int d = 0; d + c <= R; d++) {
            auto it = f[c][d].find(hsh(x - sL[S], y - sL[T]));
            if(it == f[c][d].end()) continue;
            int coef = 1ll * fc[c + ppS] * fc[d + ppT] % mod * fc[n - c - d - ppS - ppT] % mod;
            ans = (ans + 1ll * coef * it->second) % mod;
          }
        if(!T) break;
      }
    }
  };
  auto solve = [&](int x) {
    for(int i = 0; i < N; i++) g[i].clear();
    for(int S = 0; S < 1 << R; S++) {
      int ppS = __builtin_popcount(S);
      if(sR[S] <= x) g[ppS][sR[S]]++;
    }
    for(int S = 0; S < 1 << L; S++) {
      int ppS = __builtin_popcount(S);
      if(sL[S] > x) continue;
      for(int c = 0; c <= R; c++) {
        auto it = g[c].find(x - sL[S]);
        if(it == g[c].end()) continue;
        int coef = 1ll * fc[c + ppS] * fc[n - c - ppS] % mod;
        ans = (ans + mod - 1ll * coef * it->second % mod) % mod;
      }
    }
  };
  solve2(), solve(x), solve(x + y);
  cout << ans << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/10/19
author: Alex_Wei
start coding at
finish debugging at
*/