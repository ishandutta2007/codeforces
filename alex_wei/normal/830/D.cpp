#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using uint = unsigned int;
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
inline void print(int x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
constexpr int N = 400 + 5;
constexpr int mod = 1e9 + 7;
long long n, f[N], g[N];
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n, f[0] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; i + j <= n + 1; j++)
      for(int s = j; i + s <= n + 1; s++)
        if(f[j] && f[s - j]) {
          long long prod = f[j] * f[s - j] % mod;
          g[s + 1] += prod;
          g[s] += prod * (1 + 2 * s);
          g[s - 1] += prod * s * (s - 1);
        }
    swap(f, g), memset(g, 0, sizeof(g));
    for(int i = 0; i <= n + 1; i++) f[i] %= mod;
  }
  cout << f[1] << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/25
author: Alex_Wei
start coding at 
finish debugging at 
*/