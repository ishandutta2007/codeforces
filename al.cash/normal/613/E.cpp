#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), b_(b); i >= b_; --i)

const int mod = 1e9+7;
void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }
void dec(int &x, int y) { x -= y; if (x < 0) x += mod; }

const int N = 2001;
int n, m;
char a[2][N], w[N];
int c[2][N][N], cr[2][N][N];

void calcc(int u, int c[N][N]) {
  FORD(i, n-1, 0) FORD(j, m-1, 0)
    c[i][j] = a[u][i] == w[j] ? 1 + c[i+1][j+1] : 0;
}

int d[2][N][N];

int solve(bool first) {
  int ans = 0;
  memset(d, 0, sizeof d);
  REP(i, n) {
    d[0][i][0] = d[1][i][0] = 1;
    REP(u, 2) FOR(j, 2, min(n-i, m/2)+1)
    if (c[u][i][m-2*j] >= j && cr[u^1][i][0] >= j)
      if (2*j < m || first) inc(ans, d[u][i][m-2*j]);

    REP(u, 2) REP(j, m) if (a[u][i] == w[j]) {
      inc(d[u][i+1][j+1], d[u][i][j]);
      if (j+1 < m && a[u^1][i] == w[j+1])
        inc(d[u^1][i+1][j+2], d[u][i][j]);
    }

    REP(u, 2) FOR(j, 2, min(i+1, m/2)+1) {
      int l = i-j+1;
      if (c[u][l][j] >= j && cr[u^1][l][m-j] >= j)
        if (2*j < m || first) inc(d[u][i+1][2*j], 1);
    }
    REP(u, 2) inc(ans, d[u][i+1][m]);
  }
  return ans;
}

int main() {
  scanf("%s%s%s", a[0], a[1], w);
  n = strlen(a[0]);
  m = strlen(w);
  REP(u, 2) calcc(u, cr[u]);
  reverse(w, w + m);
  REP(u, 2) calcc(u, c[u]);
  int ans = solve(true);
  if (m > 1) {
    reverse(w, w + m);
    REP(u, 2) REP(i, n) REP(j, m) swap(c[u][i][j], cr[u][i][j]);
    inc(ans, solve(false));
    if (m == 2) REP(i, n) REP(u, 2)
      if (a[u][i] == w[0] && a[u^1][i] == w[1]) dec(ans, 1);
  }
  printf("%d\n", ans);
  return 0;
}