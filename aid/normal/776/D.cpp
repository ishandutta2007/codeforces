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

const int maxn = (int) 1e5 + 5;
int n, m;
int r[maxn];
vector<int> sw[maxn];
vector< pair<int, int> > g[maxn];

int read() {
  if (scanf("%d%d", &m, &n) < 2) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &r[i]);
    r[i] ^= 1;
    sw[i].clear();
  }
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      int rid;
      scanf("%d", &rid);
      rid--;
      sw[rid].push_back(i);
    }
  }
  return true;
}

int used[maxn];
int c[maxn];

bool dfs(int v) {
  used[v] = true;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, w = g[v][i].second;
    if (used[u]) {
      if ((c[v] ^ c[u]) != w) {
        return false;
      }
    } else {
      c[u] = (c[v] ^ w);
      if (!dfs(u)) {
        return false;
      }
    }
  }
  return true;
}

void solve() {
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    assert(sz(sw[i]) == 2);
    int v = sw[i][0];
    int u = sw[i][1];
    g[v].push_back(make_pair(u, r[i]));
    g[u].push_back(make_pair(v, r[i]));
  }
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      c[i] = false;
      if (!dfs(i)) {
        printf("NO\n");
        return;
      }
    }
  }
  printf("YES\n");
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