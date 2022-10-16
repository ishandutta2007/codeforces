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
int n;
int a[maxn];
vector<int> g[maxn];
int p[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    g[i].clear();
    p[i] = -1;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    g[v].push_back(u);
    p[u] = v;
  }
  return true;
}

int pos[maxn];
int used[maxn];
int b[maxn];
vector<int> path;

bool bbcmp(int v, int u) {
  return b[v] < b[u];
}

int dep[maxn];

bool checkDfs(int v, int &cur) {
  if (b[v] != cur) {
    return false;
  }
  ++cur;
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    dep[u] = dep[v] + 1;
    if (!checkDfs(u, cur)) {
      return false;
    }
  }
  return true;
}

int deg[maxn];
int del[maxn];
int cdel[maxn];

bool dfs(int v) {
  cdel[v] = del[v];
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    if (!dfs(u)) {
      return false;
    }
    cdel[v] += cdel[u];
  }
  if (!del[v] && a[v] != b[v] + cdel[v]) {
    return false;
  }
  return true;
}

void solve() {
  for (int i = 0; i < n; ++i) {
    used[i] = false;
  }
  for (int i = 0; i < n; ++i) {
    pos[a[i]] = i;
  }
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    int v = pos[i];
    path.clear();
    while (v != -1 && !used[v]) {
      used[v] = true;
      path.push_back(v);
      v = p[v];
    }
    for (int j = sz(path) - 1; j >= 0; --j) {
      int u = path[j];
      b[u] = cur++;
    }
  }
  for (int v = 0; v < n; ++v) {
    sort(g[v].begin(), g[v].end(), bbcmp);
  }
  cur = 0;
  dep[0] = 0;
  if (!checkDfs(0, cur)) {
    printf("NO\n");
    return;
  }
  for (int i = 0; i < n; ++i) {
    deg[i] = sz(g[i]);
    del[i] = false;
  }
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    int v = pos[i];
    if (!deg[v]) {
      del[v] = true;
      int u = p[v];
      if (u != -1) {
        --deg[u];
      }
      res += dep[v];
      continue;
    }
    while (p[v] != -1) {
      int u = p[v];
      swap(a[v], a[u]);
      for (int j = 0; j < sz(g[u]); ++j) {
        int w = g[u][j];
        if (a[w] > a[u] && a[w] < a[v]) {
          printf("NO\n");
          return;
        }
      }
      ++res;
      v = u;
    }
    if (!dfs(v)) {
      printf("NO\n");
      return;
    }
    break;
  }
  printf("YES\n");
  printf("%lld\n", res);
  for (int i = 0; i < n; ++i) {
    printf("%d ", b[i] + 1);
  }
  printf("\n");
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