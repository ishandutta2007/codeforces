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
constexpr int N = 1e5 + 5;
bool vis[N];
int cnt, pr[N], phi[N], l = 1, r;
ll S[N], f[18][N], res;
vector<int> d[N];
ll coef(int pl, int pr) {
  while(r < pr) {
    r++;
    for(int it : d[r])
      if(it >= l) res += phi[r / it];
      else break;
  }
  while(l > pl) res += S[r / (--l)];
  while(r > pr) {
    for(int it : d[r])
      if(it >= l) res -= phi[r / it];
      else break;
    r--;
  }
  while(l < pl) res -= S[r / (l++)];
  return res;
}
void solve(int l, int r, int pl, int pr, ll *f, ll *g) {
  int m = l + r >> 1, c = pl;
  for(int i = pl; i <= pr && i < m; i++) {
    ll val = f[i] + coef(i + 1, m);
    if(val < g[m]) g[m] = val, c = i;
  }
  if(l < m) solve(l, m, pl, c, f, g);
  if(m < r) solve(m + 1, r, c, pr, f, g);
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  for(int i = 1; i < N; i++)
    for(int j = i; j < N; j += i)
      d[j].push_back(i);
  for(int i = 1; i < N; i++) reverse(d[i].begin(), d[i].end());
  phi[1] = 1;
  for(int i = 2; i < N; i++) {
    if(!vis[i]) vis[i] = 1, phi[i] = i - 1, pr[++cnt] = i;
    for(int j = 1; j <= cnt && i * pr[j] < N; j++) {
      vis[i * pr[j]] = 1;
      if(i % pr[j] == 0) {
        phi[i * pr[j]] = phi[i] * pr[j];
        break;
      }
      phi[i * pr[j]] = phi[i] * (pr[j] - 1);
    }
  }
  for(int i = 1; i < N; i++) S[i] = S[i - 1] + phi[i];
  memset(f, 0x3f, sizeof(f)), f[0][0] = 0;
  for(int i = 1; i < 18; i++) solve(1, N - 1, 0, N - 2, f[i - 1], f[i]);
  int T = read();
  while(T--) {
    int n = read(), k = read();
    if(k > 31 - __builtin_clz(n)) print(n);
    else print(f[k][n]);
    putchar('\n');
  }
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/10/11
author: Alex_Wei
start coding at 15:01
finish debugging at 15:22
*/