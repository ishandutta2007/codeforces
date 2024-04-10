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

const int maxn = (int) 2e5 + 5;
int n, m;
int a[maxn];
int ks[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &ks[i]);
  }
  return true;
}

int cnt[maxn];

void solve() {
  int good = 0;
  for (int i = 0; i < m; i++) {
    good += (ks[i] == 0);
  }
  int res = inf;
  for (int l = 0, r = 0; l < n; l++) {
    while (r < n && good < m) {
      cnt[a[r]]++;
      if (cnt[a[r]] == ks[a[r]]) {
        good++;
      }
      r++;
    }
    if (good < m) {
      break;
    }
    res = min(res, r - l);
    if (cnt[a[l]] == ks[a[l]]) {
      good--;
    }
    cnt[a[l]]--;
  }
  if (res >= inf) {
    printf("-1\n");
    return;
  }
  for (int i = 0; i < m; i++) {
    res -= ks[i];
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