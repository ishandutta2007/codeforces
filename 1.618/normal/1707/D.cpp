/*
start thinking:
BULB:
result of thinking: Pure.

f(u, k): k  u  u , 
g(u, k): k  u  u , 
h(u, k): k  ( par(u) -  u)  par(u) , 

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 2005
int n, mod, ans[maxn], c[maxn][maxn];
vector<int> adj[maxn];
 
int modpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1)
      res = (ll)res * x % mod;
    y >>= 1;
    x = (ll)x * x % mod;
  }
  return res;
}
int inv(int x) { return modpow(x, mod - 2); }

// f(u, k): k  u  u , 
// g(u, k): k  u  u , 
// h(u, k): k  ( par(u) -  u)  par(u) , 
int k, f[maxn][maxn], g[maxn][maxn], h[maxn][maxn];
int sf[maxn][maxn], sg[maxn][maxn], sh[maxn][maxn];

void dfs(int u, int p) {
  static int pre[maxn], suf[maxn];
  for (int i = 0; i < (int)adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == p) {
      pre[i + 1] = pre[i];
      continue;
    }
    dfs(v, u);
    g[u][k] = (g[u][k] + ll(f[v][k] + g[v][k]) * sh[v][k - 1]) % mod;
  }
  pre[0] = suf[adj[u].size()] = 1;
  for (int i = 0; i < (int)adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == p) {
      pre[i + 1] = pre[i];
    } else {
      pre[i + 1] = (ll)pre[i] * (sf[v][k] + sg[v][k]) % mod;
    }
  }
  for (int i = adj[u].size() - 1; i >= 0; i--) {
    int v = adj[u][i];
    if (v == p) {
      suf[i] = suf[i + 1];
    } else {
      suf[i] = (ll)suf[i + 1] * (sf[v][k] + sg[v][k]) % mod;
    }
  }
  f[u][k] = pre[adj[u].size()];
  sf[u][k] = (sf[u][k - 1] + f[u][k]) % mod;
  sg[u][k] = (sg[u][k - 1] + g[u][k]) % mod;
  for (int i = 0; i < (int)adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == p)
      continue;
    h[v][k] = (ll)pre[i] * suf[i + 1] % mod;
    sh[v][k] = (sh[v][k - 1] + h[v][k]) % mod;
  }
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d", &n, &mod);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
  }
  for (int i = 1; i <= n; i++)
    sf[i][0] = f[i][0] = 1;
  for (int i = 2; i <= n; i++)
    sh[i][0] = h[i][0] = 1;
  ans[1] = 1;
  for (k = 1; k < n - 1; k++) {
    dfs(1, 0);
    ans[k + 1] = f[1][k];
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      ans[i] = (ans[i] - (ll)ans[j] * c[i][j]) % mod;
    }
  }
  for (int i = 1; i < n; i++) {
    printf("%d%c", (ans[i] + mod) % mod, " \n"[i == n - 1]);
  }
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}