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
int n, m;
vector<int> diag[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    diag[i].clear();
    diag[i].push_back((i + 1) % n);
    diag[i].push_back((i + n - 1) % n);
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    diag[v].push_back(u);
    diag[u].push_back(v);
  }
  return true;
}

vector<int> used[maxn];
vector<int> f[maxn];
vector<int> g[maxn];
int del[maxn];
int ts[maxn];
int d[maxn];

void getTs(int v, int p) {
  ts[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (del[u] || u == p) {
      continue;
    }
    getTs(u, v);
    ts[v] += ts[u];
  }
}

void centroid(int v, int curd) {
  {
    getTs(v, -1);
    int p = -1;
    int all = ts[v];
    while (true) {
      int maxu = -1;
      for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        if (del[u] || u == p) {
          continue;
        }
        if (2 * ts[u] > all) {
          maxu = u;
        }
      }
      if (maxu == -1) {
        break;
      }
      p = v;
      v = maxu;
    }
  }
  d[v] = curd;
  del[v] = true;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (del[u]) {
      continue;
    }
    centroid(u, curd + 1);
  }
}

pair<vector<int>, int> tosort[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < sz(diag[i]); j++) {
      if (diag[i][j] < i) {
        diag[i][j] += n;
      }
    }
    sort(diag[i].begin(), diag[i].end());
  }
  for (int i = 0; i < n; i++) {
    used[i].clear();
    used[i].resize(sz(diag[i]));
  }
  int fs = 0;
  vector< pair<pair<int, int>, int> > e;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < sz(diag[i]); j++) {
      if (used[i][j] || diag[i][j] % n == (i + n - 1) % n) {
        continue;
      }
      int v = i;
      int pos = j;
      f[fs].clear();
      while (!used[v][pos]) {
        f[fs].push_back(v);
        used[v][pos] = true;
        int u = diag[v][pos] % n;
        e.push_back(make_pair(make_pair(min(v, u), max(v, u)), fs));
        if (u > v) {
          v += n;
        }
        pos = lower_bound(diag[u].begin(), diag[u].end(), v) - diag[u].begin();
        assert(pos < sz(diag[u]) && diag[u][pos] == v);
        v = u;
        pos--;
        if (pos < 0) {
          pos += sz(diag[v]);
        }
      }
      fs++;
    }
  }
  /*for (int i = 0; i < fs; i++) {
    for (int j = 0; j < sz(f[i]); j++) {
      eprintf("%d ", f[i][j]);
    }
    eprintf("\n");
  }*/
  sort(e.begin(), e.end());
  for (int i = 0; i < fs; i++) {
    g[i].clear();
  }
  for (int i = 0; i < sz(e);) {
    int j = i;
    while (j < sz(e) && e[j].first == e[i].first) {
      j++;
    }
    assert(j - i <= 2);
    if (j - i == 2) {
      int v = e[i].second;
      int u = e[i + 1].second;
      g[v].push_back(u);
      g[u].push_back(v);
      //eprintf("%d %d: %d %d\n", e[i].first.first, e[i].first.second, v, u);
    }
    i = j;
  }
  for (int i = 0; i < fs; i++) {
    del[i] = false;
  }
  centroid(0, 0);
  for (int i = 0; i < fs; i++) {
    sort(f[i].begin(), f[i].end(), greater<int>());
    tosort[i] = make_pair(f[i], i);
  }
  sort(tosort, tosort + fs);
  for (int i = 0; i < fs; i++) {
    int id = tosort[i].second;
    printf("%d ", d[id] + 1);
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