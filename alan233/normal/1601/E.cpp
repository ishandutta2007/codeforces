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
int a[N];
int n, q, k;

int val[N]; // min(a[i-k] ... a[i])
void calc() {
  static int q[N], ql, qr;
  ql = 1, qr = 0;
  for (int i = 1; i <= n; i++) {
    while (ql <= qr && a[q[qr]] > a[i]) --qr;
    while (ql <= qr && i - q[ql] > k) ++ql;
    q[++qr] = i;
    val[i] = a[q[ql]];
    // printf("val[%d] = %d\n", i, val[i]); 
  }
}

ll ans[N];
int pos[N], len;

#define ls (u << 1)
#define rs (u << 1 | 1)
ll sum[N << 2];
int cov[N << 2];
void pushup(int u) {
  sum[u] = sum[ls] + sum[rs];
}
void pushcov(int u, int l, int r, int num) {
  cov[u] = num;
  sum[u] = 1ll * (r - l + 1) * num;
}
void pushdown(int u, int l, int r) {
  if (cov[u] != -1) {
    int mid = l + r >> 1;
    pushcov(ls, l, mid, cov[u]);
    pushcov(rs, mid + 1, r, cov[u]);
    cov[u] = -1;
  }
}
void build(int u, int l, int r) {
  cov[u] = -1;
  if (l == r) {
    sum[u] = a[pos[l]];
    return ;
  }
  int mid = l + r >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(u);
}
void update(int u, int l, int r, int ql, int qr, int num) {
  if (ql <= l && r <= qr) {
    pushcov(u, l, r, num);
    return ;
  } 
  pushdown(u, l, r);
  int mid = l + r >> 1;
  if (ql <= mid) update(ls, l, mid, ql, qr, num);
  if (qr > mid) update(rs, mid + 1, r, ql, qr, num);
  pushup(u);
}
ll query(int u, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return sum[u];
  pushdown(u, l, r);
  int mid = l + r >> 1; ll res = 0;
  if (ql <= mid) res += query(ls, l, mid, ql, qr);
  if (qr > mid) res += query(rs, mid + 1, r, ql, qr);
  return res;
}

int main() {
  n = read(), q = read(), k = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= q; i++) {
    int l = read(), r = read();
    ask[l].pb({r, i});
  }
  calc();
  for (int re = 1; re <= k; re++) {
    static int stk[N], top;
    len = 0, top = 0;
    for (int i = re; i <= n; i += k)
      pos[++len] = i;
    build(1, 1, len);
    for (int i = len; i >= 1; i--) {
      int u = pos[i];
      for (auto [r, id]: ask[u]) {
        ans[id] = a[u] + query(1, 1, len, i + 1, (r - re) / k + 1);
      }
      while (top && val[pos[i]] < val[pos[stk[top]]]) --top;
      if (top) update(1, 1, len, i, stk[top] - 1, val[pos[i]]);
      else update(1, 1, len, i, len, val[pos[i]]);
      stk[++top] = i;
    }
  }
  for (int i = 1; i <= q; i++) print(ans[i], '\n');
  return 0;
}