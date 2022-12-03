/*
start thinking:
BULB:
result of thinking:

: , : .
 sum_{r=1}^n rforum.
(xiaoyaowudi)[http://www.nfls.com.cn:10688/contest/467/problem/1].

start coding:
AC:
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

#define maxn 305
const int mod = 998244353;
const int inv2 = 499122177;
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

int n, r;
vector<int> adj[maxn];
// f[u][x][0/1]: d[u] = x, son(u)d[v] = d[u] - 1, d[subtree(u)].
ll f[maxn][maxn][2];

void dfs(int u, int p) {
  for (int i = 0; i <= r; i++)
    f[u][i][0] = 1;
  for (auto v : adj[u]) {
    if (v == p)
      continue;
    dfs(v, u);
    memset(f[0], 0, sizeof(f[0]));
    for (int i = 0; i <= r; i++) {
      for (int j = max(0, i - 1); j <= min(r, i + 1); j++) {
        (f[0][i][i - 1 == j] += f[u][i][0] * f[v][j][1]) %= mod;
        (f[0][i][1] += f[u][i][1] * f[v][j][1]) %= mod;
        if (!j || j - 1 == i) {
          (f[0][i][i - 1 == j] += f[u][i][0] * f[v][j][0]) %= mod;
          (f[0][i][1] += f[u][i][1] * f[v][j][0]) %= mod;
        }
      }
    }
    memcpy(f[u], f[0], sizeof(f[0]));
  }
}

// rforum (i.e. d <= r) .
int solve() {
  memset(f, 0, sizeof(f));
  dfs(1, 0);
  int ans = 0;
  for (int i = 0; i <= r; i++)
    (ans += f[1][i][i >= 1]) %= mod;
  return ans;
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ans = -1;
  for (r = 0; r < n; r++)
    (ans += solve()) %= mod;
  ans = ((n - 1) - (ll)ans * modpow(inv2, n)) % mod;
  printf("%d\n", (ans + mod) % mod);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}