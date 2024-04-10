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
constexpr int N = 1.5e5 + 5;
int n, m, k, a[N], len[N << 2], laz[N << 2];
struct dat {
  pii a[5];
  dat operator + (const dat &x) const {
    dat z = *this;
    for(int i = 0; i < k; i++) {
      pii cur = x.a[i];
      if(!cur.second) continue;
      bool add = 0;
      for(int j = 0; j < k; j++)
        if(z.a[j].first == cur.first)
          z.a[j].second += cur.second, add = 1;
      if(!add) {
        if(cur.second >= z.a[k - 1].second) {
          cur.second -= z.a[k - 1].second;
          for(int j = 0; j < k; j++) z.a[j].second -= z.a[k - 1].second;
          z.a[k - 1] = cur;
        }
        else for(int j = 0; j < k; j++) z.a[j].second -= cur.second;
      }
      sort(z.a, z.a + k, [&](pii x, pii y) {return x.second > y.second;});
    }
    return z;
  }
} val[N << 2];
void build(int l, int r, int x) {
  len[x] = r - l + 1;
  if(l == r) return val[x].a[0] = {a[l], 1}, void();
  int m = l + r >> 1;
  build(l, m, x << 1), build(m + 1, r, x << 1 | 1);
  val[x] = val[x << 1] + val[x << 1 | 1];
}
void tag(int x, int v) {
  for(int i = 0; i < k; i++) val[x].a[i] = {0, 0};
  val[x].a[0] = {laz[x] = v, len[x]};
}
void down(int x) {
  if(laz[x]) {
    tag(x << 1, laz[x]);
    tag(x << 1 | 1, laz[x]);
    laz[x] = 0;
  }
}
void modify(int l, int r, int ql, int qr, int x, int v) {
  if(ql <= l && r <= qr) return tag(x, v);
  int m = l + r >> 1;
  down(x);
  if(ql <= m) modify(l, m, ql, qr, x << 1, v);
  if(m < qr) modify(m + 1, r, ql, qr, x << 1 | 1, v);
  val[x] = val[x << 1] + val[x << 1 | 1];
}
dat query(int l, int r, int ql, int qr, int x) {
  if(ql <= l && r <= qr) return val[x];
  int m = l + r >> 1;
  down(x);
  if(qr <= m) return query(l, m, ql, qr, x << 1);
  if(m < ql) return query(m + 1, r, ql, qr, x << 1 | 1);
  return query(l, m, ql, qr, x << 1) + query(m + 1, r, ql, qr, x << 1 | 1);
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n >> m >> k, k = 100 / k;
  for(int i = 1; i <= n; i++) a[i] = read();
  build(1, n, 1);
  for(int i = 1; i <= m; i++) {
    int op = read(), l = read(), r = read();
    if(op == 1) modify(1, n, l, r, 1, read());
    else {
      dat ans = query(1, n, l, r, 1);
      print(k), putchar(' ');
      for(int j = 0; j < k; j++) print(max(1, ans.a[j].first)), putchar(' ');
      cout << "\n";
    }
  }
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/16
author: Alex_Wei
start coding at
finish debugging at
*/