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
int n;
vector<int> g[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
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

map<vector<int>, int> h;
map<pair<int, int>, int> dp;

int getId(const vector<int> &a) {
  if (h.count(a)) {
    return h[a];
  }
  int id = sz(h);
  return h[a] = id;
}

int dfs(int v, int p) {
  if (dp.count(make_pair(v, p))) {
    return dp[make_pair(v, p)];
  }
  vector<int> a;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    a.push_back(dfs(u, v));
  }
  sort(a.begin(), a.end());
  return dp[make_pair(v, p)] = getId(a);
}

void solve() {
  h.clear();
  dp.clear();
  vector<int> a;
  for (int i = 0; i < n; i++) {
    if (sz(g[i]) < 4) {
      a.push_back(dfs(i, -1));
    }
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  printf("%d\n", sz(a));
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