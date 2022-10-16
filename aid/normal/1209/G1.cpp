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
int n, q;
int a[maxn];
int qs[maxn][2];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for (int i = 0; i < q; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", qs[i][j]);
      qs[i][j]--;
    }
  }
  return true;
}

int cnt[maxn];
int rs[maxn];

void solve() {
  for (int i = 0; i < maxn; i++) {
    cnt[i] = 0;
    rs[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
    rs[a[i]] = i + 1;
  }
  int res = n;
  for (int l = 0; l < n;) {
    int r = l + 1;
    int cur = 0;
    for (int i = l; i < r; i++) {
      r = max(r, rs[a[i]]);
      cur = max(cur, cnt[a[i]]);
    }
    res -= cur;
    l = r;
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