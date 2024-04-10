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

const int maxn = (int) 1e6 + 5;
int n, m;
vector<int> g[maxn], gr[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
    gr[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    gr[u].push_back(v);
  }
  return true;
}

int a[maxn];
int del[maxn];
set<int> alive;

void rec() {
  if (alive.empty()) {
    return;
  }
  int v = *alive.begin();
  alive.erase(alive.begin());
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    alive.erase(u);
  }
  rec();
  bool need = true;
  for (int i = 0; i < sz(gr[v]); i++) {
    int u = gr[v][i];
    if (a[u]) {
      need = false;
    }
  }
  if (need) {
    a[v] = true;
  }
}

void solve() {
  alive.clear();
  for (int i = 0; i < n; i++) {
    a[i] = false;
    del[i] = false;
    alive.insert(i);
  }
  rec();
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (a[i]) {
      ans.push_back(i);
    }
  }
  printf("%d\n", sz(ans));
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