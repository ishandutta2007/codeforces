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

const int maxn = 105;
int n, m;
int a[maxn];
int ks[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &ks[i]);
  }
  return true;
}

int cnt[maxn];

void solve() {
  for (int l = 0; l < n; l++) {
    int good = 0;
    for (int i = 0; i < m; i++) {
      cnt[i] = 0;
      good += (ks[i] == 0);
    }
    for (int r = l; r < n; r++) {
      if (cnt[a[r]] == ks[a[r]]) {
        break;
      }
      cnt[a[r]]++;
      if (cnt[a[r]] == ks[a[r]]) {
        good++;
      }
      if (good == m) {
        printf("YES\n");
        return;
      }
    }
  }
  printf("NO\n");
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