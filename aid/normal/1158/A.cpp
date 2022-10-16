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
int b[maxn], g[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &g[i]);
  }
  return true;
}

void solve() {
  int mx = 0;
  int mx1 = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] > mx) {
      mx1 = mx;
      mx = b[i];
    } else if (b[i] > mx1) {
      mx1 = b[i];
    }
  }
  int mn = inf;
  for (int i = 0; i < m; i++) {
    mn = min(mn, g[i]);
  }
  if (mn < mx) {
    printf("-1\n");
    return;
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    res += (long long) m * b[i];
  }
  for (int i = 0; i < m; i++) {
    res += g[i] - mx;
  }
  if (mx < mn) {
    res += mx - mx1;
  }
  printf("%lld\n", res);
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