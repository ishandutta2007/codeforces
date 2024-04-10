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

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e3 + 5;
int n;
int w[maxn];
vector<int> g[maxn];
vector<int> ids[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
    ids[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    scanf("%d%d%d", &v, &u, &w[i]);
    v--;
    u--;
    g[v].push_back(u);
    ids[v].push_back(i);
    g[u].push_back(v);
    ids[u].push_back(i);
  }
  return true;
}

int getLeaf(int v, int p) {
  if (sz(g[v]) == 1) {
    return v;
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    return getLeaf(u, v);
  }
  assert(false);
}

pair<int, int> get(int v, int p) {
  if (sz(g[v]) == 1) {
    return make_pair(v, v);
  }
  int a = -1, b = -1;
  for (int i = 0; i < sz(g[v]) && b == -1; i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    int leaf = getLeaf(u, v);
    if (a == -1) {
      a = leaf;
    } else {
      b = leaf;
    }
  }
  return make_pair(a, b);
}

vector<pair<pair<int, int>, int>> ans;

void solve() {
  ans.clear();
  for (int v = 0; v < n; v++) {
    if (sz(g[v]) == 2) {
      continue;
    }
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      int pv = u;
      int e = ids[v][i];
      int need = w[e];
      bool ok = true;
      int pu = v;
      vector<int> es;
      es.push_back(e);
      while (sz(g[u]) == 2) {
        int j = 0;
        if (g[u][j] == pu) {
          j++;
        }
        int nu = g[u][j];
        int ne = ids[u][j];
        if (w[ne] != need) {
          ok = false;
          break;
        }
        pu = u;
        u = nu;
        es.push_back(ne);
      }
      if (!ok) {
        printf("NO\n");
        return;
      }
      if (!need) {
        continue;
      }
      pair<int, int> a = get(v, pv), b = get(u, pu);
      ans.push_back(make_pair(make_pair(a.first, b.first), need / 2));
      ans.push_back(make_pair(make_pair(a.second, b.second), need / 2));
      if (a.first != a.second) {
        ans.push_back(make_pair(make_pair(a.first, a.second), -(need / 2)));
      }
      if (b.first != b.second) {
        ans.push_back(make_pair(make_pair(b.first, b.second), -(need / 2)));
      }
      for (int j = 0; j < sz(es); j++) {
        int e = es[j];
        w[e] = 0;
      }
    }
  }
  printf("YES\n");
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d %d %d\n", ans[i].first.first + 1, ans[i].first.second + 1, ans[i].second);
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