/*
start thinking:
BULB:
result of thinking: Lost. dp.

cf.
rt.
, rtrt""rt.
""2^(-).
f(u, i): rtusubtree(u)i, subtree(u), .
-(u, v),
g(v, i): subtree(v)+(u, v), rtui, .

start coding: 13:00
AC: 

O(n^3).
*/
#include <bits/stdc++.h>
#define mp make_pair
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

#define maxn 55
int n, siz[maxn]; // siz[u]: subtree(u).
// f(u, i): rtusubtree(u)i, subtree(u), .
// -(u, v),
// g(v, i): subtree(v)+(u, v), rtui, .
ldouble f[maxn][maxn], g[maxn][maxn], fct[maxn];
vector<int> adj[maxn];

ldouble binom(int x, int y) {
  if (x < 0 || y < 0 || y > x)
    return 0;
  return fct[x] / fct[y] / fct[x - y];
}

void dfs(int u, int p) {
  f[u][0] = 1;
  for (auto v : adj[u]) {
    if (v == p)
      continue;
    dfs(v, u);
    siz[u] += siz[v] + 1;
    for (int i = siz[u]; i >= 0; i--) {
      f[u][i] = f[u][i] * g[v][0] * binom(siz[u] - i, siz[v] + 1);
      for (int j = 1; j <= min(i, siz[v] + 1); j++) {
        f[u][i] += f[u][i - j] * g[v][j] * binom(i, j)
                    * binom(siz[u] - i, siz[v] + 1 - j);
      }

      // cout << "f[" << u << "][" << i << "]: " << f[u][i] << endl;
      
    }

    // system("pause");

  }
  if (p) {
    for (int i = 0; i <= siz[u] + 1; i++) {
      g[u][i] = f[u][i] * (siz[u] - i + 1);
      for (int j = 0; j < i; j++)
        g[u][i] += f[u][j] / 2.0;

      // cout << "g[" << u << "][" << i << "]: " << g[u][i] << endl;

    }

    // system("pause");

  }
}

ldouble solve(int rt) {
  memset(siz, 0, sizeof(siz));
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  dfs(rt, 0);
  return f[rt][n - 1] / fct[n - 1];
}

bool Med;
int main() {
  fct[0] = 1;
  for (int i = 1; i <= 50; i++)
    fct[i] = fct[i - 1] * i;
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    printf("%.10Lf\n", solve(i));
  }
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}