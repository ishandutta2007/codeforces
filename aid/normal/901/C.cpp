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

const int maxn = (int) 3e5 + 5;
int n, m;
vector<int> g[maxn];

int read() {
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
    g[u].push_back(v);
  }
  return true;
}

int used[maxn];
vector<int> path;
int rs[maxn];

void dfs(int v, int p) {
  used[v] = 1;
  path.push_back(v);
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    if (used[u] == 2) {
      continue;
    }
    if (used[u] == 1) {
      int pos = sz(path) - 1;
      int mn = u, mx = u;
      while (path[pos] != u) {
        mn = min(mn, path[pos]);
        mx = max(mx, path[pos]);
        pos--;
      }
      rs[mn] = mx;
      continue;
    }
    dfs(u, v);
  }
  path.pop_back();
  used[v] = 2;
}

vector<int> as[4 * maxn];
vector<long long> sums[4 * maxn];
long long all[4 * maxn];

void buildst(int v, int tl, int tr) {
  if (tl == tr - 1) {
    as[v] = {tr};
    sums[v] = {1};
    all[v] = 1;
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  int cur = as[2 * v + 1][0];
  as[v].clear();
  as[v].resize(tm - tl);
  sums[v].clear();
  sums[v].resize(tm - tl);
  all[v] = all[2 * v] + all[2 * v + 1];
  long long s = 0;
  for (int i = tm - 1; i >= tl; i--) {
    if (rs[i] != -1) {
      cur = min(cur, rs[i]);
    }
    as[v][i - tl] = cur;
    s += (cur < tm ? 0 : cur - tm);
    sums[v][i - tl] = s;
  }
  all[v] += s;
}

long long get(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return all[v];
  }
  int tm = (tl + tr) / 2;
  long long res = 0;
  if (l < tm) {
    res += get(2 * v, tl, tm, l, min(r, tm));
  }
  if (r > tm) {
    res += get(2 * v + 1, tm, tr, max(l, tm), r);
  }
  if (l < tm && r > tm) {
    int pos = lower_bound(as[v].begin(), as[v].end(), r) - as[v].begin() + tl;
    pos = max(pos, l);
    res += sums[v][l - tl] - (pos >= tm ? 0 : sums[v][pos - tl]);
    res += (long long) (tm - pos) * (r - tm);
  }
  return res;
}

void solve() {
  for (int i = 0; i < n; i++) {
    used[i] = 0;
    rs[i] = -1;
  }
  path.clear();
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i, -1);
    }
  }
  buildst(1, 0, n);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    long long res = get(1, 0, n, l, r);
    printf("%lld\n", res);
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