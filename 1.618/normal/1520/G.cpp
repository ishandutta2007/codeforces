/*


Q.E.D.
*/
/*
BULB: Instant.
result of thinking: Pure.

1: >=2.
 
start coding: 14:17
AC:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 2005
#define mp make_pair
const ll infll = 0x3f3f3f3f3f3f3f3f;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
typedef pair<int, int> P;

int n, m, w, a[maxn][maxn];
ll ds[maxn][maxn], dt[maxn][maxn];

void bfs(ll d[maxn][maxn], int sx, int sy) {
  d[sx][sy] = 0;
  queue<P> que;
  que.push(mp(sx, sy));
  while (!que.empty()) {
    P p = que.front(); que.pop();
    int x = p.first, y = p.second;
    for (int dir = 0; dir < 4; dir++) {
      int cx = x + dx[dir], cy = y + dy[dir];
      if (cx >= 1 && cx <= n && cy >= 1 && cy <= m && 
          a[cx][cy] >= 0 && d[cx][cy] > d[x][y] + w) {
        d[cx][cy] = d[x][y] + w;
        que.push(mp(cx, cy));
      }
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &w);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  memset(ds, 0x3f, sizeof(ds));
  bfs(ds, 1, 1);
  memset(dt, 0x3f, sizeof(dt));
  bfs(dt, n, m);
  ll ans = ds[n][m], ans1 = infll, ans2 = infll;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] > 0) {
        chmin(ans1, a[i][j] + ds[i][j]);
        chmin(ans2, a[i][j] + dt[i][j]);
      }
    }
  }
  chmin(ans, ans1 + ans2);
  printf("%lld\n", ans < infll ? ans : -1);
  return 0;
}