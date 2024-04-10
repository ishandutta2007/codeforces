#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 1005, maxe = maxn * maxn;
int n, m, q, es;
int p[maxn], ts[maxn];
int used[maxn], col[maxn];
pair<pair<int, int>, pair<int, int> > e[maxe];
pair<int, pair<int, int> > ee[maxe];
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &m, &q) < 1) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &e[i].second.first, &e[i].second.second, &e[i].first.first);
    e[i].first.second = i;
    e[i].second.first--;
    e[i].second.second--;
  }
  return true;
}

int get(int x) {
  return p[x] == x? x : p[x] = get(p[x]);
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

void dfs(int v) {
  used[v] = true;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (used[u]) {
      continue;
    }
    col[u] = (col[v] ^ 1);
    dfs(u);
  }
}

int solve0() {
  for (int i = 0; i < n; i++) {
    p[i] = i;
    ts[i] = 1;
    g[i].clear();
    used[i] = false;
  }
  for (int i = es - 1; i >= 0; i--) {
    if (unite(ee[i].second.first, ee[i].second.second)) {
      g[ee[i].second.first].push_back(ee[i].second.second);
      g[ee[i].second.second].push_back(ee[i].second.first);
    }
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      col[i] = 0;
      dfs(i);
    }
  }
  for (int i = es - 1; i >= 0; i--) {
    if (col[ee[i].second.first] == col[ee[i].second.second]) {
      return ee[i].first;
    }
  }
  return -1;
}

void solve() {
  sort(e, e + m);
  for (int qq = 0; qq < q; qq++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    es = 0;
    for (int i = 0; i < m; i++) {
      if (l <= e[i].first.second && e[i].first.second < r) {
        ee[es] = make_pair(e[i].first.first, e[i].second);
        es++;
      }
    }
    printf("%d\n", solve0());
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}