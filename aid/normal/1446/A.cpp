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
long long w;
int a[maxn];

bool read() {
  if (scanf("%d%lld", &n, &w) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

void solve() {
  for (int i = 0; i < n; ++i) {
    if (a[i] <= w && 2 * a[i] >= w) {
      printf("1\n");
      printf("%d\n", i + 1);
      return;
    }
  }
  vector<int> ans;
  long long sum = 0;
  for (int i = 0; i < n && 2 * sum < w; ++i) {
    if (a[i] <= w) {
      ans.push_back(i);
      sum += a[i];
    }
  }
  if (2 * sum < w) {
    printf("-1\n");
    return;
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); ++i) {
    printf("%d ", ans[i] + 1);
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