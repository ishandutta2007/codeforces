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

int k;

bool read() {
  if (scanf("%d", &k) < 1) {
    return false;
  }
  return true;
}

void solve() {
  int n;
  if (k < 1e4) {
    n = 1;
  } else {
    n = 1997;
  }
  int a = 0, b = ((k & 1) ? 1 : 2);
  vector<int> ans;
  ans.push_back(a);
  ans.push_back(-b);
  int sum = k + (n + 2) * (b - a);
  assert(!(sum & 1));
  sum /= 2;
  for (int i = 0; i < n; i++) {
    int x = min(sum, (int) 1e6);
    sum -= x;
    ans.push_back(x);
  }
  assert(!sum);
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