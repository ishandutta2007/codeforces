// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) ((x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 200005;

struct node {
  int l, r;
  friend bool operator < (const node &x, const node &y) {
    if (x.l != y.l) return x.l < y.l;
    else return x.r > y.r;
  }
} b[N];
int a[N];
ll f[N], g[N];
int n, m;

void solve() {
  n = read(), m = read();
  rep(i, 0, n + 1) f[i] = g[i] = 2e9;
  set<int> tp;
  rep(i, 1, n) a[i] = read(), tp.insert(a[i]);
  sort(a + 1, a + n + 1);
  rep(i, 1, m) {
    b[i].l = read(), b[i].r = read();
    auto it = tp.lower_bound(b[i].l);
    if (it != tp.end() && *it <= b[i].r) {
      i--, m--;
    }
  }
  sort(b + 1, b + m + 1);
  int m2 = 0;
  rep(i, 1, m) {
    while (m2 && b[m2].r >= b[i].r) --m2;
    b[++m2] = b[i];
  }
  m = m2;
  if (m == 0) {
    puts("0");
    return ;
  }
//  rep(i, 1, m) {
//    printf("b[%d] = (%d, %d)\n", i, b[i].l, b[i].r);
//  }
  int tail = 1;
  if (b[tail].r < a[1]) {
    f[1] = 2ll * (a[1] - b[tail].r);
    g[1] = a[1] - b[tail].r;
    while (tail <= m && b[tail].r < a[1]) ++tail;
  } else {
    f[1] = g[1] = 0;
  }
//  printf("f[1] = %d, g[1] = %d\n", f[1], g[1]);
  rep(i, 1, n - 1) {
    int tp = tail;
    while (tail <= m && b[tail].r < a[i + 1]) ++tail;
//    if (tp == tail) {
//      ckmin(f[i + 1], f[i]);
//      ckmin(f[i + 1], g[i]);
//      ckmin(g[i + 1], f[i]);
//      ckmin(g[i + 1], g[i]);
//      continue;
//    }
//    printf("i = %d, tp = %d, tail = %d\n", i, tp, tail);
    rep(k, tp - 1, tail - 1) {
      ckmin(f[i + 1], f[i] +     (k != tp - 1 ? b[k].l - a[i]: 0) + 2ll * (k + 1 != tail ? a[i + 1] - b[k + 1].r : 0));
      ckmin(g[i + 1], f[i] +     (k != tp - 1 ? b[k].l - a[i]: 0) +     (k + 1 != tail ? a[i + 1] - b[k + 1].r : 0));
      ckmin(f[i + 1], g[i] + 2ll * (k != tp - 1 ? b[k].l - a[i]: 0) + 2ll * (k + 1 != tail ? a[i + 1] - b[k + 1].r : 0));
      ckmin(g[i + 1], g[i] + 2ll * (k != tp - 1 ? b[k].l - a[i]: 0) +     (k + 1 != tail ? a[i + 1] - b[k + 1].r : 0));
    }
//    printf("f[%d] = %d, g[%d] = %d\n", i + 1, f[i + 1], i + 1, g[i + 1]);
  }
  if (tail <= m) {
    f[n] += b[m].l - a[n];
    g[n] += 2ll * (b[m].l - a[n]); 
  }
  print(min(f[n], g[n]), '\n');
}

int main() {
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}