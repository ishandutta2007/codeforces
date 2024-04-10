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

const int maxn = (int) 1e5 + 5, maxx = (int) 1e6 + 5;
int n;
vector<int> a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    a[i].resize(k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  return true;
}

int good[maxn], mn[maxn], mx[maxn];
int cnt[maxx];

void solve() {
  for (int i = 0; i < n; i++) {
    good[i] = false;
    auto &l = mn[i], &r = mx[i];
    l = inf;
    r = -inf;
    for (int j = 0; j < sz(a[i]); j++) {
      if (a[i][j] > l) {
        good[i] = true;
      }
      l = min(l, a[i][j]);
      r = max(r, a[i][j]);
    }
  }
  for (int i = 0; i < maxx; i++) {
    cnt[i] = 0;
  }
  int cntgood = 0;
  for (int i = 0; i < n; i++) {
    if (good[i]) {
      cntgood++;
      continue;
    }
    cnt[mx[i]]++;
  }
  for (int i = maxx - 2; i >= 0; i--) {
    cnt[i] += cnt[i + 1];
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    if (good[i]) {
      continue;
    }
    res += cnt[mn[i] + 1];
  }
  res += 2ll * cntgood * (n - cntgood);
  res += (long long) cntgood * cntgood;
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