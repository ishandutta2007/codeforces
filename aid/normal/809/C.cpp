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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int q;

int read() {
  if (scanf("%d", &q) < 1) {
    return false;
  }
  return true;
}

const int maxlen = 31;
int dp[maxlen + 1][8];
int cnt[maxlen + 1][8];
int s[3][maxlen];

int get(int a, int b, int c) {
  for (int t = 0; t < 3; t++) {
    int x = (t == 0 ? a : (t == 1 ? b : c));
    for (int i = 0; i < maxlen; i++) {
      s[t][i] = ((x >> i) & 1);
    }
  }
  memset(dp, 0, sizeof(dp));
  memset(cnt, 0, sizeof(cnt));
  cnt[maxlen][0] = 1;
  for (int pos = maxlen - 1; pos >= 0; pos--) {
    for (int msk = 0; msk < 8; msk++) {
      auto curdp = dp[pos + 1][msk];
      auto curcnt = cnt[pos + 1][msk];
      if (!curcnt) {
        continue;
      }
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          int k = (i ^ j);
          bool ok = true;
          int nmsk = msk;
          for (int t = 0; t < 3; t++) {
            if (msk & (1 << t)) {
              continue;
            }
            int d = (t == 0 ? i : (t == 1 ? j : k));
            if (d > s[t][pos]) {
              ok = false;
              break;
            }
            if (d < s[t][pos]) {
              nmsk |= (1 << t);
            }
          }
          if (!ok) {
            continue;
          }
          add(dp[pos][nmsk], curdp);
          if (k) {
            add(dp[pos][nmsk], mul(curcnt, (1 << pos) % mod));
          }
          add(cnt[pos][nmsk], curcnt);
        }
      }
    }
  }
  int res = dp[0][7];
  add(res, cnt[0][7]);
  //eprintf("%d %d %d: %d\n", a, b, c, res);
  return res;
}

void solve() {
  for (int qq = 0; qq < q; qq++) {
    int x0, y0, x1, y1, k;
    scanf("%d%d%d%d%d", &x0, &y0, &x1, &y1, &k);
    x0--;
    y0--;
    int res = get(x1, y1, k);
    add(res, mod - get(x1, y0, k));
    add(res, mod - get(x0, y1, k));
    add(res, get(x0, y0, k));
    printf("%d\n", res);
  }
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