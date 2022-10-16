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

const int maxn = (int) 1e5 + 5;
int n, m;
long long a[maxn];
vector<int> g[maxn];
vector<int> ids[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < n; i++) {
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

int col[maxn];
vector<int> path;

bool checkBip(int v) {
  path.push_back(v);
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (col[u] == -1) {
      col[u] = (col[v] ^ 1);
      if (!checkBip(u)) {
        return false;
      }
    } else {
      if (col[u] == col[v]) {
        path.push_back(u);
        return false;
      }
    }
  }
  path.pop_back();
  return true;
}

int del[maxn];
long long ans[maxn];
int used[maxn];

void delEdges(int v, int p) {
  used[v] = true;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i], id = ids[v][i];
    if (u == p || del[id]) {
      continue;
    }
    if (used[u]) {
      ans[id] = 1;
      del[id] = true;
      a[v]--;
      a[u]--;
      continue;
    }
    delEdges(u, v);
  }
}

void dfs(int v, int p, int pe) {
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i], id = ids[v][i];
    if (u == p || del[id]) {
      continue;
    }
    dfs(u, v, id);
  }
  if (p != -1) {
    ans[pe] = a[v];
    a[v] -= ans[pe];
    a[p] -= ans[pe];
  }
}

void solve() {
  for (int i = 0; i < m; i++) {
    del[i] = false;
  }
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  for (int i = 0; i < n; i++) {
    col[i] = -1;
  }
  col[0] = 0;
  path.clear();
  if (checkBip(0)) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum += (2 * col[i] - 1) * a[i];
    }
    if (sum) {
      printf("NO\n");
      return;
    }
    delEdges(0, -1);
    dfs(0, -1, -1);
  } else {
    for (int i = 0; i < sz(path); i++) {
      if (path[i] == path.back()) {
        path.erase(path.begin(), path.begin() + i);
        break;
      }
    }
    assert(!(sz(path) & 1));
    vector<int> es;
    for (int i = 0; i + 1 < sz(path); i++) {
      int v = path[i], nv = path[i + 1];
      for (int j = 0; j < sz(g[v]); j++) {
        int u = g[v][j], id = ids[v][j];
        if (u == nv) {
          es.push_back(id);
          del[id] = true;
          break;
        }
      }
      used[v] = true;
    }
    for (int i = 0; i + 1 < sz(path); i++) {
      delEdges(path[i], -1);
    }
    for (int i = 0; i + 1 < sz(path); i++) {
      dfs(path[i], -1, -1);
    }
    long long sum = 0;
    for (int i = 0; i + 1 < sz(path); i++) {
      sum += ((i & 1) ? -1 : 1) * a[path[i]];
    }
    assert(!(sum & 1));
    sum /= 2;
    ans[es.back()] = sum;
    a[path.back()] -= sum;
    a[path[sz(path) - 2]] -= sum;
    for (int i = 0; i + 2 < sz(path); i++) {
      int v = path[i];
      ans[es[i]] = a[v];
      a[v] -= ans[es[i]];
      a[path[i + 1]] -= ans[es[i]];
    }
  }
  for (int i = 0; i < n; i++) {
    assert(!a[i]);
  }
  printf("YES\n");
  for (int i = 0; i < m; i++) {
    printf("%lld\n", ans[i]);
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