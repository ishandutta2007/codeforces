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
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

int used[maxn];
int taken[maxn];

void dfs(int v) {
  used[v] = true;
  taken[v] = true;
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    if (!used[u]) {
      continue;
    }
    if (taken[u]) {
      taken[v] = false;
    }
  }
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    if (!used[u]) {
      dfs(u);
    }
  }
}

void solve() {
  for (int i = 0; i < n; ++i) {
    used[i] = false;
    taken[i] = false;
  }
  dfs(0);
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (taken[i]) {
      ans.push_back(i);
    }
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); ++i) {
    printf("%d ", ans[i] + 1);
  }
  printf("\n");
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