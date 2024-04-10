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

const int maxn = 1005;
int n;
int deg[maxn];
vector<int> g[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    deg[i] = 0;
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    deg[v]++;
    g[v].push_back(u);
    deg[u]++;
    g[u].push_back(v);
  }
  return true;
}

int del[maxn];
vector<int> q;

int ask(int v, int u) {
  printf("? %d %d\n", v + 1, u + 1);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  res--;
  return res;
}

void printAns(int v) {
  printf("! %d\n", v + 1);
  fflush(stdout);
}

void delVer(int v) {
  del[v] = true;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (del[u]) {
      continue;
    }
    deg[u]--;
    if (deg[u] == 1) {
      q.push_back(u);
    }
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    del[i] = false;
  }
  q.clear();
  for (int i = 0; i < n; i++) {
    if (deg[i] == 1) {
      q.push_back(i);
    }
  }
  for (int l = 0; l < sz(q); l += 2) {
    int v = q[l];
    if (l + 1 >= sz(q)) {
      printAns(v);
      return;
    }
    int u = q[l + 1];
    int w = ask(v, u);
    if (w == v || w == u) {
      printAns(w);
      return;
    }
    delVer(v);
    delVer(u);
  }
  assert(false);
}

int main() {
  precalc();
  read();
  solve();
#ifdef DEBUG
  eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}