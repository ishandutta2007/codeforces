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
int x;
vector<int> g[maxn];
pair<int, pair<int, int>> es[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  x = 0;
  for (int i = 0; i < m; ++i) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    --v;
    --u;
    x ^= w;
    g[v].push_back(u);
    g[u].push_back(v);
    es[i] = make_pair(w, make_pair(v, u));
  }
  return true;
}

int ts[maxn], p[maxn];

int get(int x) {
  return (p[x] == x ? x : p[x] = get(p[x]));
}

bool unite(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y) {
    return false;
  }
  if (ts[x] < ts[y]) {
    swap(x, y);
  }
  ts[x] += ts[y];
  p[y] = x;
  return true;
}

set<int> alive;

void dfs(int v) {
  int i = 0;
  vector<int> go;
  for (auto it = alive.begin(); it != alive.end();) {
    int u = *it;
    while (i < sz(g[v]) && g[v][i] < u) {
      ++i;
    }
    if (i < sz(g[v]) && g[v][i] == u) {
      ++it;
      continue;
    }
    auto del = it;
    ++it;
    alive.erase(del);
    go.push_back(u);
  }
  for (int i = 0; i < sz(go); ++i) {
    int u = go[i];
    unite(v, u);
    dfs(u);
  }
}

int take[maxn];

void solve() {
  sort(es, es + m);
  for (int i = 0; i < n; ++i) {
    sort(g[i].begin(), g[i].end());
  }
  alive.clear();
  for (int i = 0; i < n; ++i) {
    alive.insert(i);
    ts[i] = 1;
    p[i] = i;
  }
  int k = 0;
  while (!alive.empty()) {
    ++k;
    int v = *alive.begin();
    alive.erase(alive.begin());
    dfs(v);
  }
  long long res = 0;
  for (int i = 0; i < m; ++i) {
    int w = es[i].first, v = es[i].second.first, u = es[i].second.second;
    take[i] = false;
    if (unite(v, u)) {
      take[i] = true;
      res += w;
    }
  }
  if (m + n - k == (long long) n * (n - 1) / 2) {
    res += x;
    for (int i = 0; i < n; ++i) {
      ts[i] = 1;
      p[i] = i;
    }
    for (int i = 0; i < m; ++i) {
      int w = es[i].first, v = es[i].second.first, u = es[i].second.second;
      if (take[i]) {
        unite(v, u);
      } else if (unite(v, u)) {
        if (w < x) {
          res += w - x;
        }
        break;
      }
    }
  }
  printf("%lld\n", res);
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