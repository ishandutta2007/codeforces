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

const int maxn = (int) 2e5 + 5;
int n;
int a[maxn];
vector<int> g[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    g[i].clear();
  }
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

int deg[maxn];
int used[maxn];
queue<int> q[3];

void solve() {
  if (n == 1) {
    printf("1\n");
    return;
  }
  int res = inf;
  for (int t = 0; t < 2; ++t) {
    for (int col = 0; col < 3; ++col) {
      while (!q[col].empty()) {
        q[col].pop();
      }
    }
    for (int i = 0; i < n; ++i) {
      deg[i] = sz(g[i]);
      if (deg[i] == 1) {
        q[a[i]].push(i);
      }
      used[i] = false;
    }
    int cur = 0;
    while (!q[0].empty() || !q[1].empty() || !q[2].empty()) {
      int col = ((cur & 1) ^ t) + 1;
      while (!q[0].empty() || !q[col].empty()) {
        int v;
        if (!q[0].empty()) {
          v = q[0].front();
          q[0].pop();
        } else {
          v = q[col].front();
          q[col].pop();
        }
        used[v] = true;
        for (int i = 0; i < sz(g[v]); ++i) {
          int u = g[v][i];
          if (used[u]) {
            continue;
          }
          --deg[u];
          if (deg[u] == 1) {
            q[a[u]].push(u);
          }
        }
      }
      ++cur;
    }
    res = min(res, cur);
  }
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