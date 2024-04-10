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

const int maxn = (int) 1e5 + 5;
long long cnt[maxn];

void precalc() {
  cnt[0] = 1;
  long long sum = 1;
  for (int i = 1; i < maxn; ++i) {
    cnt[i] = sum;
    sum = min(sum + cnt[i], infll);
  }
}

int n;
long long k;

bool read() {
  if (scanf("%d%lld", &n, &k) < 2) {
    return false;
  }
  --k;
  return true;
}

void solve() {
  if (k >= cnt[n]) {
    printf("-1\n");
    return;
  }
  int x = 1;
  int prv = 0;
  while (x <= n) {
    while (k >= cnt[n - x]) {
      k -= cnt[n - x];
      ++x;
    }
    for (int i = x; i > prv; --i) {
      printf("%d ", i);
    }
    prv = x;
    ++x;
  }
  printf("\n");
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