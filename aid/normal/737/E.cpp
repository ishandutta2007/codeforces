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

const int maxn = 45;
int n, m, b;
int c[maxn];
int w[maxn][maxn];

int read() {
  if (scanf("%d%d%d", &n, &m, &b) < 3) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &c[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * m; j++) {
      w[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      int id, t;
      scanf("%d%d", &id, &t);
      id--;
      w[i][2 * id] = t;
    }
  }
  return true;
}

int maxdeg;
int take[maxn];
vector< pair<pair<int, int>, pair<int, int> > > ans;
vector<int> g[2][maxn];
int p[2][maxn];
int deg[2][maxn];
int used[maxn];

bool dfs(int t, int v) {
  used[v] = true;
  for (int i = 0; i < sz(g[t][v]); i++) {
    int u = g[t][v][i];
    if (p[!t][u] == -1 || deg[t][p[!t][u]] < maxdeg) {
      if (p[!t][u] != -1) {
        p[t][p[!t][u]] = -1;
      }
      p[!t][u] = v;
      p[t][v] = u;
      return true;
    }
  }
  for (int i = 0; i < sz(g[t][v]); i++) {
    int u = g[t][v][i];
    if (!used[p[!t][u]] && dfs(t, p[!t][u])) {
      p[!t][u] = v;
      p[t][v] = u;
      return true;
    }
  }
  return false;
}

void solve() {
  for (int i = 0; i < m; i++) {
    take[i] = false;
  }
  while (true) {
    bool change = false;
    int t = 0;
    for (int i = 0; i < n; i++) {
      int cur = 0;
      for (int j = 0; j < 2 * m; j++) {
        cur += w[i][j];
      }
      t = max(t, cur);
    }
    for (int i = 0; i < 2 * m; i++) {
      int cur = 0;
      for (int j = 0; j < n; j++) {
        cur += w[j][i];
      }
      t = max(t, cur);
    }
    for (int i = 0; i < m; i++) {
      if (take[i] || c[i] > b) {
        continue;
      }
      int cur = 0;
      for (int j = 0; j < n; j++) {
        cur += w[j][2 * i];
      }
      if (cur < t) {
        continue;
      }
      int tomove = t / 2;
      for (int j = 0; j < n; j++) {
        int x = min(tomove, w[j][2 * i]);
        w[j][2 * i] -= x;
        w[j][2 * i + 1] += x;
        tomove -= x;
      }
      take[i] = true;
      b -= c[i];
      change = true;
    }
    if (!change) {
      break;
    }
  }
  ans.clear();
  int t = 0;
  while (true) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < max(n, 2 * m); j++) {
        g[i][j].clear();
        p[i][j] = -1;
        deg[i][j] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 2 * m; j++) {
        deg[0][i] += w[i][j];
        deg[1][j] += w[i][j];
        if (w[i][j]) {
          g[0][i].push_back(j);
          g[1][j].push_back(i);
        }
      }
    }
    maxdeg = 0;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < max(n, 2 * m); j++) {
        maxdeg = max(maxdeg, deg[i][j]);
      }
    }
    if (!maxdeg) {
      break;
    }
    for (int i = 0; i < 2; i++) {
      int vs = (i ? 2 * m : n);
      for (int j = 0; j < vs; j++) {
        if (deg[i][j] == maxdeg && p[i][j] == -1) {
          for (int k = 0; k < vs; k++) {
            used[k] = false;
          }
          dfs(i, j);
        }
      }
    }
    int ndeg = 0;
    for (int i = 0; i < 2; i++) {
      int vs = (i ? 2 * m : n);
      for (int j = 0; j < vs; j++) {
        if (p[i][j] == -1) {
          ndeg = max(ndeg, deg[i][j]);
        }
      }
    }
    int minw = inf;
    for (int i = 0; i < n; i++) {
      if (p[0][i] != -1) {
        minw = min(minw, w[i][p[0][i]]);
      }
    }
    int curt = min(minw, maxdeg - ndeg);
    for (int i = 0; i < n; i++) {
      if (p[0][i] != -1) {
        ans.push_back(make_pair(make_pair(i + 1, p[0][i] / 2 + 1), make_pair(t, curt)));
        w[i][p[0][i]] -= curt;
      }
    }
    t += curt;
  }
  printf("%d\n", t);
  for (int i = 0; i < m; i++) {
    printf("%d", take[i]);
  }
  printf("\n%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d %d %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second.first, ans[i].second.second);
  }
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
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}