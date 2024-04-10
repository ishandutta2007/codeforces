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

const int maxn = 7005;
int n;
int k[2];
int a[2][maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < 2; i++) {
    scanf("%d", &k[i]);
    for (int j = 0; j < k[i]; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  return true;
}

int dp[2 * maxn];
int deg[2 * maxn];
int q[2 * maxn];

void solve() {
  for (int i = 0; i < 2 * n; i++) {
    dp[i] = -1;
    deg[i] = k[i & 1];
  }
  int r = 0;
  dp[0] = 0;
  q[r++] = 0;
  dp[1] = 0;
  q[r++] = 1;
  for (int l = 0; l < r; l++) {
    int v = q[l];
    int t = ((v & 1) ^ 1);
    int pos = (v >> 1);
    for (int i = 0; i < k[t]; i++) {
      int npos = pos - a[t][i];
      if (npos < 0) {
        npos += n;
      }
      int u = ((npos << 1) | t);
      if (dp[u] != -1) {
        continue;
      }
      if (dp[v]) {
        deg[u]--;
        if (!deg[u]) {
          dp[u] = 0;
          q[r++] = u;
        }
      } else {
        dp[u] = 1;
        q[r++] = u;
      }
    }
  }
  for (int i = 2; i < 2 * n; i += 2) {
    printf(dp[i] == -1 ? "Loop " : (dp[i] == 0 ? "Lose " : "Win "));
  }
  printf("\n");
  for (int i = 3; i < 2 * n; i += 2) {
    printf(dp[i] == -1 ? "Loop " : (dp[i] == 0 ? "Lose " : "Win "));
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