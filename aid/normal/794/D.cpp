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

const int maxn = (int) 3e5 + 5;
int n, m;
vector<int> g[maxn];

int read() {
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

vector<int> xs[2][maxn];
int s[2];
int ans[maxn];
int used[maxn];
int q[maxn];
int d[maxn];
int cnt[2 * maxn];

void solve() {
  for (s[0] = 0; s[0] < n && sz(g[s[0]]) >= n - 1; s[0]++) ;
  if (s[0] >= n) {
    printf("YES\n");
    for (int i = 0; i < n; i++) {
      printf("1 ");
    }
    printf("\n");
    return;
  }
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  used[s[0]] = true;
  for (int i = 0; i < sz(g[s[0]]); i++) {
    used[g[s[0]][i]] = true;
  }
  s[1] = 0;
  while (used[s[1]]) {
    s[1]++;
  }
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < n; i++) {
      used[i] = false;
    }
    int qr = 0;
    q[qr++] = s[t];
    d[s[t]] = 0;
    used[s[t]] = true;
    for (int ql = 0; ql < qr; ql++) {
      int v = q[ql];
      for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        if (!used[u]) {
          q[qr++] = u;
          d[u] = d[v] + 1;
          used[u] = true;
        }
      }
    }
    int sx = (!t ? maxn : xs[0][s[1]][0]);
    for (int i = 0; i < n; i++) {
      xs[t][i].clear();
      xs[t][i].push_back(sx - d[i]);
      xs[t][i].push_back(sx + d[i]);
      if (d[i] == 1) {
        xs[t][i].push_back(sx);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int x = -1;
    for (int j = 0; j < sz(xs[0][i]); j++) {
      for (int k = 0; k < sz(xs[1][i]); k++) {
        if (xs[0][i][j] == xs[1][i][k]) {
          x = xs[0][i][j];
        }
      }
    }
    if (x == -1) {
      printf("NO\n");
      return;
    }
    ans[i] = x;
  }
  for (int i = 0; i < 2 * maxn; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cnt[ans[i]]++;
  }
  for (int i = 0; i < n; i++) {
    if (cnt[ans[i] - 1] + cnt[ans[i]] + cnt[ans[i] + 1] != sz(g[i]) + 1) {
      printf("NO\n");
      return;
    }
    for (int j = 0; j < sz(g[i]); j++) {
      if (abs(ans[g[i][j]] - ans[i]) > 1) {
        printf("NO\n");
        return;
      }
    }
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
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