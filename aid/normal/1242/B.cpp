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

int p[maxn];
vector<int> vs[maxn];
set<int> cs;

int get(int x) {
  return (p[x] == x ? x : p[x] = get(p[x]));
}

int unite(int x, int y) {
  x = get(x);
  y = get(y);
  assert(x != y);
  if (sz(vs[x]) < sz(vs[y])) {
    swap(x, y);
  }
  p[y] = x;
  for (int i = 0; i < sz(vs[y]); i++) {
    vs[x].push_back(vs[y][i]);
  }
  vs[y].clear();
  return y;
}

int used[maxn];
int curu;

vector<int> todel;

void solve() {
  cs.clear();
  for (int i = 0; i < n; i++) {
    p[i] = i;
    vs[i] = {i};
    cs.insert(i);
  }
  for (int v = 0; v < n; v++) {
    curu++;
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      used[u] = curu;
    }
    todel.clear();
    for (auto it = cs.begin(); it != cs.end(); it++) {
      int root = get(*it);
      if (root == get(v)) {
        continue;
      }
      bool found = false;
      for (int i = 0; i < sz(vs[root]); i++) {
        int u = vs[root][i];
        if (used[u] != curu) {
          found = true;
          break;
        }
      }
      if (found) {
        todel.push_back(unite(root, v));
      }
    }
    for (int i = 0; i < sz(todel); i++) {
      cs.erase(todel[i]);
    }
  }
  printf("%d\n", sz(cs) - 1);
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