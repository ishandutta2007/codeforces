
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define TASK "text"

const int inf = (int)1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld)-1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 2e5 + 5;
int n;
int col[maxn];
vector<int> g[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &col[i]);
    if (col[i] == -1) {
      col[i] = 0;
    }
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

void dfs(int v, int p) {
  printf("%d ", v + 1);
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    col[u] ^= 1;
    dfs(u, v);
  }
  if (p == -1) {
    if (!col[v]) {
      int u = g[v][0];
      printf("%d ", u + 1);
      printf("%d ", v + 1);
      printf("%d\n", u + 1);
      col[v] ^= 1;
    }
    else {
      printf("\n");
    }
  }
  else {
    if (!col[v]) {
      printf("%d ", p + 1);
      printf("%d ", v + 1);
      printf("%d ", p + 1);
      col[v] ^= 1;
    }
    else {
      printf("%d ", p + 1);
      col[p] ^= 1;
    }
  }
}

void solve() {
  bool allb = true;
  for (int i = 0; i < n; i++) {
    if (!col[i]) {
      allb = false;
      break;
    }
  }
  if (allb) {
    printf("1\n");
    return;
  }
  dfs(0, -1);
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}