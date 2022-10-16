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

int l, r;

bool read() {
  if (scanf("%d%d", &l, &r) < 2) {
    return false;
  }
  return true;
}

const int maxn = 32;
int n;
int g[maxn][maxn];
vector<pair<pair<int, int>, int>> ans;

void addEdge(int v, int u, int w) {
  assert(v < u);
  assert(w > 0);
  assert(g[v][u] == -1);
  g[v][u] = w;
}

void solve() {
  printf("YES\n");
  if (l == r) {
    printf("2 1\n");
    printf("1 2 %d\n", l);
    return;
  }
  if (l == r - 1) {
    printf("3 3\n");
    printf("1 3 %d\n", l);
    printf("1 2 %d\n", 1);
    printf("2 3 %d\n", l);
    return;
  }
  int d = r - l;
  int b = 0;
  while ((1 << b) <= d) {
    ++b;
  }
  --b;
  int s = 0, ss = 1, t = 2 + b;
  n = t + 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      g[i][j] = -1;
    }
  }
  addEdge(s, t, l);
  for (int i = 0; i < b; ++i) {
    int v = t - 1 - i;
    addEdge(v, t, l);
    addEdge(s, v, (1 << i));
    for (int j = 0; j < i; ++j) {
      int u = t - 1 - j;
      addEdge(v, u, (1 << j));
    }
  }
  addEdge(s, ss, 1);
  for (int i = 0; i < b; ++i) {
    if (!((d >> i) & 1)) {
      continue;
    }
    int v = t - 1 - i;
    int w = ((d >> (i + 1)) << (i + 1)) - 1;
    addEdge(ss, v, w);
  }
  addEdge(ss, t, r - 1);
  ans.clear();
  for (int v = 0; v < n; ++v) {
    for (int u = 0; u < n; ++u) {
      if (g[v][u] != -1) {
        ans.push_back(make_pair(make_pair(v, u), g[v][u]));
      }
    }
  }
  printf("%d %d\n", n, sz(ans));
  for (int i = 0; i < sz(ans); ++i) {
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