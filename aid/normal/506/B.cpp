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
int n, m;
vector<int> g[maxn], g1[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
    g1[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    g1[v].push_back(u);
    g1[u].push_back(v);
  }
  return true;
}

int used[maxn];

vector<int> vs;

void dfs1(int v) {
  used[v] = true;
  vs.push_back(v);
  for (int i = 0; i < sz(g1[v]); i++) {
    int u = g1[v][i];
    if (!used[u]) {
      dfs1(u);
    }
  }
}

bool dfs(int v) {
  used[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (!used[u]) {
      if (!dfs(u)) {
        return false;
      }
    } else {
      if (used[u] == 1) {
        return false;
      }
    }
  }
  used[v] = 2;
  return true;
}

void solve() {
  int res = n;
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      vs.clear();
      dfs1(i);
      for (int j = 0; j < sz(vs); j++) {
        int v = vs[j];
        used[v] = false;
      }
      bool ok = true;
      for (int j = 0; j < sz(vs); j++) {
        int v = vs[j];
        if (!used[v]) {
          if (!dfs(v)) {
            ok = false;
            break;
          }
        }
      }
      for (int j = 0; j < sz(vs); j++) {
        int v = vs[j];
        used[v] = true;
      }
      if (ok) {
        res--;
      }
    }
  }
  printf("%d\n", res);
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