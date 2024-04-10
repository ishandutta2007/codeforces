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
int n, a[2];
int p[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &a[0], &a[1]) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }
  return true;
}

map<int, int> ids;
vector<int> g[maxn];
int msk[maxn];
int used[maxn];
vector<int> vs;

int dfs(int v) {
  used[v] = true;
  vs.push_back(v);
  int res = msk[v];
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (used[u]) {
      continue;
    }
    res &= dfs(u);
  }
  return res;
}

int ans[maxn];

void solve() {
  ids.clear();
  for (int i = 0; i < n; i++) {
    ids[p[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n; i++) {
    msk[i] = 0;
    for (int j = 0; j < 2; j++) {
      int q = a[j] - p[i];
      int id = (ids.count(q) ? ids[q] : -1);
      if (id == -1) {
        continue;
      }
      msk[i] |= (1 << j);
      g[i].push_back(id);
    }
  }
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    vs.clear();
    int x = dfs(i);
    if (!x) {
      printf("NO\n");
      return;
    }
    int col = ((x & 1) ? 0 : 1);
    for (int j = 0; j < sz(vs); j++) {
      ans[vs[j]] = col;
    }
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
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