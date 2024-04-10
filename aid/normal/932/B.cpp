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

const int maxn = (int) 1e6 + 5, maxd = 10;
int f[maxn], g[maxn];
int s[maxd][maxn];

void precalc() {
  for (int i = 1; i < maxn; i++) {
    int x = i;
    int d = x % 10;
    x /= 10;
    if (!d) {
      f[i] = f[x];
    } else {
      f[i] = d * (x ? f[x] : 1);
    }
    assert(f[i] <= i);
  }
  for (int i = 1; i < maxn; i++) {
    g[i] = (i < 10 ? i : g[f[i]]);
  }
  for (int d = 0; d < maxd; d++) {
    s[d][0] = 0;
    for (int i = 0; i + 1 < maxn; i++) {
      s[d][i + 1] = s[d][i] + (g[i] == d);
    }
  }
}

int q;

int read() {
  if (scanf("%d", &q) < 1) {
    return false;
  }
  return true;
}

void solve() {
  for (int qq = 0; qq < q; qq++) {
    int l, r, d;
    scanf("%d%d%d", &l, &r, &d);
    r++;
    printf("%d\n", s[d][r] - s[d][l]);
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