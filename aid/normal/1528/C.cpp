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

const int maxn = (int) 3e5 + 5;
int n;
vector<int> g[2][maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int t = 0; t < 2; ++t) {
    for (int i = 0; i < n; ++i) {
      g[t][i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int p;
      scanf("%d", &p);
      --p;
      g[t][p].push_back(i);
    }
  }
  return true;
}

int path[maxn];
int tin[maxn], tout[maxn], t;

void dfs1(int v) {
  path[t] = v;
  tin[v] = t++;
  for (int i = 0; i < sz(g[1][v]); ++i) {
    int u = g[1][v][i];
    dfs1(u);
  }
  tout[v] = t;
}

set<int> st;
int res;

void dfs0(int v) {
  int add = -1, del = -1;
  {
    auto it = st.lower_bound(tin[v]);
    if (it == st.end() || *it >= tout[v]) {
      if (it != st.begin()) {
        --it;
        int u = path[*it];
        if (tin[u] <= tin[v] && tout[v] <= tout[u]) {
          del = tin[u];
          st.erase(it);
        }
      }
      add = tin[v];
      st.insert(tin[v]);
    }
    res = max(res, sz(st));
  }
  for (int i = 0; i < sz(g[0][v]); ++i) {
    int u = g[0][v][i];
    dfs0(u);
  }
  if (add != -1) {
    st.erase(add);
  }
  if (del != -1) {
    st.insert(del);
  }
}

void solve() {
  t = 0;
  dfs1(0);
  st.clear();
  res = 0;
  dfs0(0);
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}