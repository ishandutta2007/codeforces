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

const int maxn = (int) 3e5 + 5;
int n, m;
vector<int> g[maxn];
vector<int> ids[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < 3 * n; i++) {
    g[i].clear();
    ids[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    ids[v].push_back(i);
    g[u].push_back(v);
    ids[u].push_back(i);
  }
  return true;
}

int used[maxn];
vector<int> mat;
vector<int> ind;

void solve() {
  for (int i = 0; i < 3 * n; i++) {
    used[i] = false;
  }
  mat.clear();
  for (int v = 0; v < 3 * n && sz(mat) < n; v++) {
    if (used[v]) {
      continue;
    }
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (used[u]) {
        continue;
      }
      mat.push_back(ids[v][i]);
      used[v] = true;
      used[u] = true;
      break;
    }
  }
  if (sz(mat) < n) {
    ind.clear();
    for (int i = 0; i < 3 * n && sz(ind) < n; i++) {
      if (!used[i]) {
        ind.push_back(i);
      }
    }
    printf("IndSet\n");
    for (int i = 0; i < n; i++) {
      printf("%d ", ind[i] + 1);
    }
    printf("\n");
    return;
  }
  printf("Matching\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", mat[i] + 1);
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