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

const int maxn = 12, pown = (1 << maxn);
const int maxw = 105;
int n, m, q;
int w[maxn];
int a[pown];
char tmp[100];

int read() {
  if (scanf("%d%d%d", &n, &m, &q) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
  }
  memset(a, 0, sizeof(a));
  for (int i = 0; i < m; i++) {
    scanf("%s", tmp);
    int cur = 0;
    for (int j = 0; j < n; j++) {
      if (tmp[j] == '1') {
        cur |= (1 << j);
      }
    }
    a[cur]++;
  }
  return true;
}

int ans[pown][maxw];

void solve() {
  memset(ans, 0, sizeof(ans));
  for (int i = 0; i < (1 << n); i++) {
    auto &cur = ans[i];
    for (int j = 0; j < (1 << n); j++) {
      if (!a[j]) {
        continue;
      }
      int sum = 0;
      for (int k = 0; k < n; k++) {
        if ((i & (1 << k)) == (j & (1 << k))) {
          sum += w[k];
        }
      }
      if (sum < maxw) {
        cur[sum] += a[j];
      }
    }
    for (int j = 1; j < maxw; j++) {
      cur[j] += cur[j - 1];
    }
  }
  for (int qq = 0; qq < q; qq++) {
    int k;
    scanf("%s%d", tmp, &k);
    int cur = 0;
    for (int j = 0; j < n; j++) {
      if (tmp[j] == '1') {
        cur |= (1 << j);
      }
    }
    printf("%d\n", ans[cur][k]);
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