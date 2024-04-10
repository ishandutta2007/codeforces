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

const int maxn = (int) 5e5 + 5;
int n, m;
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

int used[maxn];
int ise[maxn];
int curu;
int curx;
int p[maxn], q[maxn];
vector<int> alive, nalive;

bool dfs(int v, int pr, bool isroot = false) {
  used[v] = true;
  vector<int> ch;
  ++curu;
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    ise[u] = curu;
  }
  nalive.clear();
  for (int i = 0; i < sz(alive); ++i) {
    int u = alive[i];
    if (u == v) {
      continue;
    }
    if (ise[u] == curu) {
      nalive.push_back(u);
      continue;
    }
    ch.push_back(u);
  }
  alive = nalive;
  vector<int> a;
  if (pr != -1) {
    a.push_back(pr);
  }
  for (int i = 0; i < sz(ch); ++i) {
    int u = ch[i];
    int npr = -1;
    if (isroot && a.empty() && i + 1 >= sz(ch)) {
      npr = v;
    }
    if (!dfs(u, npr)) {
      a.push_back(u);
    }
    if (npr != -1) {
      return true;
    }
  }
  if (a.empty()) {
    return false;
  }
  a.push_back(v);
  for (int i = 0; i < sz(a); ++i) {
    p[a[i]] = curx + i;
  }
  for (int i = 0; i + 1 < sz(a); ++i) {
    q[a[i]] = curx + i + 1;
  }
  q[a.back()] = curx;
  curx += sz(a);
  return true;
}

void solve() {
  alive.clear();
  for (int i = 0; i < n; ++i) {
    used[i] = false;
    alive.push_back(i);
  }
  curx = 0;
  for (int i = 0; i < n; ++i) {
    if (used[i]) {
      continue;
    }
    if (!dfs(i, -1, true)) {
      p[i] = curx;
      q[i] = curx;
      ++curx;
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", p[i] + 1);
  }
  printf("\n");
  for (int i = 0; i < n; ++i) {
    printf("%d ", q[i] + 1);
  }
  printf("\n");
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