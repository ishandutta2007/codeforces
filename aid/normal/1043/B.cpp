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

const int maxn = 1005;
int n;
int a[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int x[maxn];

void solve() {
  vector<int> ans;
  for (int k = 1; k <= n; k++) {
    for (int i = 0; i < k; i++) {
      x[i] = a[i + 1] - a[i];
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (a[i + 1] != a[i] + x[i % k]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans.push_back(k);
    }
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d ", ans[i]);
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