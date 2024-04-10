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

const int maxn = (int) 1e5 + 5, k = 500;
int n, m;
vector<int> g[maxn];
int ts[maxn];
int qs[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    p--;
    g[p].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &ts[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &qs[i]);
    qs[i] = abs(qs[i]);
    qs[i]--;
  }
  return true;
}

const int logn = 20;
int p[maxn][logn];
int tin[maxn], tout[maxn], t;

void dfs0(int v) {
  tin[v] = t++;
  for (int i = 1; i < logn; i++) {
    p[v][i] = p[p[v][i - 1]][i - 1];
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    p[u][0] = v;
    dfs0(u);
  }
  tout[v] = t++;
}

bool anc(int v, int u) {
  return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int lca(int v, int u) {
  if (anc(v, u)) {
    return v;
  }
  if (anc(u, v)) {
    return u;
  }
  for (int i = logn - 1; i >= 0; i--) {
    if (!anc(p[v][i], u)) {
      v = p[v][i];
    }
  }
  return p[v][0];
}

int a[maxn];
int good[maxn];
int pr[maxn];
int pre[maxn];
vector<int> gc[maxn];
vector<vector<int>> es[maxn], xs[maxn];
vector<int> toadd[maxn];
int x[maxn];

int dfs(int v, int p, vector<int> &e) {
  if (good[v]) {
    if (p != -1) {
      pr[v] = p;
      pre[v] = sz(gc[p]);
      gc[p].push_back(v);
      es[p].push_back(e);
    }
    gc[v].clear();
    es[v].clear();
  }
  if (!a[v]) {
    e.push_back(v);
  }
  int res = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (good[v]) {
      vector<int> ne;
      res += dfs(u, v, ne);
    } else {
      res += dfs(u, p, e);
    }
  }
  x[v] = ts[v] - res;
  res += a[v];
  if (!a[v]) {
    e.pop_back();
  }
  return res;
}

vector<int> vs;

int get(const vector<int> &e, int x) {
  return lower_bound(e.begin(), e.end(), x) - e.begin();
}

void solve() {
  t = 0;
  p[0][0] = 0;
  dfs0(0);
  for (int i = 0; i < n; i++) {
    a[i] = false;
    good[i] = false;
  }
  for (int bl = 0; bl < m; bl += k) {
    int br = min(bl + k, m);
    vs.clear();
    vector<pair<int, int>> tosort;
    for (int i = bl; i < br; i++) {
      vs.push_back(qs[i]);
      tosort.push_back(make_pair(tin[qs[i]], qs[i]));
    }
    vs.push_back(0);
    tosort.push_back(make_pair(tin[0], 0));
    sort(tosort.begin(), tosort.end());
    tosort.erase(unique(tosort.begin(), tosort.end()), tosort.end());
    for (int i = 0; i + 1 < sz(tosort); i++) {
      vs.push_back(lca(tosort[i].second, tosort[i + 1].second));
    }
    sort(vs.begin(), vs.end());
    vs.erase(unique(vs.begin(), vs.end()), vs.end());
    for (int i = 0; i < sz(vs); i++) {
      good[vs[i]] = true;
    }
    {
      vector<int> e;
      dfs(0, -1, e);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      res += (!a[i] && x[i] < 0);
    }
    for (int it = 0; it < sz(vs); it++) {
      int v = vs[it];
      xs[v].clear();
      toadd[v].clear();
      for (int i = 0; i < sz(es[v]); i++) {
        const auto &e = es[v][i];
        xs[v].push_back(vector<int>(sz(e)));
        toadd[v].push_back(0);
        for (int j = 0; j < sz(e); j++) {
          xs[v][i][j] = x[e[j]];
        }
        sort(xs[v][i].begin(), xs[v][i].end());
      }
    }
    for (int i = bl; i < br; i++) {
      int v = qs[i];
      res -= (!a[v] && x[v] < 0);
      int diff = a[v];
      a[v] ^= 1;
      diff -= a[v];
      res += (!a[v] && x[v] < 0);
      while (v != 0) {
        int u = pr[v];
        int id = pre[v];
        res -= (!a[u] && x[u] < 0);
        x[u] += diff;
        res += (!a[u] && x[u] < 0);
        res -= get(xs[u][id], -toadd[u][id]);
        toadd[u][id] += diff;
        res += get(xs[u][id], -toadd[u][id]);
        v = u;
      }
      printf("%d\n", res);
    }
    for (int i = 0; i < sz(vs); i++) {
      good[vs[i]] = false;
    }
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