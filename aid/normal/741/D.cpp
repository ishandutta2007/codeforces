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

const int maxn = (int) 5e5 + 5;
int n;
int a[maxn];
int dep[maxn];
vector<int> g[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  a[0] = 0;
  dep[0] = 0;
  for (int i = 1; i < n; i++) {
    int p;
    char c;
    scanf("%d %c", &p, &c);
    p--;
    a[i] = (a[p] ^ (1 << (c - 'a')));
    dep[i] = dep[p] + 1;
    g[p].push_back(i);
  }
  return true;
}

int ts[maxn];

void getTs(int v) {
  ts[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    getTs(u);
    ts[v] += ts[u];
  }
}

const int sigma = 22;
const int maxx = (1 << sigma);
int d[maxx];
vector<int> *sub[maxn];
int ans[maxn];

void dfs(int v) {
  for (int i = 1; i < sz(g[v]); i++) {
    if (ts[g[v][i]] > ts[g[v][0]]) {
      swap(g[v][i], g[v][0]);
    }
  }
  ans[v] = 0;
  for (int i = 1; i < sz(g[v]); i++) {
    int u = g[v][i];
    dfs(u);
    ans[v] = max(ans[v], ans[u]);
    for (auto w : *sub[u]) {
      d[a[w]] = -inf;
    }
  }
  if (!g[v].empty()) {
    int u = g[v][0];
    dfs(u);
    ans[v] = max(ans[v], ans[u]);
    sub[v] = sub[u];
  } else {
    sub[v] = new vector<int>();
  }
  for (int i = 1; i < sz(g[v]); i++) {
    int u = g[v][i];
    for (auto w : *sub[u]) {
      for (int c = 0; c <= sigma; c++) {
        int msk = (a[w] ^ (c < sigma ? (1 << c) : 0));
        ans[v] = max(ans[v], d[msk] + dep[w] - 2 * dep[v]);
      }
    }
    for (auto w : *sub[u]) {
      d[a[w]] = max(d[a[w]], dep[w]);
      sub[v]->push_back(w);
    }
  }
  {
    for (int c = 0; c <= sigma; c++) {
      int msk = (a[v] ^ (c < sigma ? (1 << c) : 0));
      ans[v] = max(ans[v], d[msk] - dep[v]);
    }
    d[a[v]] = max(d[a[v]], dep[v]);
    sub[v]->push_back(v);
  }
}

void solve() {
  getTs(0);
  for (int i = 0; i < maxx; i++) {
    d[i] = -inf;
  }
  dfs(0);
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
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