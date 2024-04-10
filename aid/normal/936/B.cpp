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

const int maxn = (int) 2e5 + 5;
int n, m;
vector<int> g[maxn];
int s;

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < 2 * n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      int to;
      scanf("%d", &to);
      to--;
      g[2 * i].push_back(2 * to + 1);
      g[2 * i + 1].push_back(2 * to);
    }
  }
  scanf("%d", &s);
  s--;
  s *= 2;
  return true;
}

int used[maxn];
bool draw;
vector<int> path;

bool dfs(int v) {
  used[v] = 1;
  path.push_back(v);
  if ((v & 1) && g[v].empty()) {
    return true;
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (used[u] == 1) {
      draw = true;
    }
    if (used[u]) {
      continue;
    }
    if (dfs(u)) {
      return true;
    }
  }
  used[v] = 2;
  path.pop_back();
  return false;
}

void solve() {
  for (int i = 0; i < 2 * n; i++) {
    used[i] = 0;
  }
  path.clear();
  draw = false;
  if (dfs(s)) {
    printf("Win\n");
    for (int i = 0; i < sz(path); i++) {
      printf("%d ", path[i] / 2 + 1);
    }
    printf("\n");
    return;
  }
  if (draw) {
    printf("Draw\n");
    return;
  }
  printf("Lose\n");
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