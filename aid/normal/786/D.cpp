#ifdef DEBUG
//#define _GLIBCXX_DEBUG
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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 2e4 + 5;
int n, m;
vector<int> g[maxn];
vector<char> gc[maxn];
int res[maxn];
vector< pair<int, int> > qs[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
    gc[i].clear();
    qs[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    char c;
    scanf("%d%d %c", &v, &u, &c);
    v--;
    u--;
    g[v].push_back(u);
    gc[v].push_back(c);
    g[u].push_back(v);
    gc[u].push_back(c);
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    qs[x].push_back(make_pair(y, i));
  }
  return true;
}

int p[maxn];
char pc[maxn];
int ts[maxn];

void dfs0(int v) {
  ts[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    char c = gc[v][i];
    if (u == p[v]) {
      continue;
    }
    p[u] = v;
    pc[u] = c;
    dfs0(u);
    ts[v] += ts[u];
  }
}

string s;

int get(int v, int dep) {
  int res = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p[v]) {
      continue;
    }
    char c = gc[v][i];
    if (c < s[dep]) {
      res += ts[u];
      continue;
    }
    if (c == s[dep]) {
      if (dep + 1 < sz(s)) {
        res++;
        res += get(u, dep + 1);
      }
    }
  }
  return res;
}

int q[maxn];
int d[maxn];
int used[maxn];
int curu;

int solve1(int v, int u) {
  curu++;
  s.clear();
  int r = 0;
  while (u != v) {
    s += pc[u];
    u = p[u];
    q[r++] = u;
    used[u] = curu;
  }
  reverse(s.begin(), s.end());
  reverse(q, q + r);
  for (int i = 0; i < r; i++) {
    d[i] = i;
  }
  int res = r - 1;
  for (int l = 0; l < r; l++) {
    int cur = q[l];
    int dep = d[l];
    for (int i = 0; i < sz(g[cur]); i++) {
      int nxt = g[cur][i];
      if (used[nxt] == curu) {
        continue;
      }
      char c = gc[cur][i];
      if (c == s[dep]) {
        if (dep + 1 < sz(s)) {
          res++;
          d[r] = dep + 1;
          q[r++] = nxt;
          used[nxt] = curu;
        }
      } else if (c < s[dep]) {
        res += ts[nxt];
        continue;
      }
    }
  }
  return res;
}

void solveAll(int v, int pr) {
  for (int i = 0; i < sz(qs[v]); i++) {
    res[qs[v][i].second] = solve1(v, qs[v][i].first);
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    char c = gc[v][i];
    if (u == pr) {
      continue;
    }
    p[v] = u;
    pc[v] = c;
    p[u] = -1;
    pc[u] = 0;
    ts[v] = n - ts[u];
    ts[u] = n;
    solveAll(u, v);
    p[u] = v;
    pc[u] = c;
    p[v] = -1;
    pc[v] = 0;
    ts[u] = n - ts[v];
    ts[v] = n;
  }
}

void solve() {
  p[0] = -1;
  pc[0] = 0;
  dfs0(0);
  solveAll(0, -1);
  for (int i = 0; i < m; i++) {
    printf("%d\n", res[i]);
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