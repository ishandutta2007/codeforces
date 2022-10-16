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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 1005;
int n, q;
pair<int, int> p[maxn];
int res[maxn];

int read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < q; i++) {
    scanf("%d", &p[i].first);
    p[i].second = i;
  }
  return true;
}

ld dp[maxn];

void solve() {
  sort(p, p + q);
  for (int i = 0; i <= n; i++) {
    dp[i] = 0;
  }
  dp[0] = 1;
  int pos = 0;
  int t = 0;
  while (pos < q) {
    for (int i = n - 1; i >= 0; i--) {
      ld pr = (ld) (n - i) / n;
      dp[i + 1] += dp[i] * pr;
      dp[i] *= 1 - pr;
    }
    t++;
    while (pos < q && (ld) (p[pos].first - eps) / 2000 < dp[n]) {
      res[p[pos].second] = t;
      pos++;
    }
  }
  for (int i = 0; i < q; i++) {
    printf("%d\n", res[i]);
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