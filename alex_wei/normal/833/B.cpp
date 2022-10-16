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
constexpr int N = 4e4 + 5;
int k, n, a[N], f[N], g[N];
int l = 1, r, cur, buc[N];
void add(int x) {cur += !buc[x]++;}
void del(int x) {cur -= !--buc[x];}
int coef(int i, int j) {
  while(r < j) add(a[++r]);
  while(l > i) add(a[--l]);
  while(r > j) del(a[r--]);
  while(l < i) del(a[l++]);
  return cur;
}
void solve(int l, int r, int pl, int pr) {
  int m = l + r >> 1, c = pl;
  for(int i = pl; i <= pr && i < m; i++) {
    int v = f[i] + coef(i + 1, m);
    if(v > g[m]) g[m] = v, c = i;
  }
  if(l < m) solve(l, m - 1, pl, c);
  if(m < r) solve(m + 1, r, c, pr);
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n >> k;
  for(int i = 1; i <= n; i++) a[i] = read();
  for(int i = 1; i <= k; i++) solve(1, n, 0, n - 1), swap(f, g);
  cout << f[n] << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/27
author: Alex_Wei
start coding at 12:53
finish debugging at 13:00
*/