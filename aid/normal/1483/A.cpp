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

const int maxn = (int) 1e5 + 5;
int n, m;
vector<int> as[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; ++i) {
    int k;
    scanf("%d", &k);
    as[i].resize(k);
    for (int j = 0; j < k; ++j) {
      int x;
      scanf("%d", &x);
      --x;
      as[i][j] = x;
    }
  }
  return true;
}

int cnt[maxn];
int ans[maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    cnt[i] = 0;
  }
  int mx = (m + 1) / 2;
  for (int i = 0; i < m; ++i) {
    if (sz(as[i]) == 1) {
      int x = as[i][0];
      ++cnt[x];
      ans[i] = x;
      if (cnt[x] > mx) {
        printf("NO\n");
        return;
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    if (sz(as[i]) == 1) {
      continue;
    }
    int x = as[i][0];
    if (cnt[x] + 1 > mx) {
      x = as[i][1];
    }
    ++cnt[x];
    ans[i] = x;
  }
  printf("YES\n");
  for (int i = 0; i < m; ++i) {
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
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}