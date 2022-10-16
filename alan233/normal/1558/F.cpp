// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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
#define SZ(x) (int(x.size()))

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
const int inf = 1e9;

struct SMT {
  #define ls (u << 1)
  #define rs (u << 1 | 1)
  int maxx[N << 2], lazy[N << 2];
  void pushup(int u) {
    maxx[u] = max(maxx[ls], maxx[rs]);
  }
  void pushtag(int u, int dlt) {
    maxx[u] += dlt, lazy[u] += dlt;
  }
  void pushdown(int u) {
    if (lazy[u]) pushtag(ls, lazy[u]), pushtag(rs, lazy[u]), lazy[u] = 0; 
  }
  void build(int u, int l, int r) {
    maxx[u] = lazy[u] = 0;
    if (l == r) {
      maxx[u] = l - 1;
      return ;
    }
    int mid = l + r >> 1;
    build(ls, l, mid), build(rs, mid + 1, r);
    pushup(u);
  }
  void add(int u, int l, int r, int ql, int qr, int dlt) {
    if (ql <= l && r <= qr) { pushtag(u, dlt); return ; }
    pushdown(u);
    int mid = l + r >> 1;
    if (ql <= mid) add(ls, l, mid, ql, qr, dlt);
    if (qr > mid) add(rs, mid + 1, r, ql, qr, dlt);
    pushup(u);
  }
  int qry(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return maxx[u];
    pushdown(u);
    int mid = l + r >> 1, ret = -inf;
    if (ql <= mid) ckmax(ret, qry(ls, l, mid, ql, qr));
    if (qr > mid) ckmax(ret, qry(rs, mid + 1, r, ql, qr));
    return ret;
  }
} smt;

bool vis[N];
int a[N], pos[N];
int n;

void solve() {
  n = read();
  rep(i, 1, n) a[i] = read(), vis[i] = 0, pos[a[i]] = i;
  smt.build(1, 1, n);
  for (int i = 2; i <= n; i += 2) smt.add(1, 1, n, i, i, 1);
  int ans = 0;
  set<int> zero, one;
  for (int i = 1; i <= n; i++) one.insert(i);
  for (int i = 1; i < n; i++) { // <= i  0, > i  1 
    int ps = pos[i];
    one.erase(ps), zero.insert(ps);
    smt.add(1, 1, n, ps, n, -2);
//    printf("modify %d %d\n", ps, n);
    int l = *one.begin(), r = *(--zero.end());
    if (l <= r) {
//      printf("query %d %d\n", l, r);
//      printf("i = %d, ans = %d\n", i, i + smt.qry(1, 1, n, l, r));
      ckmax(ans, i + smt.qry(1, 1, n, l, r));
    }
  }
  print(ans, '\n');
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}