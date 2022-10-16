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
int n, k;
vector<int> g[maxn];

int read() {
  if (scanf("%d%d", &n, &k) < 2) {
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
  return true;
}

int d[maxn];

int dfs(int v, int p) {
  int res = v;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    d[u] = d[v] + 1;
    int cur = dfs(u, v);
    if (d[cur] > d[res]) {
      res = cur;
    }
  }
  return res;
}

bool getPath(int v, int p, int t, vector<int> &path) {
  path.push_back(v);
  if (v == t) {
    return true;
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    if (getPath(u, v, t, path)) {
      return true;
    }
  }
  path.pop_back();
  return false;
}

bool check(int v, int p, int k) {
  if (!k) {
    if (p == -1) {
      return false;
    }
    if (sz(g[v]) > 1) {
      return false;
    }
    return true;
  }
  int cnt = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    cnt++;
    if (!check(u, v, k - 1)) {
      return false;
    }
  }
  if (cnt < 3) {
    return false;
  }
  return true;
}

void solve() {
  int root;
  {
    int v = 0;
    d[v] = 0;
    int u = dfs(v, -1);
    swap(v, u);
    d[v] = 0;
    u = dfs(v, -1);
    vector<int> path;
    getPath(v, -1, u, path);
    if (!(sz(path) & 1)) {
      printf("No\n");
      return;
    }
    root = path[sz(path) / 2];
  }
  if (check(root, -1, k)) {
    printf("Yes\n");
  } else {
    printf("No\n");
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