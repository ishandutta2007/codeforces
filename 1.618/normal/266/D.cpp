/*
CF 266D.
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

#define maxn 205
// rk[u][i]: ui.
int n, m, d[maxn][maxn], rk[maxn][maxn];
struct Edge {
  int u, v, w;
} el[20005];

int main() {
  memset(d, 0x3f, sizeof(d));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &el[i].u, &el[i].v, &el[i].w);
    d[el[i].u][el[i].v] = d[el[i].v][el[i].u] = el[i].w;
  }
  for (int i = 1; i <= n; i++)
    d[i][i] = 0;
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        chmin(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      rk[i][j] = j;
    sort(rk[i] + 1, rk[i] + n + 1, [&](int x, int y) { return d[i][x] < d[i][y]; });
  }
  int ans = inf;
  for (int i = 1; i <= n; i++)
    chmin(ans, d[i][rk[i][n]] * 2);
  for (int i = 1; i <= m; i++) {
    for (int j = n - 1, p = rk[el[i].u][n]; j >= 1; j--) {
      if (d[el[i].v][rk[el[i].u][j]] > d[el[i].v][p]) {
        chmin(ans, d[el[i].u][rk[el[i].u][j]] + d[el[i].v][p] + el[i].w);
        p = rk[el[i].u][j];
      }
    }
  }
  printf("%.2f\n", ans / 2.0);
  return 0;
}