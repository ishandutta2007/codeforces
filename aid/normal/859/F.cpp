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

const int maxn = (int) 4e5 + 5;
int n;
long long c;
int a[maxn];

int read() {
  if (scanf("%d%lld", &n, &c) < 2) {
    return false;
  }
  for (int i = 0; i < 2 * n - 1; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

long long s[maxn];
long long dp[maxn];
set< pair<long long, int> > st;
long long toadd;
long long pmx;

void solve() {
  s[0] = 0;
  for (int i = 0; i < 2 * n - 1; i++) {
    s[i + 1] = s[i] + a[i];
  }
  st.clear();
  toadd = 0;
  pmx = -infll;
  dp[0] = 0;
  st.insert(make_pair(dp[0], 0));
  for (int i = 0, j = 0; i < 2 * n - 1; i += 2) {
    {
      int d = (i ? a[i] + a[i - 1] : a[i]);
      toadd += d;
    }
    while (s[i + 1] - s[j] > c) {
      int jj = (j ? j - 1 : j);
      st.erase(make_pair(dp[jj] + s[i + 1] - s[j] - toadd, jj));
      pmx = max(pmx, dp[jj]);
      j += 2;
    }
    auto &cur = dp[i + 1];
    cur = pmx + c;
    if (!st.empty()) {
      cur = max(cur, st.rbegin()->first + toadd);
    }
    if (i + 2 < 2 * n - 1) {
      st.insert(make_pair(cur - a[i + 1] - toadd, i + 1));
    }
  }
  printf("%lld\n", dp[2 * n - 1]);
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