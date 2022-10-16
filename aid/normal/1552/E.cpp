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

const int maxn = 105, maxx = maxn * maxn;
int n, k;
int c[maxx];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n * k; ++i) {
    scanf("%d", &c[i]);
    --c[i];
  }
  return true;
}

int ans[maxn][2];
int used[maxn];
int ps[maxn][maxn];
int cnt[maxn];
int val[maxx];
int rs[maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    used[i] = false;
    cnt[i] = 0;
  }
  for (int i = 0; i < n * k; ++i) {
    ps[c[i]][cnt[c[i]]++] = i;
  }
  for (int i = 0; i < n * k; ++i) {
    val[i] = 0;
  }
  int mx = (n + k - 2) / (k - 1);
  for (int i = 1; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      rs[j] = ps[j][i];
    }
    sort(rs, rs + n);
    for (int j = 0; j < n; ++j) {
      int r = rs[j];
      int id = c[r];
      if (used[id]) {
        continue;
      }
      int l = ps[id][i - 1];
      bool ok = true;
      for (int x = l; x <= r; ++x) {
        if (val[x] >= mx) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        break;
      }
      for (int x = l; x <= r; ++x) {
        ++val[x];
      }
      ans[id][0] = l;
      ans[id][1] = r;
      used[id] = true;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      printf("%d ", ans[i][j] + 1);
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
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}