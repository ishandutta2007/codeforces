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
int n, m;
vector<pair<int, int>> gt[maxn];
int qs[maxn][3];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    gt[i].clear();
  }
  for (int i = 0; i < n - 1; ++i) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    --v;
    --u;
    gt[v].push_back(make_pair(u, w));
    gt[u].push_back(make_pair(v, w));
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &qs[i][0], &qs[i][1], &qs[i][2]);
    --qs[i][0];
    --qs[i][1];
  }
  return true;
}

int ids[maxn], s[maxn];

void dfsTree(int v, int p) {
  for (int i = 0; i < sz(gt[v]); ++i) {
    int u = gt[v][i].first, w = gt[v][i].second;
    if (u == p) {
      continue;
    }
    if (w == -1) {
      ids[u] = u;
      s[u] = s[v];
    } else {
      ids[u] = ids[v];
      s[u] = (s[v] ^ w);
    }
    dfsTree(u, v);
  }
}

int ans[maxn];
vector<pair<int, int>> g[maxn];

bool dfs(int v) {
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i].first, x = g[v][i].second;
    if (ans[u] == -1) {
      ans[u] = (ans[v] ^ x);
      if (!dfs(u)) {
        return false;
      }
    }
    if (ans[u] ^ ans[v] ^ x) {
      return false;
    }
  }
  return true;
}

void printAns(int v, int p) {
  for (int i = 0; i < sz(gt[v]); ++i) {
    int u = gt[v][i].first, w = gt[v][i].second;
    if (u == p) {
      continue;
    }
    if (w == -1) {
      w = (ans[u] ^ ans[ids[v]]);
    }
    printf("%d %d %d\n", v + 1, u + 1, w);
    printAns(u, v);
  }
}

void solve() {
  ids[0] = 0;
  s[0] = 0;
  dfsTree(0, -1);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    int v = qs[i][0], u = qs[i][1], x = qs[i][2];
    int val = (__builtin_popcount(s[v] ^ s[u]) & 1);
    x ^= val;
    v = ids[v];
    u = ids[u];
    g[v].push_back(make_pair(u, x));
    g[u].push_back(make_pair(v, x));
  }
  for (int i = 0; i < n; ++i) {
    ans[i] = -1;
  }
  for (int i = 0; i < n; ++i) {
    if (ids[i] != i) {
      continue;
    }
    if (ans[i] == -1) {
      ans[i] = 0;
      if (!dfs(i)) {
        printf("NO\n");
        return;
      }
    }
  }
  printf("YES\n");
  printAns(0, -1);
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