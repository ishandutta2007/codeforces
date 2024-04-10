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

const int maxn = (int) 1e5 + 5;
int n, x;
int s[maxn], a[maxn], b[maxn];

int read() {
  if (scanf("%d%d", &n, &x) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &s[i], &a[i], &b[i]);
  }
  return true;
}

pair<int, int> tosort[maxn];
long long sum[maxn];
long long suma[maxn], sumb[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(b[i] - a[i], i);
  }
  sort(tosort, tosort + n);
  sum[0] = 0;
  suma[0] = 0;
  sumb[0] = 0;
  for (int i = 0; i < n; i++) {
    int id = tosort[i].second;
    sum[i + 1] = sum[i] + s[id];
    suma[i + 1] = suma[i] + (long long) a[id] * s[id];
    sumb[i + 1] = sumb[i] + (long long) b[id] * s[id];
  }
  long long p = (sum[n] + x - 1) / x;
  long long res = -infll;
  for (int i = 0; i < n; i++) {
    int id = tosort[i].second;
    long long l = sum[i], r = sum[n] - sum[i + 1];
    long long lp = (l + x - 1) / x, rp = (r + x - 1) / x;
    if (lp + rp > p) {
      continue;
    }
    long long ra = lp * x - l, rb = rp * x - r;
    long long can = p - lp - rp;
    long long cur = suma[i] + sumb[n] - sumb[i + 1];
    long long need = s[id];
    if (a[id] > b[id]) {
      ra += can * x;
      ra = min(ra, need);
      cur += (long long) a[id] * ra;
      need -= ra;
      rb = min(rb, need);
      cur += (long long) b[id] * rb;
      need -= rb;
    } else {
      rb += can * x;
      rb = min(rb, need);
      cur += (long long) b[id] * rb;
      need -= rb;
      ra = min(ra, need);
      cur += (long long) a[id] * ra;
      need -= ra;
    }
    if (need) {
      continue;
    }
    res = max(res, cur);
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