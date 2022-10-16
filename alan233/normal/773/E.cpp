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

const int N = 1000005;
const int V = 500005;

#define ls (u << 1)
#define rs (u << 1 | 1)
struct SMT1 {
  int maxx[N << 2], tag[N << 2];
  void pushup(int u) {
    maxx[u] = max(maxx[ls], maxx[rs]);
  }
  void pushtag(int u, int dlt) {
    maxx[u] += dlt, tag[u] += dlt;
  }
  void pushdown(int u) {
    if (tag[u])
      pushtag(ls, tag[u]), pushtag(rs, tag[u]), tag[u] = 0;
  }
  void build(int u, int l, int r) {
    if (l == r) {
      maxx[u] = l;
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
  int query(int u, int l, int r) {
    if (l == r) return l;
    pushdown(u);
    int mid = l + r >> 1;
    if (maxx[ls] >= 0) return query(ls, l, mid);
    else return query(rs, mid + 1, r);
  }
} smt1;

struct SMT2 {
  int minn[N << 2], tag[N << 2];
  void pushup(int u) {
    minn[u] = min(minn[ls], minn[rs]);
  }
  void pushtag(int u, int dlt) {
    minn[u] += dlt, tag[u] += dlt;
  }
  void pushdown(int u) {
    if (tag[u])
      pushtag(ls, tag[u]), pushtag(rs, tag[u]), tag[u] = 0;
  }
  void build(int u, int l, int r) {
    if (l == r) {
      minn[u] = l;
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
  int query(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return minn[u];
    pushdown(u);
    int mid = l + r >> 1, ret = 1e9;
    if (ql <= mid) ckmin(ret, query(ls, l, mid, ql, qr));
    if (qr > mid) ckmin(ret, query(rs, mid + 1, r, ql, qr));
    return ret;
  }
} smt2;

int main() {
  int n = read();
  smt1.build(1, -V, 0);
  smt2.build(1, -V, V);
  while (n--) {
    int x = read();
    if (x < 0) smt1.update(1, -V, 0, x, 0, 1);
    int pos = smt1.query(1, -V, 0);
//    printf("pos = %d\n", pos);
    smt2.update(1, -V, V, -V, x - 1, 1);
    print(smt2.query(1, -V, V, pos, V), '\n');
  }
  return 0;
}