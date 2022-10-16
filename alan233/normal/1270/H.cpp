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
#define SZ(x) ((int)(x.size()))
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

const int N = 1000005;
const int inf = 1e9;

int cov[N];
int a[N], n, q;

struct SMT {
  #define ls (u << 1)
  #define rs (u << 1 | 1)
  int minn[N << 2], mcnt[N << 2], lazy[N << 2];
  void pushup(int u) {
    if (minn[ls] < minn[rs]) minn[u] = minn[ls], mcnt[u] = mcnt[ls];
    else if (minn[rs] < minn[ls]) minn[u] = minn[rs], mcnt[u] = mcnt[rs];
    else minn[u] = minn[ls], mcnt[u] = mcnt[ls] + mcnt[rs];
  }
  void pushtag(int u, int dlt) {
    minn[u] += dlt, lazy[u] += dlt;
  }
  void pushdown(int u) {
    if (lazy[u]) {
      pushtag(ls, lazy[u]);
      pushtag(rs, lazy[u]);
      lazy[u] = 0;
    }
  }
  void build(int u, int l, int r) {
    if (l == r) {
      minn[u] = inf, mcnt[u] = 1;
      return ;
    }
    int mid = l + r >> 1;
    build(ls, l, mid), build(rs, mid + 1, r);
    pushup(u);
  }
  void update(int u, int l, int r, int ql, int qr, int dlt) {
    if (ql <= l && r <= qr) {
      pushtag(u, dlt);
      return ;
    }
    pushdown(u);
    int mid = l + r >> 1;
    if (ql <= mid) update(ls, l, mid, ql, qr, dlt);
    if (qr > mid) update(rs, mid + 1, r, ql, qr, dlt);
    pushup(u);
  }
} smt;

int main() {
  n = read(), q = read();
  rep(i, 1, n) {
    a[i] = read();
  }
  smt.build(1, 1, 1e6);
  rep(i, 2, n) {
    if (a[i - 1] < a[i])
      smt.update(1, 1, 1e6, a[i - 1] + 1, a[i], 1);
  }
  rep(i, 1, n) {
    if (cov[a[i]]++ == 0)
      smt.update(1, 1, 1e6, a[i], a[i], -inf);
  }
  while (q--) {
    int pos = read(), x = read();
    if (pos > 1) {
      if (a[pos - 1] < a[pos]) smt.update(1, 1, 1e6, a[pos - 1] + 1, a[pos], -1);
      if (a[pos - 1] < x) smt.update(1, 1, 1e6, a[pos - 1] + 1, x, 1);
    }
    if (pos < n) {
      if (a[pos] < a[pos + 1]) smt.update(1, 1, 1e6, a[pos] + 1, a[pos + 1], -1);
      if (x < a[pos + 1]) smt.update(1, 1, 1e6, x + 1, a[pos + 1], 1);
    }
    if (--cov[a[pos]] == 0) smt.update(1, 1, 1e6, a[pos], a[pos], inf);
    if (cov[x]++ == 0) smt.update(1, 1, 1e6, x, x, -inf);
    a[pos] = x;
    if (smt.minn[1]) puts("0");
    else printf("%d\n", smt.mcnt[1]); 
  }
  return 0;
}