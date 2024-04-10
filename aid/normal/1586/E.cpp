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

const int maxn = (int) 3e5 + 5;
int n, m;
int a[maxn];
vector<int> g[maxn], gt[maxn];
int q;
int qs[maxn][2];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    a[i] = 0;
    g[i].clear();
    gt[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    for (int j = 0; j < 2; ++j) {
      scanf("%d", &qs[i][j]);
      --qs[i][j];
      a[qs[i][j]] ^= 1;
    }
  }
  return true;
}

int used[maxn];

void dfs0(int v) {
  used[v] = true;
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    if (used[u]) {
      continue;
    }
    gt[v].push_back(u);
    gt[u].push_back(v);
    dfs0(u);
  }
}

vector<int> path;

bool getPath(int v, int p, int t) {
  if (v == t) {
    path.push_back(v);
    return true;
  }
  for (int i = 0; i < sz(gt[v]); ++i) {
    int u = gt[v][i];
    if (u == p) {
      continue;
    }
    if (getPath(u, v, t)) {
      path.push_back(v);
      return true;
    }
  }
  return false;
}

void solve() {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += a[i];
  }
  if (cnt) {
    printf("NO\n");
    printf("%d\n", cnt / 2);
    return;
  }
  for (int i = 0; i < n; ++i) {
    used[i] = false;
  }
  dfs0(0);
  printf("YES\n");
  for (int i = 0; i < q; ++i) {
    int v = qs[i][0], u = qs[i][1];
    path.clear();
    getPath(u, -1, v);
    printf("%d\n", sz(path));
    for (int j = 0; j < sz(path); ++j) {
      printf("%d ", path[j] + 1);
    }
    printf("\n");
  }
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