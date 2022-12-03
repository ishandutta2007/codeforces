/*
start thinking: 9:00
BULB: 12:00
result of thinking: Pure.

DAG.

start coding: 12:30
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
int n, m, len[maxn], rlen[maxn];
// r := n - rlen[n] + 1.
// f(u, 0): (u - 1, u)[u - 1, n], u-1 -> r-1, u -> r , u <= r
// f(u, 1): (u - 1, u)[u - 1, n], u-1 -> r, u -> r-1 , u <= r
// rf(u, 0): (u, u + 1)[r - 1, u + 1], , u >= r - 1
// rf(u, 1): (u, u + 1)[r - 1, u + 1], , u >= r - 1
bool f[2][maxn], rf[2][maxn];
vector<int> adj[maxn], radj[maxn];

void solve() {
  memset(len, 0, sizeof(len));
  memset(rlen, 0, sizeof(rlen));
  memset(f, 0, sizeof(f));
  memset(rf, 0, sizeof(rf));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    radj[i].clear();
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (v == u + 1) {
      len[u] = rlen[v] = 1;
    } else {
      adj[u].push_back(v);
      radj[v].push_back(u);
    }
  }
  for (int i = n - 1; i >= 1; i--) {
    if (len[i])
      len[i] = len[i + 1] + 1;
  }
  for (int i = 2; i <= n; i++) {
    if (rlen[i])
      rlen[i] = rlen[i - 1] + 1;
  }
  for (int i = 1; i <= n; i++)
    len[i]++, rlen[i]++;
  if (len[1] == n) {
    printf("%lld\n", n * ll(n - 1) / 2);
    return;
  }
  f[0][n - rlen[n] + 1] = true;
  for (int i = n - rlen[n]; i > 1; i--) {
    for (auto v : adj[i - 1]) {
      if (len[i] >= v - i) {
        f[0][i] |= f[1][v];
        f[1][i] |= f[0][v];
      }
    }
  }
  rf[0][n - rlen[n]] = true;
  for (int i = n - rlen[n] + 1; i < n; i++) {
    for (auto v : radj[i + 1]) {
      if (rlen[i] >= i - v) {
        rf[0][i] |= rf[1][v];
        rf[1][i] |= rf[0][v];
      }
    }
  }
  ll ans = 0, foo[3] = {0, 0, 0}, bar[3] = {0, 0, 0};
  for (int i = len[1] + 1; i > 1; i--) {
    foo[0] += f[0][i];
    foo[1] += f[1][i];
    foo[2] += f[0][i] & f[1][i];
  }
  for (int i = n - rlen[n]; i < n; i++) {
    bar[0] += rf[0][i];
    bar[1] += rf[1][i];
    bar[2] += rf[0][i] & rf[1][i];
  }
  ans += foo[0] * bar[0] + foo[1] * bar[1] - foo[2] * bar[2];

  // for (int i = n - rlen[n]; i < n; i++) {
  //   cout << rf[0][i] << " " << rf[1][i] << endl;
  // }
  // cout << foo << " " << bar << endl;
  // system("pause");

  ans += (bool)ans;
  ans -= len[1] + rlen[n] == n;
        
  // cout << ans << endl;
  // system("pause");

  memset(rf, 0, sizeof(rf));
  rf[0][len[1]] = true;
  for (int i = len[1] + 1; i < n; i++) {
    for (auto v : radj[i + 1]) {
      if (rlen[i] >= i - v) {
        rf[0][i] |= rf[1][v];
        rf[1][i] |= rf[0][v];
      }
    }
  }
  if (adj[n - rlen[n]].size()) {
    for (int i = len[1] + 1; i > 1; i--)
      ans += f[1][i] | f[0][i];
  } else {
    for (int i = len[1] + 1; i > 1; i--)
      ans += f[1][i];
  }
  if (radj[len[1] + 1].size()) {
    for (int i = n - rlen[n]; i < n; i++)
      ans += rf[0][i] | rf[1][i];
  } else {
    for (int i = n - rlen[n]; i < n; i++)
      ans += rf[1][i];
  }
  printf("%lld\n", ans);
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
/*
1
4 4
1 3
1 4
2 3
3 4
*/