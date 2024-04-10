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

const int maxn = (int) 1e3 + 5;
int n;
int xs[maxn], ys[maxn];;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &xs[i], &ys[i]);
  }
  return true;
}

void solve() {
  while (true) {
    int msk = 0;
    for (int i = 0; i < n; i++) {
      int col = ((xs[i] + ys[i]) & 1);
      msk |= (1 << col);
    }
    if (msk == 3) {
      break;
    }
    if (msk == 2) {
      for (int i = 0; i < n; i++) {
        xs[i]--;
      }
    }
    for (int i = 0; i < n; i++) {
      int nx = (xs[i] + ys[i]) / 2, ny = (xs[i] - ys[i]) / 2;
      xs[i] = nx;
      ys[i] = ny;
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if ((xs[i] + ys[i]) & 1) {
      ans.push_back(i);
    }
  }
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
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}