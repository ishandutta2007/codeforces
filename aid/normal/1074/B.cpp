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

const int maxn = 1005;
int n;
vector<int> g[maxn];
vector<int> vs[2];

int read() {
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
  for (int t = 0; t < 2; t++) {
    int k;
    scanf("%d", &k);
    vs[t].resize(k);
    for (int i = 0; i < k; i++) {
      scanf("%d", &vs[t][i]);
      vs[t][i]--;
    }
  }
  return true;
}

int good[maxn];

int dfs(int v, int p) {
  if (good[v]) {
    return v;
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    int cur = dfs(u, v);
    if (cur != -1) {
      return cur;
    }
  }
  return -1;
}

int ask(int t, int v) {
  printf("%c %d\n", (char) ('A' + t), v + 1);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  res--;
  return res;
}

void solve() {
  for (int i = 0; i < n; i++) {
    good[i] = false;
  }
  for (int i = 0; i < sz(vs[0]); i++) {
    good[vs[0][i]] = true;
  }
  int v = ask(1, vs[1][0]);
  int u = dfs(v, -1);
  assert(u != -1);
  int u1 = ask(0, u);
  for (int i = 0; i < sz(vs[1]); i++) {
    if (vs[1][i] == u1) {
      printf("C %d\n", u + 1);
      fflush(stdout);
      return;
    }
  }
  printf("C -1\n");
  fflush(stdout);
}

int main() {
  precalc();
  int t;
  scanf("%d", &t);
  for (int tt = 0; tt < t; tt++) {
    assert(read());
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}