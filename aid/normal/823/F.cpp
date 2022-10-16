#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const ld pi = acos((ld) -1);
const int inf = (int) 1.01e9;
const ld eps = 1e-12;

#define sz(a) (int) (a).size()

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

mt19937 mrand(random_device{} ());

int rnd(int x) {
  return mrand() % x;
}

const int maxn = (int) 1e5 + 5;
int n, m;
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
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

int used[maxn];
int ans[maxn];

bool getCycle(int v, int p) {
  used[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p || used[u] == 2) {
      continue;
    }
    if (used[u] == 1) {
      return true;
    }
    if (getCycle(u, v)) {
      return true;
    }
  }
  used[v] = 2;
  return false;
}

void dfs1(int v) {
  ans[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (ans[u]) {
      continue;
    }
    dfs1(u);
  }
}

bool dfs3(int v, int p) {
  if (p != -1 && sz(g[v]) >= 3) {
    ans[v] = 2;
    int need = 2;
    for (int i = 0; i < sz(g[v]) && need; i++) {
      int u = g[v][i];
      if (u == p) {
        continue;
      }
      ans[u] = 1;
      need--;
    }
    assert(!need);
    return true;
  }
  bool ok = false;
  int nv = -1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    if (dfs3(u, v)) {
      ok = true;
      nv = u;
      break;
    }
  }
  if (!ok) {
    return false;
  }
  ans[v] = 2;
  if (p == -1) {
    int need = 2;
    for (int i = 0; i < sz(g[v]) && need; i++) {
      int u = g[v][i];
      if (u == nv) {
        continue;
      }
      ans[u] = 1;
      need--;
    }
    assert(!need);
  }
  return true;
}

void printAns() {
  ll res = 0;
  bool was = false;
  for (int i = 0; i < n; i++) {
    if (ans[i]) {
      was = true;
    }
    assert(ans[i] >= 0);
    res -= 2 * ans[i] * (ll) ans[i];
    for (int j = 0; j < sz(g[i]); j++) {
      res += ans[i] * (ll) ans[g[i][j]];
    }
  }
  assert(res >= 0);
  assert(was);
  printf("YES\n");
  for (int j = 0; j < n; j++) {
    printf("%d ", ans[j]);
  }
  printf("\n");
}

vector<int> ps[3];

void getP(int v, int p, vector<int> &path) {
  path.push_back(v);
  assert(sz(g[v]) <= 2);
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    getP(u, v, path);
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    used[i] = 0;
    ans[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    if (getCycle(i, -1)) {
      dfs1(i);
      printAns();
      return;
    }
  }
  for (int v = 0; v < n; v++) {
    if (sz(g[v]) >= 4) {
      ans[v] = 2;
      for (int i = 0; i < 4; i++) {
        int u = g[v][i];
        ans[u] = 1;
      }
      printAns();
      return;
    }
  }
  for (int v = 0; v < n; v++) {
    if (sz(g[v]) >= 3) {
      if (dfs3(v, -1)) {
        printAns();
        return;
      }
    }
  }
  for (int v = 0; v < n; v++) {
    if (sz(g[v]) == 3) {
      for (int i = 0; i < 3; i++) {
        int u = g[v][i];
        ps[i].clear();
        getP(u, v, ps[i]);
      }
      for (int a = 1; a <= min(10, sz(ps[0])); a++) {
        for (int b = 1; b <= min(10, sz(ps[1])); b++) {
          for (int c = 1; c <= min(10, sz(ps[2])); c++) {
            if (2 * a / (ld) (a + 1) + 2 * b / (ld) (b + 1) + 2 * c / (ld) (c + 1) >= 4 - eps) {
              eprintf("%d %d %d\n", a, b, c);
              ans[v] = (a + 1) * (b + 1) * (c + 1);
              for (int i = 0; i < a; i++) {
                ans[ps[0][i]] = (a - i) * (b + 1) * (c + 1);
              }
              for (int i = 0; i < b; i++) {
                ans[ps[1][i]] = (b - i) * (a + 1) * (c + 1);
              }
              for (int i = 0; i < c; i++) {
                ans[ps[2][i]] = (c - i) * (a + 1) * (b + 1);
              }
              printAns();
              return;
            }
          }
        }
      }
    }
  }
  printf("NO\n");
}

int main() {
#ifdef DEBUG
  freopen("text.out", "w", stdout);
  assert(freopen("text.in", "r", stdin));
#endif

  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
    eprintf("Time: %.3fs\n", (double) clock() / CLOCKS_PER_SEC);
  }

  return 0;
}