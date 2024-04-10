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
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
  }
  return true;
}

int used[maxn];
int tin[maxn], tout[maxn], t;

void dfs0(int v) {
  used[v] = true;
  tin[v] = t++;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (!used[u]) {
      dfs0(u);
    }
  }
  tout[v] = t;
}

bool anc(int v, int u) {
  return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int incnt[maxn];
int cnt[maxn], tov[maxn];
int go[maxn];

bool dfs1(int v) {
  used[v] = true;
  cnt[v] = 0;
  tov[v] = v;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (used[u]) {
      if (!anc(u, v)) {
        return false;
      }
      incnt[u]++;
      cnt[v]++;
      if (anc(u, tov[v])) {
        tov[v] = u;
      }
    } else {
      if (!dfs1(u)) {
        return false;
      }
      cnt[v] += cnt[u];
      if (anc(tov[u], tov[v])) {
        tov[v] = tov[u];
      }
    }
  }
  cnt[v] -= incnt[v];
  go[v] = (cnt[v] == 1 ? tov[v] : -1);
  return true;
}

int good[maxn];

void dfs2(int v) {
  used[v] = true;
  if (go[v] == v) {
    good[v] = true;
  } else if (go[v] == -1) {
    good[v] = false;
  } else {
    good[v] = good[go[v]];
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (!used[u]) {
      dfs2(u);
    }
  }
}

vector<int> ans;

bool solve1(int s) {
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  t = 0;
  dfs0(s);
  for (int i = 0; i < n; i++) {
    used[i] = false;
    incnt[i] = 0;
  }
  if (!dfs1(s)) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  go[s] = s;
  dfs2(s);
  ans.clear();
  for (int i = 0; i < n; i++) {
    if (good[i]) {
      ans.push_back(i);
    }
  }
  if (sz(ans) * 5 < n) {
    printf("-1\n");
  } else {
    for (int i = 0; i < sz(ans); i++) {
      printf("%d ", ans[i] + 1);
    }
    printf("\n");
  }
  return true;
}

const int K = 70;

void solve() {
  for (int it = 0; it < K; it++) {
    int s = rnd(n);
    if (solve1(s)) {
      return;
    }
  }
  printf("-1\n");
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