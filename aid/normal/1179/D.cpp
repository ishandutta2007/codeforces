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

struct line {
  long long a, b;

  line(long long _a, long long _b): a(_a), b(_b) {}

  long long eval(long long x) {
    return a * x + b;
  }
};

bool bad(const line &l0, const line &l1, const line &l2) {
  return (l1.b - l0.b) * (l1.a - l2.a) >= (l2.b - l1.b) * (l0.a - l1.a);
}

vector<line> ls;
int pos;

void add(const line &l) {
  if (sz(ls) >= 1 && ls.back().a == l.a) {
    if (ls.back().b <= l.b) {
      return;
    }
    ls.pop_back();
  }
  while (sz(ls) >= 2 && bad(l, ls[sz(ls) - 1], ls[sz(ls) - 2])) {
    ls.pop_back();
  }
  if (pos >= sz(ls) - 1) {
    pos = sz(ls);
  }
  ls.push_back(l);
}

long long getVal(long long x) {
  while (pos > 0 && ls[pos - 1].eval(x) < ls[pos].eval(x)) {
    pos--;
  }
  return ls[pos].eval(x);
}

int ts[maxn];
long long dp[maxn];
long long res;
vector<pair<int, int>> tosort;

void dfs(int v, int p) {
  ts[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs(u, v);
    ts[v] += ts[u];
  }
  dp[v] = (long long) ts[v] * ts[v];
  tosort.clear();
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    int x = ts[v] - ts[u];
    dp[v] = min(dp[v], dp[u] + (long long) x * x);
    tosort.push_back(make_pair(ts[u], u));
  }
  sort(tosort.begin(), tosort.end());
  ls.clear();
  for (int i = 0; i < sz(tosort); i++) {
    int u = tosort[i].second;
    if (!ls.empty()) {
      long long cur = getVal(ts[u]) + dp[u] + (long long) n * n - 2ll * n * ts[u] + (long long) ts[u] * ts[u];
      if (cur < res) {
        res = cur;
      }
    }
    add(line(2 * ts[u], dp[u] - 2ll * n * ts[u] + (long long) ts[u] * ts[u]));
  }
}

void solve() {
  if (n == 2) {
    printf("%d\n", 2);
    return;
  }
  int root = 0;
  while (sz(g[root]) == 1) {
    root++;
  }
  res = (long long) n * n;
  dfs(root, -1);
  res = (long long) n * (n - 1) / 2 + ((long long) n * n - res) / 2;
  printf("%lld\n", res);
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