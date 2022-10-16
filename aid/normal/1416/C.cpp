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

const int maxn = (int) 3e5 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

const int maxb = 30;
vector<int> tmp[2];

void solve() {
  long long invs = 0;
  int x = 0;
  for (int b = maxb - 1; b >= 0; --b) {
    long long cinv[2] = {0, 0};
    for (int r = 0; r < n;) {
      int l = r;
      while (r < n && (a[r] >> (b + 1)) == (a[l] >> (b + 1))) {
        ++r;
      }
      int cnt[2] = {0, 0};
      tmp[0].clear();
      tmp[1].clear();
      for (int i = l; i < r; ++i) {
        int z = ((a[i] >> b) & 1);
        cinv[z] += cnt[z ^ 1];
        ++cnt[z];
        tmp[z].push_back(a[i]);
      }
      int pos = l;
      for (int z = 0; z < 2; ++z) {
        for (int i = 0; i < sz(tmp[z]); ++i) {
          a[pos++] = tmp[z][i];
        }
      }
    }
    if (cinv[1] < cinv[0]) {
      x ^= (1 << b);
      invs += cinv[1];
    } else {
      invs += cinv[0];
    }
  }
  printf("%lld %d\n", invs, x);
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