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

const int N = 200005;

struct node {
  int opt, x, y;
} q[N];
map<int, int> event[N], exist[N];
int n, m;

int f[N], sz[N], stk[N], top;
int find(int x) { return f[x] == x ? x : find(f[x]); }
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return ;
  if (sz[x] > sz[y]) swap(x, y);
  f[x] = y, sz[y] += sz[x], stk[++top] = x;
}
void undo() {
  int x = stk[top--];
  sz[f[x]] -= sz[x], f[x] = x;
}

int ans[N], lastans;

struct SMT {
  #define ls (u << 1)
  #define rs (u << 1 | 1)
  vector<pii> tmp[N << 2];
  void update(int u, int l, int r, int ql, int qr, pii ev) {
    if (ql <= l && r <= qr) {
      tmp[u].pb(ev);
      return ;
    }
    int mid = l + r >> 1;
    if (ql <= mid) update(ls, l, mid, ql, qr, ev);
    if (qr > mid) update(rs, mid + 1, r, ql, qr, ev);
  }  
  void query(int u, int l, int r) {
    int _ = top;
    for (auto [x, y]: tmp[u]) if (exist[x][y]) merge(x, y);
    if (l == r) {
      q[l].x = (q[l].x + lastans - 1) % n + 1;
      q[l].y = (q[l].y + lastans - 1) % n + 1;
      if (q[l].x > q[l].y) swap(q[l].x, q[l].y);
      if (q[l].opt == 1) {
        exist[q[l].x][q[l].y] ^= 1;
      } else {
        lastans = find(q[l].x) == find(q[l].y);
        ans[l] = lastans;
      }
    } else {
      int mid = l + r >> 1;
      query(ls, l, mid), query(rs, mid + 1, r);
    }
    while (top > _) undo();
  }
} smt;

int main() {
  n = read(), m = read();
  rep(i, 1, n) f[i] = i, sz[i] = 1;
  rep(i, 1, m) {
    q[i].opt = read(), q[i].x = read(), q[i].y = read();
    if (q[i].x > q[i].y) swap(q[i].x, q[i].y);
    if (q[i].opt == 1) {
      if (event[q[i].x].count(q[i].y)) smt.update(1, 1, m, event[q[i].x][q[i].y] + 1, i, {q[i].x, q[i].y});
      event[q[i].x][q[i].y] = i;
      int x = q[i].x % n + 1, y = q[i].y % n + 1;
      if (x > y) swap(x, y);
      if (event[x].count(y)) smt.update(1, 1, m, event[x][y] + 1, i, {x, y});
      event[x][y] = i;
    }
  }
  rep(i, 1, n) {
    for (auto [j, tim]: event[i])
      if (tim != m)
        smt.update(1, 1, m, tim + 1, m, {i, j});
  }
  smt.query(1, 1, m);
  rep(i, 1, m) {
    if (q[i].opt == 2)
      print(ans[i]);
  }
  return 0;
}