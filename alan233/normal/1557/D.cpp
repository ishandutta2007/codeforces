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

vector<pii> vec[N];
int tmp[N], len;
int n, m;

pii dp[N];

#define ls (u << 1)
#define rs (u << 1 | 1)
pii lazy[N << 2], maxx[N << 2];
void pushup(int u) { maxx[u] = max(maxx[ls], maxx[rs]); }
void pushtag(int u, pii x) {
  ckmax(maxx[u], x), ckmax(lazy[u], x);
}
void pushdown(int u) {
  if (lazy[u] != make_pair(0, 0)) {
    pushtag(ls, lazy[u]), pushtag(rs, lazy[u]);
    lazy[u] = make_pair(0, 0);
  }
}
void update(int u, int l, int r, int ql, int qr, pii x) {
  if (ql <= l && r <= qr) {
    pushtag(u, x);
    return ;
  }
  pushdown(u);
  int mid = l + r >> 1;
  if (ql <= mid) update(ls, l, mid, ql, qr, x);
  if (qr > mid) update(rs, mid + 1, r, ql, qr, x);
  pushup(u);
} 
pii query(int u, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return maxx[u];
  pushdown(u);
  int mid = l + r >> 1;
  pii ret = make_pair(0, 0);
  if (ql <= mid) ckmax(ret, query(ls, l, mid, ql, qr));
  if (qr > mid) ckmax(ret, query(rs, mid + 1, r, ql, qr));
  return ret;
}

bool ban[N];

int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int line = read(), l = read(), r = read();
    vec[line].pb({l, r});
    tmp[++len] = l, tmp[++len] = r;
  }
  sort(tmp + 1, tmp + len + 1);
  len = unique(tmp + 1, tmp + len + 1) - tmp - 1;
  for (int i = 1; i <= n; i++) {
    for (auto &v: vec[i]) {
      v.fir = lower_bound(tmp + 1, tmp + len + 1, v.fir) - tmp;
      v.sec = lower_bound(tmp + 1, tmp + len + 1, v.sec) - tmp; 
    }
  }
  pii ans = make_pair(0, 0);
  for (int i = 1; i <= n; i++) {
    pii qwq = make_pair(0, 0);
    for (auto v: vec[i]) {
      ckmax(qwq, query(1, 1, len, v.fir, v.sec));
    }
    dp[i] = qwq; dp[i].fir++;
    ckmax(ans, make_pair(dp[i].fir, i));
    for (auto v: vec[i]) {
      update(1, 1, len, v.fir, v.sec, make_pair(dp[i].fir, i));
    }
  }
  printf("%d\n", n - ans.fir);
  if (n - ans.fir == 0) {
    return 0;
  }
  for (int x = ans.sec; x; x = dp[x].sec) {
    ban[x] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (!ban[i]) printf("%d ", i);
  }
  puts("");
  return 0;
}