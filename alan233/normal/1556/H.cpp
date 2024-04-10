// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
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

const int N = 55;
const int inf = 1e9;

int e[N][N], U[N * N], V[N * N], W[N * N], tot, S, T;
int n, k;

struct M1 {
  int f[N];
  inline void init() { iota(f + 1, f + n + 1, 1); }
  int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
  inline void merge(int x, int y) {
    x = find(x), y = find(y);
    f[x] = y;
  }
  inline bool check(int x, int y) {
    return find(x) != find(y);
  }
} m1, mm1;
struct M2 {
  int lim[N], deg[N];
  inline void merge(int x, int y) {
    deg[x]++, deg[y]++;
  }
  inline bool check(int x, int y) {
    return deg[x] != lim[x] && deg[y] != lim[y];
  }
} im2, m2, mm2;

vector<int> adj[N * N];
bool in[N * N];

int dis[N * N], cnt[N * N], inq[N * N], pre[N * N];
inline int calc(int x) {
  if (x > tot) return 0;
  return in[x] ? -W[x] : W[x];
}
int q[1848576], ql, qr;
inline int Aug() {
  rep(i, 1, tot + 2) adj[i].clear();
  mm1 = m1, mm2 = m2;
  rep(i, 1, tot) if (in[i]) mm1.merge(U[i], V[i]), mm2.merge(U[i], V[i]); 
  rep(i, 1, tot) if (!in[i]) {
    if (mm1.check(U[i], V[i])) adj[S].pb(i);
    if (mm2.check(U[i], V[i])) adj[i].pb(T);
  }
  rep(i, 1, tot) if (in[i]) {
    mm1 = m1; mm2 = m2;
    rep(j, 1, tot) if (in[j] && i != j) mm1.merge(U[j], V[j]), mm2.merge(U[j], V[j]);
    rep(j, 1, tot) if (!in[j]) {
      if (mm1.check(U[j], V[j])) adj[i].pb(j);
      if (mm2.check(U[j], V[j])) adj[j].pb(i); //!!!
    }
  }
  /*
  cerr << "Aug edge!\n";
  rep(i, 1, tot + 2) {
    printf("i = %d: ", i);
    for (auto v: adj[i]) printf("%d ", v);
    puts("");
  }
  printf("S = %d, T = %d\n", S, T); 
  */
  rep(i, 1, tot + 2) dis[i] = inf, cnt[i] = inq[i] = pre[i] = 0;
  ql = 0, qr = 0;
  dis[S] = 0, q[qr++] = S;
  while (ql != qr) {
    int u = q[ql++];
    inq[u] = 0;
    for (auto v: adj[u]) {
      int new_dis = dis[u] + calc(v);
      if (dis[v] > new_dis || (dis[v] == new_dis && cnt[v] > cnt[u] + 1)) {
        dis[v] = new_dis, cnt[v] = cnt[u] + 1, pre[v] = u;
        if (!inq[v]) inq[v] = 1, q[qr++] = v;
      }
    }
  }
//  cerr << "spfa ok!\n";
  if (dis[T] == inf) return inf; // 
//  cerr << dis[T] << ' ' << pre[T] << '\n';
  for (int i = pre[T]; i != S; i = pre[i]) {
//    printf("i = %d\n", i);
//    system("pause");
    in[i] ^= 1;
  }
//  rep(i, 1, tot) printf("%d ", in[i]);
//  puts("");
  return dis[T];
}

int main() {
  n = read(), k = read();
  rep(i, 1, n) im2.lim[i] = (i <= k ? read() : inf);
  rep(i, 1, n) rep(j, i + 1, n) e[i][j] = e[j][i] = read();
  rep(i, 1, n) rep(j, max(i + 1, k + 1), n) {
    ++tot;
    U[tot] = i, V[tot] = j, W[tot] = e[i][j];
  }
  S = tot + 1, T = tot + 2;
  int all = 1 << k * (k - 1) / 2, ans = 1e9;
  rep(st, 0, all - 1) {
    m1.init(), m2 = im2;
    rep(i, 1, tot) in[i] = 0; 
    int ind = 0, ok = 1;
    int res = 0;
    rep(i, 1, k) rep(j, i + 1, k) if (st >> ind++ & 1) {
      ok &= m1.check(i, j) & m2.check(i, j);
      m1.merge(i, j), m2.merge(i, j);
      res += e[i][j];
    }
    if (!ok) continue;
//    cerr << "!\n";
    int zz = n - 1 - __builtin_popcount(st);
    rep(turns, 1, zz) {
      int t = Aug();
//      printf("turns = %d, t = %d\n", turns, t);
      if (t == inf) { ok = 0; break; }
      res += t; 
    }
    if (ok) {
//      printf("states = %d, ok!\n", st);
//      rep(i, 1, tot) printf("%d ", in[i]);puts("");
//      res = 0;
//      rep(i, 1, tot) if (in[i]) res += W[i]; 
      ckmin(ans, res);
    }
  }
  print(ans, '\n');
  return 0;
}