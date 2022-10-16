// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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

const int N = 300005;

vector<pii> ask[N];
int a[N], n, q;

#define ls (u << 1)
#define rs (u << 1 | 1)
int minn[N << 2], who[N << 2], lazy[N << 2];
inline void pushup(int u) {
  if (minn[rs] <= minn[ls]) minn[u] = minn[rs], who[u] = who[rs];
  else minn[u] = minn[ls], who[u] = who[ls];
}
inline void pushtag(int u, int dlt) {
  minn[u] -= dlt;
  lazy[u] += dlt;
}
inline void pushdown(int u) {
  if (lazy[u]) {
    pushtag(ls, lazy[u]);
    pushtag(rs, lazy[u]);
    lazy[u] = 0;
  }
}
void build(int u, int l, int r) {
  if (l == r) {
    minn[u] = a[l], who[u] = l;
    return ;
  }  
  int mid = l + r >> 1;
  build(ls, l, mid), build(rs, mid + 1, r);
  pushup(u);
}
void ban(int u, int l, int r, int pos) {
  if (l == r) {
    minn[u] = 1e9, who[u] = l;
    return ;
  }
  pushdown(u);
  int mid = l + r >> 1;
  if (pos <= mid) ban(ls, l, mid, pos);
  else ban(rs, mid + 1, r, pos);
  pushup(u);
}
void update(int u, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    pushtag(u, 1);
    return ;
  }
  pushdown(u);
  int mid = l + r >> 1;
  if (ql <= mid) update(ls, l, mid, ql, qr);
  if (qr > mid) update(rs, mid + 1, r, ql, qr);
  pushup(u);
}
inline void adjust() {
  while (minn[1] < 0) {
    ban(1, 1, n, who[1]);
  }
}

struct Fen {
  int c[N];
  inline void add(int x, int dlt) {
    while (x <= n) c[x] += dlt, x += x & -x;
  }  
  inline int qry(int x) {
    int ret = 0;
    while (x) ret += c[x], x ^= x & -x;
    return ret;
  }
} tr;
int ans[N];

int main() {
  n = read(), q = read();
  rep(i, 1, n) a[i] = i - read();
  rep(i, 1, q) {
    int x = read(), y = read();
    ask[x + 1].pb({n - y, i});
  }
  build(1, 1, n), adjust();
  per(i, n, 1) {
    while (minn[1] == 0 && who[1] >= i) {
      int t = who[1];
      tr.add(t, 1);
      ban(1, 1, n, t);
      update(1, 1, n, t, n);
      adjust();
    }
    for (auto it: ask[i])
      ans[it.sec] = tr.qry(it.fir);
  }
  rep(i, 1, q) print(ans[i], '\n');
  return 0;
}