// LUOGU_RID: 91430430
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
constexpr int N = 1e6 + 5;
constexpr int S = 26;
int n, ans, cor[N], res[N];
char s[N];
int cnt = 1, las = 1, f[N];
int fa[N], len[N], son[N][S];
void ins(int it) {
  int p = las, cur = ++cnt;
  len[cur] = len[p] + 1, las = cur;
  while(!son[p][it]) son[p][it] = cur, p = fa[p];
  if(!p) return fa[cur] = 1, void();
  int q = son[p][it];
  if(len[p] + 1 == len[q]) return fa[cur] = q, void();
  int cl = ++cnt;
  len[cl] = len[p] + 1;
  memcpy(son[cl], son[q], S << 2);
  fa[cl] = fa[q], fa[q] = fa[cur] = cl;
  while(son[p][it] == q) son[p][it] = cl, p = fa[p];
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  scanf("%d%s", &n, s + 1);
  reverse(s + 1, s + n + 1);
  for(int i = 1; i <= n; i++) ins(s[i] - 'a');
  int l = 1, p = 1;
  for(int r = 1; r <= n; r++) {
    int q = p;
    p = son[p][s[r] - 'a'];
    auto update = [&](int p, int v) {
      if(v <= f[p]) return;
      f[p] = v, p = fa[p];
      while(p > 1 && f[p] != len[p]) f[p] = len[p], p = fa[p];
    };
    while(l < r) {
      if(max(max(f[p], f[q]), f[fa[p]]) >= r - l) break;
      update(cor[l], res[l]), l++;
      if(len[fa[p]] >= r - l + 1) p = fa[p];
      if(len[fa[q]] >= r - l) q = fa[q];
    }
    cor[r] = p, res[r] = r - l + 1;
    ans = max(ans, r - l + 1);
  }
  cout << ans << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/10/25
author: Alex_Wei
start coding at 
finish debugging at
*/