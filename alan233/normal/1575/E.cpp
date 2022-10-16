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

const int N = 200005;
const int mod = 1e9 + 7;
const int inf = 1e9;

inline void add(int &x, int y) {
  x += y; if (x >= mod) x -= mod;
}
inline void sub(int &x, int y) {
  x -= y; if (x < 0) x += mod;
}

vector<pii> adj[N];
int a[N], n, LIM;

bool ban[N]; int sz[N], maxp[N], sumsz, rt;
void getrt(int u, int fa) {
  maxp[u] = 0, sz[u] = 1;
  for (auto v: adj[u]) {
    if (ban[v.fir] || v.fir == fa) continue;
    getrt(v.fir, u);
    sz[u] += sz[v.fir];
    ckmax(maxp[u], sz[v.fir]);
  }
  ckmax(maxp[u], sumsz - sz[u]);
  if (maxp[u] < maxp[rt]) rt = u;
}

vector<pii> tmp, tmq[2]; // (, )
int ans;

void dfs1(int u, int fa, int lst, int turns, int sum) {
  sum = (sum + a[u]) % mod;
  tmp.pb({turns, sum});
  for (auto v: adj[u]) {
    if (ban[v.fir] || v.fir == fa) continue;
    dfs1(v.fir, u, v.sec, turns + (lst != v.sec), sum);
  }
}
int calc1(vector<pii> x) {
  static int zz[N];
//  printf("calc1 in\n");
  int n = SZ(x), res = 0;
  for (int i = 0; i < n; i++) zz[i] = x[i].sec;
  for (int i = 1; i < n; i++) add(x[i].sec, x[i - 1].sec);
  for (int i = 0; i < n; i++) {
    int t = upper_bound(x.begin(), x.end(), make_pair(LIM - x[i].fir, mod)) - x.begin() - 1;
    ckmin(t, i - 1);
//    printf("i = %d, t = %d\n", i, t);
    if (t >= 0) add(res, (x[t].sec + 1ll * (t + 1) * (zz[i] + a[rt])) % mod);
  }
//  printf("calc1 out\n");
  return res;
}
int calc2(vector<pii> x, vector<pii> y) {
//  printf("calc2 in\n");
  int n = SZ(x), m = SZ(y), res = 0;
  for (int i = 1; i < n; i++) add(x[i].sec, x[i - 1].sec);
  for (int i = 0; i < m; i++) {
    int t = upper_bound(x.begin(), x.end(), make_pair(LIM - y[i].fir - 1, mod)) - x.begin() - 1;
    if (t >= 0) add(res, (x[t].sec + 1ll * (t + 1) * (y[i].sec + a[rt])) % mod);
  }
//  printf("calc2 out\n");
  return res;
}
void calc_in(int u) { //  
  sort(tmp.begin(), tmp.end());
  for (auto v: tmp) if (v.fir <= LIM) add(ans, (v.sec + a[u]) % mod);
  sub(ans, calc1(tmp));
}

void dfz(int u) {
//  assert(rt == u);
//  printf("dfz %d\n", u);
//  system("pause");
  ban[u] = 1;
  tmq[0].clear(), tmq[1].clear();
  add(ans, a[u]);
  for (auto v: adj[u]) {
    if (!ban[v.fir]) {
//      printf("dfs %d\n", v.fir);
      tmp.clear(); dfs1(v.fir, u, v.sec, 0, 0);
//      printf("dfs ok!\n");
//      for (auto it: tmp) printf("(%d, %d)\n", it.fir, it.sec);
      for (auto it: tmp) tmq[v.sec].pb(it);
      calc_in(u);
//      printf("after dfs %d, ans = %d\n", v.fir, ans);
    }
  }
//  printf("now !\n");
  sort(tmq[0].begin(), tmq[0].end());
  sort(tmq[1].begin(), tmq[1].end());
//  printf("tmq[0] = "); for (auto it: tmq[0]) printf("(%d, %d), ", it.fir, it.sec); puts("");
//  printf("tmq[1] = "); for (auto it: tmq[1]) printf("(%d, %d), ", it.fir, it.sec); puts("");
  add(ans, calc1(tmq[0]));
//  printf(">>>>>> fuck!!!\n");
  add(ans, calc1(tmq[1]));
  add(ans, calc2(tmq[0], tmq[1]));
//  printf("%d\n", ans);
//  printf("now !!\n");
  for (auto v: adj[u]) {
    if (!ban[v.fir]) {
      rt = 0, sumsz = sz[v.fir], getrt(v.fir, 0);
      dfz(rt);
    }
  }
}

int main() {
  n = read(), LIM = read();
  rep(i, 1, n) a[i] = read();
  rep(i, 1, n - 1) {
    int u = read(), v = read(), w = read();
    adj[u].pb({v, w}), adj[v].pb({u, w});
  }
  maxp[rt = 0] = n, sumsz = n, getrt(1, 0);
  dfz(rt);
  print(ans, '\n');
  return 0;
} 

/*
3 0
1 1 1
1 2 1
3 2 0
*/