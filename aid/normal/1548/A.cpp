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
int n, m;
int cnt[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    cnt[i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    if (v > u) {
      swap(v, u);
    }
    ++cnt[v];
  }
  return true;
}

void solve() {
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (!cnt[i]) {
      ++res;
    }
  }
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; ++qq) {
    int t;
    scanf("%d", &t);
    if (t == 3) {
      printf("%d\n", res);
      continue;
    }
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    if (v > u) {
      swap(v, u);
    }
    if (!cnt[v]) {
      --res;
    }
    if (t == 1) {
      ++cnt[v];
    } else {
      --cnt[v];
    }
    if (!cnt[v]) {
      ++res;
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