#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
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

const int maxn = (int) 2e5 + 5;
int n;
int c[maxn], d[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &c[i], &d[i]);
  }
  return true;
}

bool intersect(int &a, int &b, int c, int d) {
  a = max(a, c);
  b = min(b, d);
  return a <= b;
}

void solve() {
  int l = -inf, r = inf;
  for (int i = 0; i < n; i++) {
    if (d[i] == 1) {
      if (!intersect(l, r, 1900, inf)) {
        printf("Impossible\n");
        return;
      }
    } else {
      if (!intersect(l, r, -inf, 1899)) {
        printf("Impossible\n");
        return;
      }
    }
    if (l != -inf) {
      l += c[i];
    }
    if (r != inf) {
      r += c[i];
    }
  }
  if (r == inf) {
    printf("Infinity\n");
    return;
  }
  printf("%d\n", r);
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}