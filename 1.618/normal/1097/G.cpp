/*
start thinking:
BULB:
result of thinking:

0, 1, ..., kO(nk^2)FFTnklogk,
.
: |S|^k -> Sk.
kk.
Stirlingk.
f(u, i): subtree(u)i, .

start coding:
AC:

PS. , https://codeforces.com/blog/entry/64367.
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

#define maxn 100005
#define maxk 205
const int mod = 1000000007;

// siz[u]: number of edges in subtree(u)
// f(u, i): subtree(u)i, , .
int n, k, siz[maxn], s2[maxk][maxk], fct[maxk], f[maxn][maxk], res[maxk];
vector<int> adj[maxn];

void dfs(int u, int p) {
  f[u][0] = 2;
  for (auto v : adj[u]) {
    if (v == p)
      continue;
    dfs(v, u);
    for (int i = min(k, siz[u]); i >= 0; i--) {
      for (int j = 1; j <= min(k - i, siz[v] + 1); j++) {
        f[u][i + j] = (f[u][i + j] + (ll)f[u][i] 
                        * (f[v][j] + f[v][j - 1] - (j == 1))) % mod;
      }
      f[u][i] = (ll)f[u][i] * f[v][0] % mod;
    }
    siz[u] += siz[v] + 1;
  }
  for (int i = 1; i <= min(siz[u], k); i++) {
    (res[i] += f[u][i]) %= mod;
    for (auto v : adj[u]) {
      if (v == p)
        continue;
      res[i] = ((ll)res[i] - f[v][i] - f[v][i - 1] + (i == 1)) % mod;
    }
  }
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  s2[0][0] = fct[0] = 1;
  for (int i = 1; i <= k; i++) {
    fct[i] = (ll)fct[i - 1] * i % mod;
    for (int j = 1; j <= k; j++)
      s2[i][j] = (s2[i - 1][j - 1] + (ll)j * s2[i - 1][j]) % mod;
  }
  dfs(1, 0);
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    ans = (ans + (ll)fct[i] * s2[k][i] % mod * res[i]) % mod;
  }
  printf("%d\n", (ans + mod) % mod);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}