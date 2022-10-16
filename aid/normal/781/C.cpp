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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 2e5 + 5;
int n, m, k;
vector<int> g[maxn];
int used[maxn];
vector<int> path;

int read() {
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

void dfs(int v) {
  used[v] = true;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (used[u]) {
      continue;
    }
    path.push_back(u);
    dfs(u);
    path.push_back(v);
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  path.clear();
  path.push_back(0);
  dfs(0);
  assert(sz(path) == 2 * n - 1);
  int b = (2 * n - 1) / k;
  int rem = (2 * n - 1) % k;
  int l = 0, r;
  for (int i = 0; i < k; i++) {
    if (i < rem) {
      r = l + b + 1;
    } else {
      r = l + b;
    }
    printf("%d ", r - l);
    for (int j = l; j < r; j++) {
      printf("%d ", path[j] + 1);
    }
    printf("\n");
    l = r;
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