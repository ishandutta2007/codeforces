#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR (i, 0, n)

const int L = 2e5;
int n, x[L], y[L];
int d[L], e[L][2];
char ans[L+1];

inline void add(int i, int j) {
  e[i][d[i]++] = j;
  e[j][d[j]++] = i;
}

int main() {
  scanf("%d", &n);
  REP(i, n) {
    int xi, yi, j;
    scanf("%d%d", &xi, &yi);
    if ((j = x[--xi] - 1) >= 0) add(i, j), x[xi] = 0;
    else x[xi] = i + 1;
    if ((j = y[--yi] - 1) >= 0) add(i, j), y[yi] = 0;
    else y[yi] = i + 1;
  }

  REP(i, n) if (d[i]) {
    x[0] = i;
    for (int *v = x, *b = x+1; v < b; ++v) {
      REP(j, d[*v]) {
        int u = e[*v][j];
        if (d[u]) y[u] = !y[*v], *b = u, ++b;
      }
      d[*v] = 0;
    }
  }

  REP(i, n) ans[i] = y[i] ? 'r' : 'b';
  printf("%s\n", ans);
  return 0;
}