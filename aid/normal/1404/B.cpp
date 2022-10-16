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

const int maxn = (int) 1e5 + 5;
int n, a, b, da, db;
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d%d%d%d", &n, &a, &b, &da, &db) < 5) {
    return false;
  }
  --a;
  --b;
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

int d[maxn];

int dfs(int v, int p) {
  d[v] = (p == -1 ? 0 : d[p] + 1);
  int res = v;
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    int cur = dfs(u, v);
    if (d[cur] > d[res]) {
      res = cur;
    }
  }
  return res;
}

void solve() {
  {
    dfs(a, -1);
    if (d[b] <= da) {
      printf("Alice\n");
      return;
    }
  }
  {
    int v = 0;
    int u = dfs(v, -1);
    v = dfs(u, -1);
    if (d[v] <= 2 * da) {
      printf("Alice\n");
      return;
    }
  }
  if (db <= 2 * da) {
    printf("Alice\n");
    return;
  }
  printf("Bob\n");
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}