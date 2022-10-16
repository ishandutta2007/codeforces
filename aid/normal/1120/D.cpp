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
int n;
int c[maxn];
vector<int> g[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
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

int ls[maxn], rs[maxn];
int t;

void dfs(int v, int p) {
  ls[v] = t;
  bool leaf = true;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    leaf = false;
    dfs(u, v);
  }
  if (leaf) {
    t++;
  }
  rs[v] = t;
}

pair<int, int> es[maxn];
int p[maxn], ts[maxn];

int get(int x) {
  return (p[x] == x ? x : p[x] = get(p[x]));
}

void unite(int x, int y) {
  x = get(x);
  y = get(y);
  if (ts[x] < ts[y]) {
    swap(x, y);
  }
  ts[x] += ts[y];
  p[y] = x;
}

void solve() {
  t = 0;
  dfs(0, -1);
  t++;
  for (int i = 0; i < n; i++) {
    es[i] = make_pair(c[i], i);
  }
  sort(es, es + n);
  for (int i = 0; i < t; i++) {
    p[i] = i;
    ts[i] = 1;
  }
  vector<int> ans;
  long long res = 0;
  for (int j = 0; j < n;) {
    int i = j;
    while (j < n && es[j].first == es[i].first) {
      j++;
    }
    for (int k = i; k < j; k++) {
      int id = es[k].second;
      if (get(ls[id]) != get(rs[id])) {
        ans.push_back(id);
      }
    }
    for (int k = i; k < j; k++) {
      int id = es[k].second;
      if (get(ls[id]) != get(rs[id])) {
        res += c[id];
        unite(ls[id], rs[id]);
      }
    }
  }
  sort(ans.begin(), ans.end());
  printf("%lld %d\n", res, sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d ", ans[i] + 1);
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