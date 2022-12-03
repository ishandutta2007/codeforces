/*
start thinking:
BULB:
result of thinking:

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
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005
const int mod = 998244353;
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

int n;
struct Edge {
  int v, x, y;
};
vector<Edge> adj[maxn];
int r[maxn], cnt[maxn], mincnt[maxn];

vector<int> factorize(int x) {
  vector<int> res;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      while (x % i == 0) {
        res.push_back(i);
        x /= i;
      }
    }
  }
  if (x > 1)
    res.push_back(x);
  return res;
}

void dfs(int u, int f) {
  for (auto e : adj[u]) {
    if (e.v == f)
      continue;
    r[e.v] = (ll)r[u] * modpow(e.x, mod - 2) % mod * e.y % mod;
    auto xx = factorize(e.x);
    for (auto i : xx)
      chmin(mincnt[i], --cnt[i]);
    auto yy = factorize(e.y);
    for (auto i : yy)
      cnt[i]++;
    dfs(e.v, u);
    for (auto i : yy)
      cnt[i]--;
    for (auto i : xx)
      cnt[i]++;
  }
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    adj[i].clear();
  for (int i = 1; i < n; i++) {
    int u, v, x, y;
    scanf("%d%d%d%d", &u, &v, &x, &y);
    int d = __gcd(x, y);
    x /= d, y /= d;
    adj[u].push_back({v, x, y});
    adj[v].push_back({u, y, x});
  }
  r[1] = 1;
  dfs(1, 0);
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = -1; j >= mincnt[i]; j--) {
      ans = (ll)ans * i % mod;
    }
  }
  r[0] = 0;
  for (int i = 1; i <= n; i++)
    (r[0] += r[i]) %= mod;
  printf("%lld\n", ((ll)ans * r[0] % mod + mod) % mod);
  for (int i = 1; i <= n; i++)
    cnt[i] = mincnt[i] = 0;
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}