/*
start thinking:
BULB:
result of thinking:

triedpxorx

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
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 150005
#define maxV 4500005
const int mod = 998244353;
int n, x, chi[maxV][2], V;
ll siz[maxV], pow2[maxn];

void ins(int a) {
  int u = 1;
  for (int i = 29; i >= 0; i--) {
    siz[u]++;
    int b = a >> i & 1;
    if (!chi[u][b])
      chi[u][b] = ++V;
    u = chi[u][b];
  }
  siz[u]++;
}

ll dfs(int u, int v, int hei) {
  if (!u || !v)
    return 0;
  if (!hei) {
    if (u == v)
      return pow2[siz[u]] - 1;
    return (pow2[siz[u]] - 1) * (pow2[siz[v]] - 1) % mod;
  }
  if (x >> (hei - 1) & 1) {
    if (u == v) {
      ll ans = dfs(chi[u][0], chi[u][1], hei - 1);
      (ans += pow2[siz[chi[u][0]]] - 1 + pow2[siz[chi[u][1]]] - 1) %= mod;
      return ans;
    }
    ll ans = 0, f1 = dfs(chi[u][0], chi[v][1], hei - 1),
                f2 = dfs(chi[u][1], chi[v][0], hei - 1);
    (ans += f1 * (pow2[siz[chi[u][1]]] + pow2[siz[chi[v][0]]] - 1)) %= mod;
    (ans += f2 * (pow2[siz[chi[u][0]]] + pow2[siz[chi[v][1]]] - 1)) %= mod;
    (ans += f1 * f2) %= mod;
    (ans += (pow2[siz[chi[u][0]]] - 1) * (pow2[siz[chi[v][0]]] - 1)) %= mod;
    (ans += (pow2[siz[chi[u][1]]] - 1) * (pow2[siz[chi[v][1]]] - 1)) %= mod;
    return ans;
  } else {
    return (dfs(chi[u][0], chi[v][0], hei - 1) + dfs(chi[u][1], chi[v][1], hei - 1))
              % mod;
  }
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d", &n, &x);
  V = 1;
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    ins(a);
  }
  pow2[0] = 1;
  for (int i = 1; i <= n; i++)
    pow2[i] = pow2[i - 1] * 2 % mod;
  printf("%lld\n", (dfs(1, 1, 30) + mod) % mod);
  return 0;
}