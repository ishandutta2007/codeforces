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
int p[maxn];
vector<int> gr[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    gr[i].clear();
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
    gr[p[i]].push_back(i);
  }
  return true;
}

void solve() {
  int res = n;
  for (int v = 0; v < n; ++v) {
    if (sz(gr[v]) <= 1) {
      continue;
    }
    int w = -1;
    for (int i = 0; i < sz(gr[v]); ++i) {
      int u = gr[v][i];
      if (gr[u].empty()) {
        w = u;
        break;
      }
    }
    if (w == -1) {
      w = gr[v][0];
    }
    for (int i = 0; i < sz(gr[v]); ++i) {
      int u = gr[v][i];
      if (u != w) {
        --res;
        p[u] = -1;
      }
    }
  }
  int lst = -1, fst = -1;
  for (int s = 0; s < n; ++s) {
    if (!gr[s].empty()) {
      continue;
    }
    if (lst == -1) {
      fst = s;
    } else {
      p[lst] = s;
    }
    int v = s;
    while (p[v] != -1) {
      v = p[v];
    }
    lst = v;
  }
  p[lst] = fst;
  printf("%d\n", res);
  for (int i = 0; i < n; ++i) {
    printf("%d ", p[i] + 1);
  }
  printf("\n");
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