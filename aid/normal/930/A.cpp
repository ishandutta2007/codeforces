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
int n;
int p[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  p[0] = -1;
  for (int i = 1; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  return true;
}

int dep[maxn], cnt[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    cnt[i] = 0;
  }
  dep[0] = 0;
  cnt[dep[0]]++;
  for (int i = 1; i < n; i++) {
    dep[i] = dep[p[i]] + 1;
    cnt[dep[i]]++;
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    res += (cnt[i] & 1);
  }
  printf("%d\n", res);
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