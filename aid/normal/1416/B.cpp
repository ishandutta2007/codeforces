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

const int maxn = (int) 1e4 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

vector<vector<int>> ans;

void makeOp(int i, int j, int x) {
  ans.push_back({i, j, x});
  a[i] -= x * i;
  a[j] += x * i;
}

void solve() {
  int sum = 0;
  for (int i = 1; i <= n; ++i){
    sum += a[i];
  }
  if (sum % n) {
    printf("-1\n");
    return;
  }
  ans.clear();
  for (int i = 2; i <= n; ++i) {
    if (a[i] % i) {
      int need = i - (a[i] % i);
      assert(a[1] >= need);
      makeOp(1, i, need);
    }
    assert(!(a[i] % i));
    int x = a[i] / i;
    makeOp(i, 1, x);
  }
  for (int i = 2; i <= n; ++i) {
    makeOp(1, i, sum / n);
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); ++i) {
    for (int j = 0; j < sz(ans[i]); ++j) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }
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