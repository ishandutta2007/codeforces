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

const int maxn = 5e5 + 5;
int n;
vector<int> g[maxn];

bool read() {
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

int dep[maxn];

void dfs0(int v, int p) {
  dep[v] = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs0(u, v);
    dep[v] = max(dep[v], dep[u] + 1);
  }
}

int ans[maxn];
int cnt[maxn];
vector<int> deps;
vector<pair<int, int>> udeps;

void dfs(int v, int p, int dup) {
  deps.clear();
  udeps.clear();
  if (dup) {
    deps.push_back(dup);
    udeps.push_back(make_pair(dup, v));
  }
  int mx[2] = {dup, -1};
  cnt[v] = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    int cur = dep[u] + 1;
    deps.push_back(cur);
    if (cur > mx[0]) {
      mx[1] = mx[0];
      mx[0] = cur;
    } else if (cur > mx[1]) {
      mx[1] = cur;
    }
    udeps.push_back(make_pair(cur, v));
    cnt[u] = 0;
    for (int j = 0; j < sz(g[u]); j++) {
      int w = g[u][j];
      if (w == v) {
        continue;
      }
      udeps.push_back(make_pair(dep[w] + 1, u));
    }
  }
  {
    sort(deps.begin(), deps.end(), greater<int>());
    for (int i = 0; i < sz(deps); i++) {
      int d = deps[i];
      ans[2 * d] = max(ans[2 * d], i + 1);
      ans[2 * d - 1] = max(ans[2 * d - 1], i + 1);
      if (i + 1 < sz(deps) && deps[i + 1] >= d - 1) {
        ans[2 * d - 1] = max(ans[2 * d - 1], i + 2);
      }
      if (i && deps[i - 1] >= d + 1) {
        ans[2 * d + 1] = max(ans[2 * d + 1], i + 1);
      }
    }
    sort(udeps.begin(), udeps.end(), greater<pair<int, int>>());
    int best = -1;
    for (int i = 0; i < sz(udeps); i++) {
      int d = udeps[i].first, u = udeps[i].second;
      cnt[u]++;
      if (u != v && (best == -1 || cnt[u] > cnt[best])) {
        best = u;
      }
      if (best != -1) {
        ans[2 * d] = max(ans[2 * d], (cnt[v] - 1) + cnt[best]);
      }
    }
    ans[1] = max(ans[1], sz(g[v]) + 1);
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    int nd = (mx[0] == dep[u] + 1 ? mx[1] : mx[0]) + 1;
    dfs(u, v, nd);
  }
}

void solve() {
  dfs0(0, -1);
  for (int i = 1; i <= n; i++) {
    ans[i] = 1;
  }
  dfs(0, -1, 0);
  for (int i = n - 2; i >= 1; i--) {
    ans[i] = max(ans[i], ans[i + 2]);
  }
  for (int i = 1; i <= n; i++) {
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