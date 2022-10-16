// Author: wlzhouzhuan
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

const int N = 100005;
const int M = 200 * N;
const int inf = 1e9;

int L[N], R[N];
int n, m;

struct node { int x, y, id; };
vector<node> vec[N];

int rt[N << 2], ls[M], rs[M], minn[M], seg_tot;
void ins(int &u, int l, int r, int y, int z) {
  if (!u) u = ++seg_tot, minn[u] = inf;
  ckmin(minn[u], z);
  if (l == r) return ;
  int mid = l + r >> 1;
  if (y <= mid) ins(ls[u], l, mid, y, z);
  else ins(rs[u], mid + 1, r, y, z);
}
void ins(int u, int l, int r, int x, int y, int z) {
  ins(rt[u], 1, n, y, z);
  if (l == r) return ;
  int mid = l + r >> 1;
  if (x <= mid) ins(2 * u, l, mid, x, y, z);
  else ins(2 * u + 1, mid + 1, r, x, y, z);
}
int qry(int u, int l, int r, int ql, int qr) {
  if (!u || qr < l || ql > r || ql > qr) return inf;
  if (ql <= l && r <= qr) return minn[u];
  int mid = l + r >> 1;
  return min(qry(ls[u], l, mid, ql, qr), qry(rs[u], mid + 1, r, ql, qr));
}
int query(int u, int l, int r, int ql, int qr) {
  if (qr < l || ql > r || ql > qr) return inf;
  if (ql <= l && r <= qr) return qry(rt[u], 1, n, ql, qr);
  int mid = l + r >> 1;
  return min(query(2 * u, l, mid, ql, qr), query(2 * u + 1, mid + 1, r, ql, qr));
}

int ans[N];
queue<node> q;
void add(int l, int r) {
  if (l <= r) {
    int t = query(1, 1, n, l, r);
    if (t != inf) q.push({l, r, t});
  }
}
int solve() {
//  printf("solve!\n"); 
  add(1, n);
  int len = 0;
  while (!q.empty()) {
    node u = q.front(); q.pop();
//    printf("%d %d %d\n", u.x, u.y, u.id); 
    len += R[u.id] - L[u.id] + 1;
    add(u.x, L[u.id] - 1);
    add(R[u.id] + 1, u.y);
  }
  return len;
}
int main() {
  n = read(), m = read();
  rep(i, 1, m) {
    int l = read(), r = read();
    L[i] = l, R[i] = r;
    vec[r - l + 1].pb({l, r, i});
  }
  per(i, n, 1) {
    for (auto v: vec[i]) ins(1, 1, n, v.x, v.y, v.id);
    ans[i] = solve();
  }
  rep(i, 1, n) print(ans[i], '\n');
  return 0;
}