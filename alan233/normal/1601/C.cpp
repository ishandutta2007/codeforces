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

const int N = 2000005;

struct Info {
  int val, pos, type;
  friend bool operator < (const Info &a, const Info &b) {
    if (a.val != b.val) return a.val < b.val;
    else return a.type > b.type;
  }
} c[N];

int a[N], b[N];
int len;
int n, m;

#define ls (u << 1)
#define rs (u << 1 | 1)

int minn[N << 2], tag[N << 2];

void pushup(int u) {
  minn[u] = min(minn[ls], minn[rs]);
}
void pushtag(int u, int dlt) {
  tag[u] += dlt;
  minn[u] += dlt;
}
void pushdown(int u) {
  if (tag[u])
    pushtag(ls, tag[u]), pushtag(rs, tag[u]), tag[u] = 0;
}
void build(int u, int l, int r) {
  tag[u] = 0;
  if (l == r) {
    minn[u] = l - 1;
    return ;
  }
  int mid = l + r >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
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

struct Fenwick {
  int c[N];
  void ini(int n) {
    memset(c, 0, sizeof(int) * (n + 1));
  }
  void add(int x, int dlt) {
    while (x <= n) {
      c[x] += dlt;
      x += x & -x;
    }
  }
  int qry(int x) {
    int ret = 0;
    while (x) {
      ret += c[x];
      x ^= x & -x;
    }
    return ret;
  }
} fen;
ll gao() {
  static int lsh[N];
  fen.ini(n);
  ll ans = 0;
  for (int i = 1; i <= n; i++) lsh[i] = a[i];
  sort(lsh + 1, lsh + n + 1);
  for (int i = 1; i <= n; i++) {
    int who = lower_bound(lsh + 1, lsh + n + 1, a[i]) - lsh;
    ans += i - 1 - fen.qry(who);
    fen.add(who, 1);
  }
  return ans;
}

void solve() {
  n = read(), m = read();
  len = 0;
  rep(i, 1, n) a[i] = read(), c[++len] = {a[i], i, 0};
  rep(i, 1, m) b[i] = read(), c[++len] = {b[i], i, 1};
  sort(c + 1, c + len + 1);
  // for (int i = 1; i <= len; i++) {
    // printf("[debug] %d %d %d\n", c[i].val, c[i].pos, c[i].type);
  // }
  build(1, 1, n + 1);
  ll ans = gao();
  // printf("ini ans = %lld\n", ans);
  for (int i = 1; i <= len; i++) {
    int j = i;
    while (j < len && c[j + 1].val == c[i].val) ++j;
    for (int k = i; k <= j; k++) {
      if (c[k].type == 0) { // a
        update(1, 1, n + 1, c[k].pos + 1, n + 1, -1);
      }
    }
    for (int k = i; k <= j; k++) {
      if (c[k].type == 1) { // b
        // printf("deal b[%d], ans = %d\n", c[k].pos, minn[1]);
        ans += minn[1];
      }
    }
    for (int k = i; k <= j; k++) {
      if (c[k].type == 0) { // a
        update(1, 1, n + 1, 1, c[k].pos, 1);
      }
    }
    i = j;
  }
  print(ans, '\n');
}

int main() {
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}