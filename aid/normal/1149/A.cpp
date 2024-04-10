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

void solve() {
  int c1 = 0, c2 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      c1++;
    }
    if (a[i] == 2) {
      c2++;
    }
  }
  if (!c1 || !c2) {
    for (int i = 0; i < n; i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
    return;
  }
  vector<int> ans;
  ans.push_back(2);
  c2--;
  ans.push_back(1);
  c1--;
  while (c2) {
    ans.push_back(2);
    c2--;
  }
  while (c1) {
    ans.push_back(1);
    c1--;
  }
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