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

struct Edge {
  int to, nxt, val;
} edge[N << 1];
int head[N], tot;
void add(int u, int v, int val) {
  edge[++tot] = {v, head[u], val};
  head[u] = tot;
}

int a[N], ans1[N], ans2[N];
int _u[N], _v[N], _c[N], _t[N], ide[N];
int _qc[N], _qx[N], idq[N];
int n, q;

int jp[N][20], mx[N][20], dep[N];
void dfs1(int u, int fa) {
  dep[u] = dep[fa] + 1;
  for (int i = 1; i < 20; i++) {
    jp[u][i] = jp[jp[u][i - 1]][i - 1];
    mx[u][i] = max(mx[u][i - 1], mx[jp[u][i - 1]][i - 1]);
  }
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa) continue;
    jp[v][0] = u, mx[v][0] = edge[i].val;
    dfs1(v, u);
  }
}
int query(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int k = 0;
  for (int i = 19; i >= 0; i--) {
    if (dep[jp[u][i]] >= dep[v]) ckmax(k, mx[u][i]), u = jp[u][i];
  }
  if (u == v) return k;
  for (int i = 19; i >= 0; i--) {
    if (jp[u][i] != jp[v][i]) {
      ckmax(k, max(mx[u][i], mx[v][i]));
      u = jp[u][i];
      v = jp[v][i];
    }
  }
  return max(k, max(mx[u][0], mx[v][0]));
}

int f[N], dot[N], maxx[N];
int find(int x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return ;
  f[x] = y;
  if (a[dot[x]] > a[dot[y]]) {
    dot[y] = dot[x];
    maxx[y] = maxx[x];
  } else if (a[dot[x]] == a[dot[y]]) {
    ckmax(maxx[y], max(maxx[x], query(dot[x], dot[y])));
  }
}

int main() {
  n = read(), q = read();
  rep(i, 1, n) a[i] = read();
  rep(i, 1, n - 1) {
    _u[i] = read(), _v[i] = read(), _c[i] = read(), _t[i] = read();
    add(_u[i], _v[i], _t[i]);
    add(_v[i], _u[i], _t[i]);
    ide[i] = i;
  }
  dfs1(1, 0);
  sort(ide + 1, ide + n, [&](int x, int y) { return _c[x] > _c[y]; });
  rep(i, 1, q) {
    _qc[i] = read(), _qx[i] = read();
    idq[i] = i;
  }
  sort(idq + 1, idq + q + 1, [&](int x, int y) { return _qc[x] > _qc[y]; });
  rep(i, 1, n) f[i] = i, dot[i] = i, maxx[i] = 0;
  int j = 1;
  rep(i, 1, q) {
    while (j <= n - 1 && _c[ide[j]] >= _qc[idq[i]]) {
      int u = _u[ide[j]], v = _v[ide[j]];
      merge(u, v);
      j++;
    }
    int g = find(_qx[idq[i]]);
    ans1[idq[i]] = a[dot[g]];
    ans2[idq[i]] = max(maxx[g], query(_qx[idq[i]], dot[g]));
  }
  rep(i, 1, q) {
    print(ans1[i], ' '), print(ans2[i], '\n');
  }
  return 0;
}