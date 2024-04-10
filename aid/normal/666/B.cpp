#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 3e3 + 5;
int n, m;
int d[maxn][maxn], maxd[maxn][3];
vector<int> g[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
  }
  return true;
}

vector<int> q;

void solve() {
  for (int s = 0; s < n; s++) {
    for (int i = 0; i < n; i++) {
      d[s][i] = inf;
    }
    d[s][s] = 0;
    q.clear();
    q.push_back(s);
    for (int l = 0; l < sz(q); l++) {
      int v = q[l];
      for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        if (d[s][v] + 1 < d[s][u]) {
          d[s][u] = d[s][v] + 1;
          q.push_back(u);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    maxd[i][0] = -1;
    maxd[i][1] = -1;
    maxd[i][2] = -1;
    for (int j = 0; j < n; j++) {
      if (j == i || d[i][j] == inf) {
        continue;
      }
      if (maxd[i][0] == -1 || d[i][j] > d[i][maxd[i][0]]) {
        maxd[i][2] = maxd[i][1];
        maxd[i][1] = maxd[i][0];
        maxd[i][0] = j;
      } else if (maxd[i][1] == -1 || d[i][j] > d[i][maxd[i][1]]) {
        maxd[i][2] = maxd[i][1];
        maxd[i][1] = j;
      } else if (maxd[i][2] == -1 || d[i][j] > d[i][maxd[i][2]]) {
        maxd[i][2] = j;
      }
    }
  }
  int ansv[4] = {-1, -1, -1, -1}, ansd = 0;
  for (int v1 = 0; v1 < n; v1++) {
    int maxdr[3] = {-1, -1, -1};
    for (int i = 0; i < n; i++) {
      if (i == v1 || d[i][v1] == inf) {
        continue;
      }
      if (maxdr[0] == -1 || d[i][v1] > d[maxdr[0]][v1]) {
        maxdr[2] = maxdr[1];
        maxdr[1] = maxdr[0];
        maxdr[0] = i;
      } else if (maxdr[1] == -1 || d[i][v1] > d[maxdr[1]][v1]) {
        maxdr[2] = maxdr[1];
        maxdr[1] = i;
      } else if (maxdr[2] == -1 || d[i][v1] > d[maxdr[2]][v1]) {
        maxdr[2] = i;
      }
    }
    for (int v2 = 0; v2 < n; v2++) {
      if (v2 == v1 || d[v1][v2] == inf) {
        continue;
      }
      for (int i = 0; i < 3; i++) {
        int v0 = maxdr[i];
        if (v0 == v2 || v0 == -1) {
          continue;
        }
        int j = 0;
        while (maxd[v2][j] == v0 || maxd[v2][j] == v1) {
          j++;
        }
        int v3 = maxd[v2][j];
        if (v3 == -1) {
          continue;
        }
        if (d[v0][v1] + d[v1][v2] + d[v2][v3] > ansd) {
          ansd = d[v0][v1] + d[v1][v2] + d[v2][v3];
          ansv[0] = v0;
          ansv[1] = v1;
          ansv[2] = v2;
          ansv[3] = v3;
        }
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    printf("%d ", ansv[i] + 1);
  }
  printf("\n");
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}