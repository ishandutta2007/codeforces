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

const int maxn = (int) 2e5 + 5;
int n, k;
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

int d[maxn];

int getFurthest(int v, int p) {
  d[v] = (p == -1 ? 0 : d[p] + 1);
  int res = v;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    int cur = getFurthest(u, v);
    if (d[cur] > d[res]) {
      res = cur;
    }
  }
  return res;
}

bool getPath(int v, int p, int t, vector<int> &path) {
  path.push_back(v);
  if (v == t) {
    return true;
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    if (getPath(u, v, t, path)) {
      return true;
    }
  }
  path.pop_back();
  return false;
}

int dep[maxn][3];

void getDep(int v, int p) {
  dep[v][0] = 0;
  dep[v][1] = -1;
  dep[v][2] = -1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    getDep(u, v);
    if (dep[u][0] + 1 > dep[v][0]) {
      dep[v][2] = dep[v][1];
      dep[v][1] = dep[v][0];
      dep[v][0] = dep[u][0] + 1;
    } else if (dep[u][0] + 1 > dep[v][1]) {
      dep[v][2] = dep[v][1];
      dep[v][1] = dep[u][0] + 1;
    } else if (dep[u][0] + 1 > dep[v][2]) {
      dep[v][2] = dep[u][0] + 1;
    }
  }
}

int col[maxn];

bool paint(int v, int p, int dc) {
  if (dep[v][1] > 0 && dep[v][0] + dep[v][1] >= k - 1) {
    return false;
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    col[u] = (col[v] + dc) % k;
    if (!paint(u, v, dc)) {
      return false;
    }
  }
  return true;
}

void dfs2(int v, int p) {
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    col[u] = (col[v] ^ 1);
    dfs2(u, v);
  }
}

void printAns() {
  printf("Yes\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", col[i] + 1);
  }
  printf("\n");
}

void solve() {
  if (k == 2) {
    col[0] = 0;
    dfs2(0, -1);
    printAns();
    return;
  }
  int v = 0;
  int u = getFurthest(v, -1);
  v = getFurthest(u, -1);
  vector<int> path;
  getPath(v, -1, u, path);
  if (!(sz(path) & 1)) {
    v = path[sz(path) / 2 - 1];
    u = path[sz(path) / 2];
    col[v] = 0;
    getDep(v, u);
    if (!paint(v, u, 1)) {
      printf("No\n");
      return;
    }
    col[u] = k - 1;
    getDep(u, v);
    if (!paint(u, v, k - 1)) {
      printf("No\n");
      return;
    }
    printAns();
    return;
  }
  v = path[sz(path) / 2];
  getDep(v, -1);
  assert(dep[v][0] == dep[v][1]);
  if (dep[v][2] > 0 && dep[v][2] + dep[v][1] >= k - 1) {
    printf("No\n");
    return;
  }
  int b = 0;
  col[v] = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    int dc;
    if (dep[u][0] + 1 == dep[v][0]) {
      dc = (!b ? 1 : k - 1);
      b++;
    } else {
      dc = 1;
    }
    col[u] = (col[v] + dc) % k;
    if (!paint(u, v, dc)) {
      printf("No\n");
      return;
    }
  }
  printAns();
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}