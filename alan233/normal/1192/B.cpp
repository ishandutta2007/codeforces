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
ll read() {
  ll x = 0, f = 0; char ch = getchar();
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

vector<pair<int, ll>> adj[N];
int seq[N], len, n, q;
ll dis[N], _u[N], _v[N], _w[N]; 

int in[N], out[N];
void dfs1(int u, int fa) {
  seq[++len] = u;
  in[u] = len;
  for (auto [v, w]: adj[u]) {
    if (v == fa) continue;
    dis[v] = dis[u] + w; 
    dfs1(v, u);
    seq[++len] = u;
  }
  out[u] = len;
}

#define ls (u << 1)
#define rs (u << 1 | 1)
ll a[N << 2], b[N << 2], c[N << 2], ab[N << 2], bc[N << 2], abc[N << 2], lazy[N << 2];
void pushup(int u) {
  a[u] = max(a[ls], a[rs]);
  b[u] = max(b[ls], b[rs]);
  c[u] = max(c[ls], c[rs]);
  ab[u] = max({ab[ls], ab[rs], a[ls] + b[rs]});
  bc[u] = max({bc[ls], bc[rs], b[ls] + c[rs]});
  abc[u] = max({abc[ls], abc[rs], a[ls] + bc[rs], ab[ls] + c[rs]});
}
void pushtag(int u, ll dlt) {
  a[u] += dlt;
  b[u] -= 2 * dlt;
  c[u] += dlt;
  ab[u] -= dlt;
  bc[u] -= dlt;
  lazy[u] += dlt;
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
    a[u] = dis[seq[l]];
    b[u] = -2 * dis[seq[l]];
    c[u] = dis[seq[l]];
    ab[u] = -dis[seq[l]];
    bc[u] = -dis[seq[l]];
    abc[u] = 0;
    return ;
  }
  int mid = l + r >> 1;
  build(ls, l, mid), build(rs, mid + 1, r);
  pushup(u);
}
void update(int u, int l, int r, int ql, int qr, ll dlt) {
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

int main() {
  n = read(), q = read();
  ll lim = read();
  rep(i, 1, n - 1) {
    int u = read(), v = read(); ll w = read();
    adj[u].pb({v, w}), adj[v].pb({u, w});
    _u[i] = u, _v[i] = v, _w[i] = w;
  } 
  dfs1(1, 0);
  // for (int i = 1; i <= len; i++) {
  //   printf("seq[%d] = %d\n", i, seq[i]);
  // }
  rep(i, 1, n - 1) {
    if (dis[_u[i]] > dis[_v[i]]) swap(_u[i], _v[i]);
    // printf("edge %d: %d %d\n", i, _u[i], _v[i]);
  }
  build(1, 1, len);
  ll last = 0;
  while (q--) {
    ll id = (read() + last) % (n - 1) + 1;
    ll e = (read() + last) % lim;
    // printf("update [%d, %d]\n", in[_v[id]], out[_v[id]]);
    update(1, 1, len, in[_v[id]], out[_v[id]], e - _w[id]);
    _w[id] = e;
    print(last = abc[1], '\n');
  }
  return 0;
}