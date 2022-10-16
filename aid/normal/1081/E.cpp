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
int n;
long long x[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 1; i < n; i += 2) {
    scanf("%lld", &x[i]);
  }
  return true;
}

bool get(long long x, long long prv, long long &a, long long &b) {
  a = -1;
  b = -1;
  for (int d = 1; d * d <= x; d++) {
    if (x % d) {
      continue;
    }
    long long sum = x / d;
    long long diff = d;
    if ((sum & 1) != (diff & 1)) {
      continue;
    }
    long long cb = (sum + diff) / 2, ca = (sum - diff) / 2;
    if (ca <= prv) {
      continue;
    }
    if (a == -1 || (ca < a)) {
      a = ca;
      b = cb;
    }
  }
  return a != -1;
}

void solve() {
  long long cur = 0;
  for (int i = 1; i < n; i += 2) {
    long long a, b;
    if (!get(x[i], cur, a, b)) {
      printf("No\n");
      return;
    }
    x[i - 1] = a * a - cur * cur;
    cur = b;
  }
  printf("Yes\n");
  for (int i = 0; i < n; i++) {
    printf("%lld ", x[i]);
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