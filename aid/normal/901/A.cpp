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
int h;
int a[maxn];

int read() {
  if (scanf("%d", &h) < 1) {
    return false;
  }
  for (int i = 0; i <= h; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

void solve() {
  assert(a[0] == 1);
  vector<int> ans;
  ans.push_back(-1);
  int v = 0, v0 = -1;
  int pos = -1, val = -1;
  for (int i = 1; i <= h; i++) {
    int nv = sz(ans);
    for (int j = 0; j < a[i]; j++) {
      ans.push_back(v);
    }
    int wasv0 = v0;
    v = nv;
    v0 = (a[i] == 1 ? -1 : v + 1);
    if (pos != -1 || a[i] == 1 || wasv0 == -1) {
      continue;
    }
    pos = v0;
    val = wasv0;
  }
  if (pos == -1) {
    printf("perfect\n");
    return;
  }
  printf("ambiguous\n");
  for (int i = 0; i < sz(ans); i++) {
    printf("%d ", ans[i] + 1);
  }
  printf("\n");
  ans[pos] = val;
  for (int i = 0; i < sz(ans); i++) {
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
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}