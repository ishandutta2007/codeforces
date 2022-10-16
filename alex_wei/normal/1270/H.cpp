#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
inline int read() {
  int x = 0, sgn = 0;
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
constexpr int N = 1e6;
int n, q, a[N + 5], laz[N << 2];
struct dat {
  int mn, cnt;
  dat operator + (const dat &x) const {
    dat z = {min(mn, x.mn), 0};
    if(mn == z.mn) z.cnt += cnt;
    if(x.mn == z.mn) z.cnt += x.cnt;
    return z;
  }
} val[N << 2];
void tag(int x, int v) {val[x].mn += v, laz[x] += v;}
void down(int x) {
  if(laz[x]) {
    tag(x << 1, laz[x]);
    tag(x << 1 | 1, laz[x]);
    laz[x] = 0;
  }
}
void activate(int l, int r, int p, int x, int v) {
  if(l == r) return val[x].cnt = v, void();
  int m = l + r >> 1;
  down(x);
  if(p <= m) activate(l, m, p, x << 1, v);
  else activate(m + 1, r, p, x << 1 | 1, v);
  val[x] = val[x << 1] + val[x << 1 | 1];
}
void modify(int l, int r, int ql, int qr, int x, int v) {
  if(r < ql) return;
  if(ql <= l && r <= qr) return tag(x, v);
  int m = l + r >> 1;
  down(x);
  if(ql <= m) modify(l, m, ql, qr, x << 1, v);
  if(m < qr) modify(m + 1, r, ql, qr, x << 1 | 1, v);
  val[x] = val[x << 1] + val[x << 1 | 1];
}
void add(int p, int v) {modify(1, N, min(a[p], a[p - 1]) + 1, max(a[p], a[p - 1]), 1, v);}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  // ios::sync_with_stdio(0);
  n = read(), q = read();
  a[0] = N + 1, a[n + 1] = 0;
  for(int i = 1; i <= n; i++) activate(1, N, a[i] = read(), 1, 1);
  for(int i = 1; i <= n + 1; i++) add(i, 1);
  for(int i = 1; i <= q; i++) {
    int p = read();
    add(p, -1), add(p + 1, -1);
    activate(1, N, a[p], 1, 0);
    activate(1, N, a[p] = read(), 1, 1);
    add(p, 1), add(p + 1, 1);
    cout << val[1].cnt << "\n";
  }
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/10
author: Alex_Wei
start coding at 8:08 
finish debugging at 9:05
*/