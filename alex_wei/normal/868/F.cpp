#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
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
constexpr int N = 1e5 + 5;
int n, k, a[N], l = 1, r = 0, buc[N];
ll f[N], g[N], coef;
ll trans(int i, int j) {
  while(r < j) coef += buc[a[++r]]++;
  while(l > i + 1) coef += buc[a[--l]]++;
  while(r > j) coef -= --buc[a[r--]];
  while(l < i + 1) coef -= --buc[a[l++]];
  return f[i] + coef;
}
void solve(int l, int r, int pl, int pr) {
  int m = l + r >> 1, c = pl;
  for(int i = pl; i <= min(pr, m - 1); i++) {
    ll val = trans(i, m);
    if(val < g[m]) g[m] = val, c = i;
  }
  if(l < m) solve(l, m, pl, c);
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
  memset(f, 0x3f, sizeof(f)), f[0] = 0;
  for(int i = 1; i <= k; i++) {
    memset(g, 0x3f, sizeof(g));
    solve(1, n, 0, n - 1);
    swap(f, g);
  }
  cout << f[n] << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/23
author: Alex_Wei
start coding at 7:19
finish debugging at 7:24
*/