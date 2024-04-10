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
constexpr int B = 333;
int n, m, q, ans[N];
int a[N], blk[N], lp[N], rp[N];
int suf[N], pre[N], fst[N];
vector<int> buc[N];
vector<pii> qu[N];
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n >> m;
  for(int i = 1; i <= n; i++) a[i] = i, blk[i] = i / B;
  for(int i = 0; i <= blk[n]; i++) lp[i] = max(1, i * B), rp[i] = min(n, i * B + B - 1);
  for(int i = 1; i <= m; i++) {
    int l = read(), r = read();
    buc[l].push_back(r);
  }
  cin >> q;
  for(int i = 1; i <= q; i++) {
    int x = read(), y = read();
    qu[x].push_back({y, i});
  }
  auto rebuild = [&](int id, int lim) {
    int l = max(lim, lp[id]), r = rp[id];
    suf[r] = a[r];
    for(int i = r - 1; i >= l; i--) suf[i] = min(suf[i + 1], a[i]);
    pre[l] = a[l];
    for(int i = l + 1; i <= r; i++) pre[i] = min(pre[i - 1], a[i]);
    fst[l] = a[l] < l ? l : l - 1;
    for(int i = l + 1; i <= r; i++) fst[i] = a[i] < l ? i : fst[i - 1];
  };
  for(int i = n; i; i--) {
    for(int it : buc[i]) {
      int cur = it;
      for(int p = it; p <= rp[blk[it]]; p++) if(a[p] <= it) a[p] = i;
      rebuild(blk[it], i);
    }
    rebuild(blk[i], i);
    for(pii it : qu[i]) {
      int y = it.first, x = a[y], ans = y;
      while(1) {
        while(blk[x] < blk[y]) {
          x = suf[min(x, pre[y])];
          y = lp[blk[y]] - 1;
        }
        if(blk[y] == blk[i]) {
          if(i < x) {
            for(int p = y; p >= i; p--) {
              if(a[p] == i) {
                ans = p;
                break;
              }
            }
          }
          break;
        }
        if(blk[x] == blk[y]) ans = y = fst[x], x = a[y];
      }
      ::ans[it.second] = ans;
    }
  }
  for(int i = 1; i <= q; i++) print(ans[i]), putchar('\n'); 
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/21
author: Alex_Wei
start coding at 
finish debugging at 20:34
*/