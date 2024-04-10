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

const int maxn = (int) 2e5 + 5;
int n;
long long a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  return true;
}

const int logx = 61;
int p[maxn];
int cnt[logx];

void solve() {
  for (int i = 0; i < logx; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    long long x = a[i];
    int k = 0;
    while (!(x & 1)) {
      x >>= 1;
      k++;
    }
    p[i] = k;
    cnt[k]++;
  }
  int k = 0;
  for (int i = 1; i < logx; i++) {
    if (cnt[i] > cnt[k]) {
      k = i;
    }
  }
  printf("%d\n", n - cnt[k]);
  for (int i = 0; i < n; i++) {
    if (p[i] != k) {
      printf("%lld ", a[i]);
    }
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