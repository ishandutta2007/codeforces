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
int n, m, k;
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
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
    g[u].push_back(v);
  }
  return true;
}

int used[maxn];
int p[maxn], dep[maxn];
vector<int> leaves;

void dfs(int v) {
  used[v] = true;
  int cnt = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (used[u]) {
      continue;
    }
    p[u] = v;
    dep[u] = dep[v] + 1;
    cnt++;
    dfs(u);
  }
  if (!cnt) {
    leaves.push_back(v);
  }
}

vector<int> path;

void solve() {
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  leaves.clear();
  p[0] = -1;
  dep[0] = 0;
  dfs(0);
  for (int i = 0; i < sz(leaves); i++) {
    int v = leaves[i];
    if (dep[v] + 1 >= (n + k - 1) / k) {
      path.clear();
      while (v != -1) {
        path.push_back(v);
        v = p[v];
      }
      printf("PATH\n%d\n", sz(path));
      for (int j = 0; j < sz(path); j++) {
        printf("%d ", path[j] + 1);
      }
      printf("\n");
      return;
    }
  }
  assert(sz(leaves) >= k);
  printf("CYCLES\n");
  for (int it = 0; it < k; it++) {
    int v = leaves[it];
    int pos = 0;
    while (g[v][pos] == p[v]) {
      pos++;
    }
    int u = g[v][pos++];
    while (g[v][pos] == p[v]) {
      pos++;
    }
    int w = g[v][pos++];
    path.clear();
    if ((dep[v] - dep[u] + 1) % 3) {
      while (v != u) {
        path.push_back(v);
        v = p[v];
      }
      path.push_back(v);
    } else if ((dep[v] - dep[w] + 1) % 3) {
      while (v != w) {
        path.push_back(v);
        v = p[v];
      }
      path.push_back(v);
    } else {
      if (dep[u] < dep[w]) {
        swap(u, w);
      }
      path.push_back(v);
      while (u != w) {
        path.push_back(u);
        u = p[u];
      }
      path.push_back(w);
    }
    assert(sz(path) % 3);
    printf("%d\n", sz(path));
    for (int i = 0; i < sz(path); i++) {
      printf("%d ", path[i] + 1);
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