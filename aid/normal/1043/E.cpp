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

const int maxn = (int) 3e5 + 5;
int n, m;
int xs[maxn], ys[maxn];
int es[maxn][2];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &xs[i], &ys[i]);
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &es[i][j]);
      es[i][j]--;
    }
  }
  return true;
}

pair<int, int> tosort[maxn];
long long ans[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(xs[i] - ys[i], i);
  }
  sort(tosort, tosort + n);
  for (int i = 0; i < n; i++) {
    ans[i] = 0;
  }
  {
    long long sx = 0;
    for (int i = 0; i < n; i++) {
      int id = tosort[i].second;
      ans[id] += sx + (long long) i * ys[id];
      sx += xs[id];
    }
  }
  {
    long long sy = 0;
    for (int i = n - 1; i >= 0; i--) {
      int id = tosort[i].second;
      ans[id] += (long long) (n - 1 - i) * xs[id] + sy;
      sy += ys[id];
    }
  }
  for (int i = 0; i < m; i++) {
    int v = es[i][0], u = es[i][1];
    int val = min(xs[v] + ys[u], xs[u] + ys[v]);
    ans[v] -= val;
    ans[u] -= val;
  }
  for (int i = 0; i < n; i++) {
    printf("%lld ", ans[i]);
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