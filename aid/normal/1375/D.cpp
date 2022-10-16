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

const int maxn = 1005;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

vector<int> ans;
int used[maxn];
int curu;

int getMex() {
  curu++;
  for (int i = 0; i < n; i++) {
    used[a[i]] = curu;
  }
  int mex = 0;
  while (used[mex] == curu) {
    mex++;
  }
  return mex;
}

void doOp(int pos) {
  int mex = getMex();
  a[pos] = mex;
  ans.push_back(pos);
}

void solve() {
  ans.clear();
  while (true) {
    int mex = getMex();
    if (mex >= n) {
      break;
    }
    doOp(mex);
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == i) {
      continue;
    }
    int x = a[i];
    doOp(i);
    while (x < n) {
      int nx = a[x];
      doOp(x);
      x = nx;
    }
  }
  for (int i = 0; i < n; i++) {
    assert(a[i] == i);
  }
  assert(sz(ans) <= 2 * n);
  printf("%d\n", sz(ans));
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