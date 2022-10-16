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
int a[maxn];
int cnt[2];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  cnt[0] = 0;
  cnt[1] = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    a[i] = (a[i] & 1);
    ++cnt[a[i]];
  }
  return true;
}

void solve() {
  long long res = infll;
  for (int t = 0; t < 2; ++t) {
    int need[2] = {(n + 1) / 2, n / 2};
    if (need[0] != cnt[t] || need[1] != cnt[t ^ 1]) {
      continue;
    }
    int pos = 0;
    long long cur = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == t) {
        cur += abs(i - pos);
        pos += 2;
      }
    }
    res = min(res, cur);
  }
  if (res >= infll) {
    res = -1;
  }
  printf("%lld\n", res);
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