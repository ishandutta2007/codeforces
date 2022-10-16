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
vector<pair<int, int>> g[maxn];
int s[maxn], t[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    v--;
    u--;
    g[v].push_back(make_pair(u, w));
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &s[i], &t[i]);
    s[i]--;
  }
  return true;
}

long long dep[maxn];
int ts[maxn];
int p[maxn];
int heavy[maxn];
int tin[maxn], tout[maxn], tt;
int go[maxn];

void dfs0(int v) {
  ts[v] = 1;
  heavy[v] = -1;
  tin[v] = tt++;
  go[v] = -1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, w = g[v][i].second;
    dep[u] = dep[v] + w;
    p[u] = v;
    dfs0(u);
    ts[v] += ts[u];
    if (heavy[v] == -1 || ts[u] > ts[heavy[v]]) {
      heavy[v] = u;
    }
    go[v] = u;
  }
  tout[v] = tt;
}

int root[maxn];
set<pair<long long, int>> out[maxn];

long long st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v] = -infll;
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void update(int v, int tl, int tr, int pos, long long x) {
  if (tl == tr - 1) {
    st[v] = max(st[v], x);
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    update(2 * v, tl, tm, pos, x);
  } else {
    update(2 * v + 1, tm, tr, pos, x);
  }
  st[v] = max(st[2 * v], st[2 * v + 1]);
}

long long get(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v];
  }
  int tm = (tl + tr) / 2;
  long long res = -infll;
  if (l < tm) {
    res = max(res, get(2 * v, tl, tm, l, min(r, tm)));
  }
  if (r > tm) {
    res = max(res, get(2 * v + 1, tm, tr, max(l, tm), r));
  }
  return res;
}

vector<pair<long long, long long>> segs;
multiset<long long> op;

void solve() {
  dep[0] = 0;
  p[0] = -1;
  tt = 0;
  dfs0(0);
  for (int s = 0; s < n; s++) {
    if (p[s] != -1 && heavy[p[s]] == s) {
      continue;
    }
    out[s].clear();
    for (int v = s; v != -1; v = heavy[v]) {
      root[v] = s;
      if (go[v] != -1 && go[v] != heavy[v]) {
        out[s].insert(make_pair(dep[v], v));
      }
    }
  }
  segs.clear();
  buildst(1, 0, n);
  for (int q = 0; q < m; q++) {
    int v = s[q], t = ::t[q];
    while (v != -1) {
      int rt = root[v];
      while (!out[rt].empty() && out[rt].begin()->first < dep[v]) {
        int u = out[rt].begin()->second;
        out[rt].erase(out[rt].begin());
        go[u] = heavy[u];
        long long l = max(1ll, dep[u] + get(1, 0, n, tin[u] + 1, tout[u]) + 1);
        long long r = dep[u] + t + 1;
        segs.push_back(make_pair(l, r));
      }
      v = p[rt];
      if (v == -1) {
        break;
      }
      if (go[v] != rt) {
        out[root[v]].insert(make_pair(dep[v], v));
        go[v] = rt;
        long long l = max(1ll, dep[v] + get(1, 0, n, tin[v] + 1, tout[v]) + 1);
        long long r = dep[v] + t + 1;
        segs.push_back(make_pair(l, r));
      }
    }
    update(1, 0, n, tin[s[q]], t);
  }
  sort(segs.begin(), segs.end());
  long long t = 1;
  op.clear();
  for (int i = 0; i < sz(segs); i++) {
    long long tt = segs[i].first;
    while (t < tt && !op.empty()) {
      auto cur = *op.begin();
      op.erase(op.begin());
      if (t >= cur) {
        int cnt = 0;
        for (int j = 0; j < sz(segs); j++) {
          if (segs[j].second < cur) {
            cnt++;
          }
        }
        printf("%lld %d\n", cur - 1, cnt);
        return;
      }
      t++;
    }
    t = tt;
    op.insert(segs[i].second);
  }
  while (!op.empty()) {
    auto cur = *op.begin();
    op.erase(op.begin());
    if (t >= cur) {
      int cnt = 0;
      for (int j = 0; j < sz(segs); j++) {
        if (segs[j].second < cur) {
          cnt++;
        }
      }
      printf("%lld %d\n", cur - 1, cnt);
      return;
    }
    t++;
  }
  printf("-1 %d\n", sz(segs));
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