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
int l[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &l[i]);
  }
  return true;
}

int d[maxn];
int p[maxn];

void solve() {
  int x = 0;
  long long sum = 0;
  for (int i = m - 1; i >= 0; i--) {
    sum += l[i];
    int px = x;
    x = max(l[i], x + 1);
    if (x > n) {
      printf("-1\n");
      return;
    }
    d[i] = x - px;
  }
  if (sum < n) {
    printf("-1\n");
    return;
  }
  int need = n - x;
  for (int i = 0; i < m; i++) {
    int y = min(need, l[i] - d[i]);
    d[i] += y;
    need -= y;
  }
  p[m] = n;
  for (int i = m - 1; i >= 0; i--) {
    p[i] = p[i + 1] - d[i];
  }
  for (int i = 0; i < m; i++) {
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
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}