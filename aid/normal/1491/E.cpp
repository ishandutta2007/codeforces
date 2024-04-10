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

const int maxk = 30;
const int maxn = (int) 2e5 + 5;
int fib[maxk];
int fid[maxn];

void precalc() {
  for (int i = 0; i < maxn; ++i) {
    fid[i] = -1;
  }
  fib[0] = 0;
  fib[1] = 1;
  fid[0] = 0;
  fid[1] = 1;
  for (int i = 2; i < maxk; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
    if (fib[i] < maxn) {
      fid[fib[i]] = i;
    }
  }
}

int n;
vector<int> g[maxn], ids[maxn];
int es[maxn][2];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    g[i].clear();
    ids[i].clear();
  }
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    g[v].push_back(u);
    ids[v].push_back(i);
    g[u].push_back(v);
    ids[u].push_back(i);
    es[i][0] = v;
    es[i][1] = u;
  }
  return true;
}

int del[maxn];
int ts[maxn];
int eans[maxn];
int used[maxn];
int curu;

void dfs(int v, int p, int pe) {
  ts[v] = 1;
  for (int i = 0; i < sz(g[v]); ++i) {
    int e = ids[v][i];
    int u = g[v][i];
    if (del[e] || u == p) {
      continue;
    }
    dfs(u, v, e);
    ts[v] += ts[u];
  }
  eans[ts[v]] = pe;
  used[ts[v]] = curu;
}

bool rec(int v) {
  ++curu;
  dfs(v, -1, -1);
  if (ts[v] <= 2) {
    return true;
  }
  int k = fid[ts[v]];
  int e = (used[fib[k - 1]] == curu ? eans[fib[k - 1]] : (used[fib[k - 2]] == curu ? eans[fib[k - 2]] : -1));
  if (e == -1) {
    return false;
  }
  del[e] = true;
  return rec(es[e][0]) && rec(es[e][1]);
}

void solve() {
  if (fid[n] == -1) {
    printf("NO\n");
    return;
  }
  for (int i = 0; i < n - 1; ++i) {
    del[i] = false;
  }
  if (rec(0)) {
    printf("YES\n");
  }  else {
    printf("NO\n");
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