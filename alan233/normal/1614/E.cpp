// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
const int M = 10000005;
const int mod = 1e9 + 1;

int minn[M], maxx[M], ls[M], rs[M], tag[M], tot, rt;

int newnode(int u, int l, int r) {
  u = ++tot;
  ls[u] = rs[u] = 0;
  tag[u] = 0;
  minn[u] = l, maxx[u] = r;
  return tot;
}
void pushup(int u) {
  minn[u] = min(minn[ls[u]], minn[rs[u]]);
  maxx[u] = max(maxx[ls[u]], maxx[rs[u]]);
}
void pushtag(int u, int dlt) {
  assert(u);
  minn[u] += dlt, maxx[u] += dlt, tag[u] += dlt;
}
void pushdown(int u, int l, int r) {
//  if (!tag[u]) return ;
  int mid = l + (r - l) / 2;
  if (!ls[u]) ls[u] = newnode(ls[u], l, mid);
  if (!rs[u]) rs[u] = newnode(rs[u], mid + 1, r);
  pushtag(ls[u], tag[u]), pushtag(rs[u], tag[u]);
  tag[u] = 0;
}
int findL(int &u, int l, int r, int val) {
  if (!u) u = newnode(u, l, r);
  if (l == r) {
    if (minn[u] == val) return l;
    else return (l == 0 ? -1 : 1e9 + 1);
  }
  pushdown(u, l, r);
  int mid = l + (r - l) / 2;
  if (maxx[ls[u]] >= val) return findL(ls[u], l, mid, val);
  else return findL(rs[u], mid + 1, r, val);
}
int findR(int &u, int l, int r, int val) {
  if (!u) u = newnode(u, l, r);
  if (l == r) {
    if (minn[u] == val) return l;
    else return (l == 0 ? -1 : 1e9 + 1);
  }
  pushdown(u, l, r);
  int mid = l + (r - l) / 2;
  if (minn[rs[u]] <= val) return findR(rs[u], mid + 1, r, val);
  else return findR(ls[u], l, mid, val);
}
void update(int &u, int l, int r, int ql, int qr, int dlt) {
  if (ql > qr) return ;
  if (!u) u = newnode(u, l, r);
  if (ql <= l && r <= qr) {
    pushtag(u, dlt);
    return ;
  }
  pushdown(u, l, r);
  int mid = l + (r - l) / 2;
  if (ql <= mid) update(ls[u], l, mid, ql, qr, dlt);
  if (qr > mid) update(rs[u], mid + 1, r, ql, qr, dlt);
  pushup(u);
}
int query(int &u, int l, int r, int pos) {
  if (!u) u = newnode(u, l, r);
  if (l == r) return maxx[u];
  pushdown(u, l, r);
  int mid = l + (r - l) / 2;
  if (pos <= mid) return query(ls[u], l, mid, pos);
  else return query(rs[u], mid + 1, r, pos);
}

int main() {
  int n = read();
  int last = 0, LIM = 1e9;
  rep(i, 1, n) {
    int T = read();
    int L = findL(rt, 0, LIM, T);
    int R = findR(rt, 0, LIM, T);
//    fprintf(stderr, "L = %d, R = %d\n", L, R);
    if (L == -1) {
      update(rt, 0, LIM, 0, LIM, -1);
    } else if (L == 1e9 + 1) {
      update(rt, 0, LIM, 0, LIM, 1);
    } else {
      update(rt, 0, LIM, 0, L - 1, 1);
      update(rt, 0, LIM, R + 1, LIM, -1);
    }
    int q = read();
    while (q--) {
      int x = (read() + last) % mod;
//      printf("now x = %d\n", x);
      print(last = query(rt, 0, LIM, x), '\n');
    }
  }
  return 0;
}