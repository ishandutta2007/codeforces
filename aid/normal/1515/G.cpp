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

long long gcd(long long a, long long b) {
  return (b ? gcd(b, a % b) : a);
}

const int maxn = (int) 2e5 + 5;
int n, m;
vector<pair<int, int>> g[maxn], gr[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    g[i].clear();
    gr[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    --v;
    --u;
    g[v].push_back(make_pair(u, w));
    gr[u].push_back(make_pair(v, w));
  }
  return true;
}

int used[maxn];
vector<int> p;

void dfs0(int v) {
  used[v] = true;
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i].first;
    if (!used[u]) {
      dfs0(u);
    }
  }
  p.push_back(v);
}

int c[maxn];
int cs;

void dfs1(int v, int col) {
  c[v] = col;
  for (int i = 0; i < sz(gr[v]); ++i) {
    int u = gr[v][i].first;
    if (c[u] == -1) {
      dfs1(u, col);
    }
  }
}

long long val[maxn];
long long d[maxn];

void dfs(int v) {
  used[v] = true;
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i].first, w = g[v][i].second;
    if (c[u] != c[v]) {
      continue;
    }
    if (!used[u]) {
      d[u] = d[v] + w;
      dfs(u);
    } else {
      long long cur = abs(d[u] - d[v] - w);
      val[c[v]] = gcd(val[c[v]], cur);
    }
  }
}

void solve() {
  for (int i = 0; i < n; ++i) {
    used[i] = false;
    c[i] = -1;
  }
  p.clear();
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      dfs0(i);
    }
  }
  cs = 0;
  for (int i = n - 1; i >= 0; --i) {
    int v = p[i];
    if (c[v] == -1) {
      dfs1(v, cs++);
    }
  }
  for (int i = 0; i < n; ++i) {
    used[i] = false;
  }
  for (int i = 0; i < n; ++i) {
    if (used[i]) {
      continue;
    }
    int cid = c[i];
    val[cid] = 0;
    d[i] = 0;
    dfs(i);
  }
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; ++qq) {
    int v, s, t;
    scanf("%d%d%d", &v, &s, &t);
    --v;
    if (s == 0) {
      printf("YES\n");
      continue;
    }
    int cid = c[v];
    if (!val[cid]) {
      printf("NO\n");
      continue;
    }
    int x = gcd(val[cid], (long long) t);
    if (s % x) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
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