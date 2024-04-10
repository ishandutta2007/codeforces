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

const int maxn = (int) 1e3 + 5;
int n;
int x[maxn], y[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  return true;
}

vector<int> xs, ys;
int id[maxn][maxn];
int who[maxn][maxn];
int p[maxn];
int q[maxn];
int used[maxn];
vector<int> g[maxn];

bool dfs(int v) {
  used[v] = true;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (p[u] == -1) {
      p[u] = v;
      q[v] = u;
      return true;
    }
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (!used[p[u]] && dfs(p[u])) {
      p[u] = v;
      q[v] = u;
      return true;
    }
  }
  return false;
}

void dfs0(int v) {
  used[v] = true;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    assert(p[u] != -1);
    if (!used[p[u]]) {
      dfs0(p[u]);
    }
  }
}

void solve() {
  xs.clear();
  ys.clear();
  for (int i = 0; i < n; i++) {
    xs.push_back(x[i]);
    ys.push_back(y[i]);
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());
  for (int i = 0; i < n; i++) {
    x[i] = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin();
    y[i] = lower_bound(ys.begin(), ys.end(), y[i]) - ys.begin();
  }
  for (int i = 0; i < sz(xs); i++) {
    for (int j = 0; j < sz(ys); j++) {
      id[i][j] = -1;
    }
  }
  for (int i = 0; i < n; i++) {
    id[x[i]][y[i]] = i;
  }
  for (int i = 0; i < sz(xs); i++) {
    for (int j = 0; j < sz(ys); j++) {
      who[i][j] = -1;
    }
    int maxy = sz(ys) - 1;
    while (maxy >= 0 && id[i][maxy] == -1) {
      maxy--;
    }
    int lst = -1;
    for (int j = 0; j < maxy; j++) {
      if (id[i][j] != -1) {
        lst = id[i][j];
        continue;
      }
      who[i][j] = lst;
    }
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int j = 0; j < sz(ys); j++) {
    int maxx = sz(xs) - 1;
    while (maxx >= 0 && id[maxx][j] == -1) {
      maxx--;
    }
    int lst = -1;
    for (int i = 0; i < maxx; i++) {
      if (id[i][j] != -1) {
        lst = id[i][j];
        continue;
      }
      int cur = lst;
      if (cur != -1 && who[i][j] != -1) {
        g[who[i][j]].push_back(cur);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    p[i] = -1;
    q[i] = -1;
  }
  while (true) {
    for (int i = 0; i < n; i++) {
      used[i] = false;
    }
    bool change = false;
    for (int i = 0; i < n; i++) {
      if (q[i] == -1 && !used[i] && dfs(i)) {
        change = true;
      }
    }
    if (!change) {
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  for (int i = 0; i < n; i++) {
    if (q[i] == -1 && !used[i]) {
      dfs0(i);
    }
  }
  vector<vector<int>> h, v;
  for (int i = 0; i < sz(xs); i++) {
    int maxy = sz(ys);
    while (maxy > 0 && id[i][maxy - 1] == -1) {
      maxy--;
    }
    for (int j = 0; j < maxy; j++) {
      if (id[i][j] == -1) {
        continue;
      }
      int l = j;
      int cur = id[i][j];
      while (j < maxy && used[cur]) {
        j++;
        if (j < maxy && id[i][j] != -1) {
          cur = id[i][j];
        }
      }
      if (j >= maxy) {
        j--;
      }
      v.push_back({xs[i], ys[l], xs[i], ys[j]});
    }
  }
  for (int j = 0; j < sz(ys); j++) {
    int maxx = sz(xs);
    while (maxx > 0 && id[maxx - 1][j] == -1) {
      maxx--;
    }
    for (int i = 0; i < maxx; i++) {
      if (id[i][j] == -1) {
        continue;
      }
      int l = i;
      int cur = id[i][j];
      while (i < maxx && (p[cur] == - 1 || !used[p[cur]])) {
        i++;
        if (i < maxx && id[i][j] != -1) {
          cur = id[i][j];
        }
      }
      if (i >= maxx) {
        i--;
      }
      h.push_back({xs[l], ys[j], xs[i], ys[j]});
    }
  }
  printf("%d\n", sz(h));
  for (int i = 0; i < sz(h); i++) {
    for (int j = 0; j < sz(h[i]); j++) {
      printf("%d ", h[i][j]);
    }
    printf("\n");
  }
  printf("%d\n", sz(v));
  for (int i = 0; i < sz(v); i++) {
    for (int j = 0; j < sz(v[i]); j++) {
      printf("%d ", v[i][j]);
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