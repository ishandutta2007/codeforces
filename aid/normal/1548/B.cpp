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

long long gcd(long long a, long long b) {
  return (b ? gcd(b, a % b) : a);
}

const int maxn = (int) 2e5 + 5;
int n;
long long a[maxn], b[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  return true;
}

long long st[4 * maxn];

void buildst(int v, int tl, int tr) {
  if (tl == tr - 1) {
    st[v] = b[tl];
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  st[v] = gcd(st[2 * v], st[2 * v + 1]);
}

long long get(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v];
  }
  int tm = (tl + tr) / 2;
  long long res = 0;
  if (l < tm) {
    res = gcd(res, get(2 * v, tl, tm, l, min(r, tm)));
  }
  if (r > tm) {
    res = gcd(res, get(2 * v + 1, tm, tr, max(l, tm), r));
  }
  return res;
}

void solve() {
  for (int i = 0; i + 1 < n; ++i) {
    b[i] = abs(a[i + 1] - a[i]);
  }
  --n;
  if (n > 0) {
    buildst(1, 0, n);
  }
  int res = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    long long cur;
    if (j <= i) {
      cur = b[i];
      j = i + 1;
    } else {
      cur = get(1, 0, n, i, j);
    }
    while (cur > 1) {
      res = max(res, j - i);
      if (j >= n) {
        break;
      }
      cur = gcd(cur, b[j]);
      ++j;
    }
  }
  ++res;
  printf("%d\n", res);
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