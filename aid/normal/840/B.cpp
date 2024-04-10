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

const int maxn = (int) 3e5 + 5;
int n, m;
int d[maxn];
vector<int> g[maxn];
vector<int> ids[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &d[i]);
    g[i].clear();
    ids[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    ids[v].push_back(i);
    g[u].push_back(v);
    ids[u].push_back(i);
  }
  return true;
}

int used[maxn];
vector<int> ans;

int dfs(int v, int pe) {
  used[v] = true;
  int odd = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    int id = ids[v][i];
    if (used[u]) {
      continue;
    }
    odd ^= dfs(u, id);
  }
  if (odd != d[v]) {
    assert(pe != -1);
    ans.push_back(pe);
    return 1;
  }
  return 0;
}

void solve() {
  {
    int odd = 0;
    int lst = -1;
    for (int i = 0; i < n; i++) {
      if (d[i] == -1) {
        lst = i;
        d[i] = 0;
      }
      odd = (odd ^ d[i]);
    }
    if (odd) {
      if (lst == -1) {
        printf("-1\n");
        return;
      }
      d[lst] ^= 1;
    }
  }
  ans.clear();
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  dfs(0, -1);
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d\n", ans[i] + 1);
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