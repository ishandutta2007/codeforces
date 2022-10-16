#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int)1e5 + 5;
int n, m;
int used[maxn], col[maxn];
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

bool dfs(int v) {
  used[v] = true;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (used[u]) {
      if (col[u] == col[v]) {
        return false;
      }
    }
    else {
      col[u] = (col[v] ^ 1);
      if (!dfs(u)) {
        return false;
      }
    }
  }
  return true;
}

void solve() {
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      col[i] = 0;
      if (!dfs(i)) {
        printf("%d\n", -1);
        return;
      }
    }
  }
  for (int c = 0; c < 2; c++) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (col[i] == c) {
        ans.push_back(i);
      }
    }
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); i++) {
      printf("%d ", ans[i] + 1);
    }
    printf("\n");
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}