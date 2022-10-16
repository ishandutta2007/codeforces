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

const int N = 500005;
const int B = 197;
const int mod = 998244853;

struct node {
  int pre, suf, len;
} tr[N << 2];
int pw[N], a[N], n;

node operator + (node a, node b) {
  node c;
  c.len = a.len + b.len;
  c.pre = (a.pre + 1ll * pw[a.len] * b.pre) % mod;
  c.suf = (b.suf + 1ll * pw[b.len] * a.suf) % mod;
  return c;
}

struct SMT {
  #define ls (u << 1)
  #define rs (u << 1 | 1)
  void build(int u, int l, int r) {
    tr[u].len = r - l + 1;
    if (l == r) return ;
    int mid = l + r >> 1;
    build(ls, l, mid), build(rs, mid + 1, r);
  }
  void ins(int u, int l, int r, int pos) {
    if (l == r) {
      tr[u].pre = 1, tr[u].suf = 1;
      return ;
    }
    int mid = l + r >> 1;
    if (pos <= mid) ins(ls, l, mid, pos);
    else ins(rs, mid + 1, r, pos);
    tr[u] = tr[ls] + tr[rs];
  }
  node query(int u, int l, int r, int ql, int qr) {
    if (ql > qr) return {0, 0, 0};
    if (ql <= l && r <= qr) return tr[u];
    int mid = l + r >> 1;
    if (qr <= mid) return query(ls, l, mid, ql, qr);
    if (ql > mid) return query(rs, mid + 1, r, ql, qr);
    return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
  }
} smt;

int main() {
  pw[0] = 1;
  rep(i, 1, N - 1) pw[i] = 1ll * pw[i - 1] * B % mod;
  n = read();
  rep(i, 1, n) a[i] = read();
  smt.build(1, 1, n);
  rep(i, 1, n) {
    smt.ins(1, 1, n, a[i]);
    int len = min(a[i] - 1, n - a[i]);
    node L = smt.query(1, 1, n, a[i] - len, a[i] - 1);
    node R = smt.query(1, 1, n, a[i] + 1, a[i] + len);
//    printf("L.pre = %d, R.suf = %d\n", L.suf, R.pre);
    if (L.suf != R.pre) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}