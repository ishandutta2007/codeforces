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
int es[maxn][2];
vector<pair<int, pair<int, int>>> g[2][maxn];
int deg[2][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int t = 0; t < 2; ++t) {
    for (int i = 0; i < n; ++i) {
      g[t][i].clear();
      deg[t][i] = 0;
    }
  }
  for (int i = 0; i < m; ++i) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    --v;
    --u;
    --w;
    es[i][0] = v;
    es[i][1] = u;
    g[w][v].push_back(make_pair(u, make_pair(i, 0)));
    g[w][u].push_back(make_pair(v, make_pair(i, 1)));
    ++deg[w][v];
    ++deg[w][u];
  }
  return true;
}

int del[maxn];
int p[2][maxn];
vector<pair<int, int>> paths[2][maxn];
vector<pair<int, int>> cycle;
int ans[maxn];
string sans;

void dfs(int t, int v, vector<pair<int, int>> &path) {
  while (!g[t][v].empty()) {
    int u = g[t][v].back().first;
    auto e = g[t][v].back().second;
    g[t][v].pop_back();
    if (del[e.first]) {
      continue;
    }
    del[e.first] = true;
    --deg[t][es[e.first][0]];
    --deg[t][es[e.first][1]];
    dfs(t, u, path);
    path.push_back(e);
    return;
  }
}

int used[maxn];

void go(int s) {
  int v = s;
  int prt = -1;
  while (!used[v]) {
    used[v] = true;
    int t = 0;
    int u = p[t][v];
    if (u == -1 || t == prt) {
      ++t;
      u = p[t][v];
    }
    if (u == -1 || t == prt) {
      break;
    }
    for (int i = 0; i < sz(paths[t][v]); ++i) {
      ans[paths[t][v][i].first] = paths[t][v][i].second;
    }
    prt = t;
    v = u;
  }
}

void solve() {
  for (int i = 0; i < m; ++i) {
    del[i] = false;
  }
  int res = 0;
  for (int t = 0; t < 2; ++t) {
    for (int v = 0; v < n; ++v) {
      p[t][v] = -1;
      paths[t][v].clear();
    }
    for (int v = 0; v < n; ++v) {
      if (deg[t][v] & 1) {
        if (t == 0) {
          res += 2;
        }
        dfs(t, v, paths[t][v]);
        int u = es[paths[t][v][0].first][!paths[t][v][0].second];
        p[t][v] = u;
        p[t][u] = v;
        paths[t][u] = paths[t][v];
        for (int i = 0; i < sz(paths[t][u]); ++i) {
          paths[t][u][i].second ^= 1;
        }
      }
    }
    for (int v = 0; v < n; ++v) {
      if (deg[t][v]) {
        cycle.clear();
        dfs(t, v, cycle);
        for (int i = 0; i < sz(cycle); ++i) {
          ans[cycle[i].first] = cycle[i].second;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    used[i] = false;
  }
  for (int s = 0; s < n; ++s) {
    if (used[s]) {
      continue;
    }
    int deg = (int) (p[0][s] != -1) + (int) (p[1][s] != -1);
    if (deg == 1) {
      go(s);
    }
  }
  for (int s = 0; s < n; ++s) {
    if (used[s]) {
      continue;
    }
    go(s);
  }
  sans.resize(m);
  for (int i = 0; i < m; ++i) {
    sans[i] = (char) ('1' + ans[i]);
  }
  printf("%d\n", res);
  printf("%s\n", sans.c_str());
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