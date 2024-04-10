#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline int read() {
  int x = 0;
  char s = getchar();
  while(!isdigit(s)) s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return x;
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
constexpr int K = 35;
constexpr int N = 3e5 + 5;
int n, q, cnt, a[N], d[N << 1];
int op[N], x[N], y[N], k[N];
int disc(int v) {return lower_bound(d + 1, d + cnt + 1, v) - d;}
struct BIT {
  ll val[N << 1], c[N];
  void build() {
    for(int i = 1; i < N << 1; i++) val[i] = rnd();
    for(int i = 1; i <= n; i++) c[i] += val[a[i]], c[min(n + 1, i + (i & -i))] += c[i];
  }
  void add(int x, ll v) {while(x <= n) c[x] += v, x += x & -x;}
  ll query(int x) {ll s = 0; while(x) s += c[x], x -= x & -x; return s;}
  ll query(int l, int r) {return query(r) - query(l - 1);}
} tr[K];
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n >> q, cnt = n;
  for(int i = 1; i <= n; i++) a[i] = d[i] = read();
  for(int i = 1; i <= q; i++) {
    op[i] = read(), x[i] = read(), y[i] = read();
    if(op[i] == 1) d[++cnt] = y[i];
    else k[i] = read();
  }
  sort(d + 1, d + cnt + 1);
  cnt = unique(d + 1, d + cnt + 1) - d - 1;
  for(int i = 1; i <= n; i++) a[i] = disc(a[i]);
  for(int i = 0; i < K; i++) tr[i].build();
  for(int i = 1; i <= q; i++) {
    if(op[i] == 1) {
      y[i] = disc(y[i]);
      for(int j = 0; j < K; j++) tr[j].add(x[i], tr[j].val[y[i]] - tr[j].val[a[x[i]]]);
      a[x[i]] = y[i];
    }
    else {
      bool ok = 1;
      for(int j = 0; j < K; j++) ok &= tr[j].query(x[i], y[i]) % k[i] == 0;
      puts(ok ? "YES" : "NO");
    }
  }
  return 0;
}
//