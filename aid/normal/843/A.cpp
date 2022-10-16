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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e5 + 5;
int n;
int a[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int tosort[maxn];
vector<int> g[maxn];
int used[maxn];

void dfs(int v, vector<int> &a) {
  a.push_back(v);
  used[v] = true;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (used[u]) {
      continue;
    }
    dfs(u, a);
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    tosort[i] = a[i];
  }
  sort(tosort, tosort + n);
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(tosort, tosort + n, a[i]) - tosort;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
    used[i] = false;
  }
  for (int i = 0; i < n; i++) {
    int v = i, u = a[i];
    g[v].push_back(u);
    g[u].push_back(v);
  }
  vector< vector<int> > ans;
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    ans.push_back(vector<int>());
    dfs(i, ans.back());
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d ", sz(ans[i]));
    for (int j = 0; j < sz(ans[i]); j++) {
      printf("%d ", ans[i][j] + 1);
    }
    printf("\n");
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