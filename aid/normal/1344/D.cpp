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
const long long infll = (long long) 3.01e18;
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
long long k;
long long a[maxn];

bool read() {
  if (scanf("%d%lld", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  return true;
}

long long getVal(long long x, long long a) {
  return x * (a - x * x);
}

long long get1(long long a, long long d) {
  long long l = 0, r = a + 1;
  while (l < r - 1) {
    long long m = (l + r) / 2;
    long long diff = getVal(m, a) - getVal(m - 1, a);
    if (diff > d) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}

long long b[maxn];

pair<long long, long long> get(long long d) {
  long long res = 0;
  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    long long x = get1(a[i], d);
    res += getVal(x, a[i]);
    cnt += x;
    b[i] = x;
  }
  return make_pair(res, cnt);
}

void solve() {
  long long l = -infll, r = inf;
  while (l < r - 1) {
    long long m = (l + r) / 2;
    auto p = get(m);
    if (p.second < k) {
      r = m;
    } else {
      l = m;
    }
  }
  auto p = get(r);
  long long need = k - p.second;
  for (int i = 0; i < n && need; i++) {
    auto &x = b[i];
    while (need && x < a[i] && getVal(x + 1, a[i]) - getVal(x, a[i]) == r) {
      x++;
      need--;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%lld ", b[i]);
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