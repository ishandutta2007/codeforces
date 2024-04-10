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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 3e5 + 5;
int n, m;
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
    g[u].push_back(v);
  }
  return true;
}

int d[maxn];
int p[maxn];
vector<int> q;
int con[maxn];
int used[maxn];

void solve() {
  q.clear();
  for (int i = 0; i < n; i++) {
    d[i] = inf;
    p[i] = -1;
  }
  d[0] = 0;
  q.push_back(0);
  for (int l = 0; l < sz(q); l++) {
    int v = q[l];
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (d[u] >= inf) {
        d[u] = d[v] + 1;
        p[u] = v;
        q.push_back(u);
      }
    }
  }
  if (d[n - 1] < 4) {
    vector<int> path;
    for (int v = n - 1; v != -1; v = p[v]) {
      path.push_back(v);
    }
    reverse(path.begin(), path.end());
    printf("%d\n", sz(path) - 1);
    for (int i = 0; i < sz(path); i++) {
      printf("%d ", path[i] + 1);
    }
    printf("\n");
    return;
  }
  vector<int> c;
  for (int i = 0; i < n; i++) {
    if (d[i] < inf) {
      c.push_back(i);
    }
  }
  if (sz(g[0]) < sz(c) - 1) {
    for (int i = 0; i < n; i++) {
      con[i] = false;
    }
    for (int i = 0; i < sz(g[0]); i++) {
      con[g[0][i]] = true;
    }
    for (int it = 0; it < sz(g[0]); it++) {
      int v = g[0][it];
      for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        if (u != 0 && !con[u]) {
          printf("4\n");
          printf("%d %d %d %d %d\n", 1, v + 1, u + 1, 1, n);
          return;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  used[0] = true;
  for (int it = 0; it < sz(c); it++) {
    int v0 = c[it];
    if (used[v0]) {
      continue;
    }
    for (int iter = 0; iter < 2; iter++) {
      q.clear();
      q.push_back(v0);
      used[v0] = true;
      int v1 = -1, v2 = -1;
      for (int l = 0; l < sz(q); l++) {
        int v = q[l];
        for (int i = 0; i < sz(g[v]); i++) {
          int u = g[v][i];
          if (used[u]) {
            continue;
          }
          q.push_back(u);
          used[u] = true;
          if (v != v0 && v1 == -1) {
            v1 = v;
            v2 = u;
          }
        }
      }
      if (v1 != -1) {
        printf("5\n");
        printf("%d %d %d %d %d %d\n", 1, v0 + 1, v1 + 1, v2 + 1, v0 + 1, n);
        return;
      }
      if (!iter) {
        for (int i = 0; i < sz(q); i++) {
          int v = q[i];
          if (sz(g[v]) < sz(q)) {
            v0 = v;
            break;
          }
        }
        for (int i = 0; i < sz(q); i++) {
          used[q[i]] = false;
        }
      }
    }
  }
  printf("-1\n");
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