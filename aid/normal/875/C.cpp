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

const int maxn = (int) 1e5 + 5;
int n, m;
vector<int> as[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    int len;
    scanf("%d", &len);
    as[i].resize(len);
    for (int j = 0; j < len; j++) {
      scanf("%d", &as[i][j]);
      as[i][j]--;
    }
  }
  return true;
}

int ans[maxn];
vector<int> g[maxn];

bool dfs(int v) {
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (ans[u] == 0) {
      return false;
    }
    if (ans[u] == 1) {
      continue;
    }
    ans[u] = 1;
    if (!dfs(u)) {
      return false;
    }
  }
  return true;
}

void solve() {
  for (int i = 0; i < m; i++) {
    ans[i] = -1;
    g[i].clear();
  }
  for (int i = 0; i + 1 < n; i++) {
    int j = 0;
    while (j < sz(as[i]) && j < sz(as[i + 1]) && as[i][j] == as[i + 1][j]) {
      j++;
    }
    if (j >= sz(as[i])) {
      continue;
    }
    if (j >= sz(as[i + 1])) {
      printf("No\n");
      return;
    }
    int a = as[i][j], b = as[i + 1][j];
    if (a > b) {
      if (ans[b] == 1) {
        printf("No\n");
        return;
      }
      ans[b] = 0;
      if (ans[a] == 0) {
        printf("No\n");
        return;
      }
      ans[a] = 1;
    } else {
      g[b].push_back(a);
    }
  }
  for (int i = 0; i < m; i++) {
    if (ans[i] == 1) {
      if (!dfs(i)) {
        printf("No\n");
        return;
      }
    }
  }
  vector<int> a;
  for (int i = 0; i < m; i++) {
    if (ans[i] == 1) {
      a.push_back(i);
    }
  }
  printf("Yes\n%d\n", sz(a));
  for (int i = 0; i < sz(a); i++) {
    printf("%d ", a[i] + 1);
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