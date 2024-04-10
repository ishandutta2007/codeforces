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
int n;
vector<int> g[maxn];
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
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
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  return true;
}

int dep[maxn], p[maxn];

void dfs(int v) {
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p[v]) {
      continue;
    }
    dep[u] = dep[v] + 1;
    p[u] = v;
    dfs(u);
  }
}

int pos[maxn];
vector<int> vs[maxn];

void solve() {
  dep[0] = 0;
  p[0] = -1;
  dfs(0);
  for (int i = 0; i < n; i++) {
    vs[i].clear();
  }
  for (int i = 0; i + 1 < n; i++) {
    if (dep[a[i + 1]] < dep[a[i]]) {
      printf("No\n");
      return;
    }
  }
  for (int i = 0; i < n; i++) {
    vs[dep[a[i]]].push_back(a[i]);
  }
  for (int d = 0; d < n; d++) {
    for (int i = 0; i + 1 < sz(vs[d]); i++) {
      if (pos[p[vs[d][i + 1]]] < pos[p[vs[d][i]]]) {
        printf("No\n");
        return;
      }
    }
    for (int i = 0; i < sz(vs[d]); i++) {
      pos[vs[d][i]] = i;
    }
  }
  printf("Yes\n");
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