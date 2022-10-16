#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 55;
int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

int ask(int x0, int y0, int x1, int y1) {
  printf("? %d %d %d %d\n", x0 + 1, y0 + 1, x1 + 1, y1 + 1);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  if (res == -1) {
    exit(0);
  }
  return res;
}

int c[maxn][maxn];
const int maxv = maxn * maxn;
vector<pair<int, int>> g[maxv];
int isp[2][2][maxn][maxn];

void addEdge(int v, int u, int w) {
  g[v].push_back(make_pair(u, w));
  g[u].push_back(make_pair(v, w));
}

void dfs(int v) {
  int x0 = v / n, y0 = v % n;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, w = g[v][i].second;
    int x = u / n, y = u % n;
    if (c[x][y] != -1) {
      continue;
    }
    c[x][y] = (c[x0][y0] ^ w);
    dfs(u);
  }
}

bool check(int x0, int y0, int x1, int y1) {
  if (c[x0][y0] != c[x1][y1]) {
    return false;
  }
  for (int i = 0; i < 2; i++) {
    int nx = x0 + i, ny = y0 + (1 - i);
    for (int j = 0; j < 2; j++) {
      int px = x1 - i, py = y1 - (1 - i);
      if (c[nx][ny] == c[px][py] && nx <= px && ny <= py && (px - nx) + (py - ny) == 1) {
        return true;
      }
    }
  }
  return false;
}

void solve() {
  for (int i = 0; i < n * n; i++) {
    g[i].clear();
  }
  for (int i = 0; i + 1 < n; i++) {
    for(int j = 0; j + 1 < n; j++) {
      addEdge(i * n + j, (i + 1) * n + (j + 1), (ask(i, j, i + 1, j + 1) ^ 1));
    }
  }
  for (int i = 0; i + 2 < n; i++) {
    addEdge(i * n + 0, (i + 2) * n + 0, (ask(i, 0, i + 2, 0) ^ 1));
  }
  for (int j = 0; j + 2 < n; j++) {
    addEdge(0 * n + j, 0 * n + (j + 2), (ask(0, j, 0, j + 2) ^ 1));
  }
  addEdge(0 * n + 1, 2 * n + 1, (ask(0, 1, 2, 1) ^ 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c[i][j] = -1;
    }
  }
  c[0][0] = 1;
  dfs(0 * n + 0);
  c[0][1] = 0;
  dfs(0 * n + 1);
  for (int i = 0; i + 1 < n; i++) {
    for (int j = 0; j + 2 < n; j++) {
      isp[0][0][i][j] = check(i, j, i + 1, j + 2);
    }
  }
  for (int i = 0; i + 2 < n; i++) {
    for (int j = 0; j + 1 < n; j++) {
      isp[0][1][i][j] = check(i, j, i + 2, j + 1);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + j) & 1) {
        c[i][j] ^= 1;
      }
    }
  }
  for (int i = 0; i + 1 < n; i++) {
    for (int j = 0; j + 2 < n; j++) {
      isp[1][0][i][j] = check(i, j, i + 1, j + 2);
    }
  }
  for (int i = 0; i + 2 < n; i++) {
    for (int j = 0; j + 1 < n; j++) {
      isp[1][1][i][j] = check(i, j, i + 2, j + 1);
    }
  }
  bool flip = false;
  bool found = false;
  for (int i = 0; i + 1 < n && !found; i++) {
    for (int j = 0; j + 2 < n && !found; j++) {
      if (isp[0][0][i][j] != isp[1][0][i][j]) {
        found = true;
        if (ask(i, j, i + 1, j + 2) != isp[1][0][i][j]) {
          flip = true;
        }
      }
    }
  }
  for (int i = 0; i + 2 < n && !found; i++) {
    for (int j = 0; j + 1 < n && !found; j++) {
      if (isp[0][1][i][j] != isp[1][1][i][j]) {
        found = true;
        if (ask(i, j, i + 2, j + 1) != isp[1][1][i][j]) {
          flip = true;
        }
      }
    }
  }
  assert(found);
  if (flip) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if ((i + j) & 1) {
          c[i][j] ^= 1;
        }
      }
    }
  }
  printf("!\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d", c[i][j]);
    }
    printf("\n");
  }
  fflush(stdout);
}

int main() {
  precalc();
  read();
  solve();
#ifdef DEBUG
  eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}