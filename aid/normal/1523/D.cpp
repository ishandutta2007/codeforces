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

const int maxn = (int) 2e5 + 5, maxm = 61, maxk = 15, powk = (1 << maxk);
char tmp[maxm];
int n, m, k;
long long a[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", tmp);
    a[i] = 0;
    for (int j = 0; j < m; ++j) {
      if (tmp[j] == '1') {
        a[i] |= (1ll << j);
      }
    }
  }
  return true;
}

int res;
long long ans;
int x[powk];
vector<int> bs;

void solve1(int p) {
  bs.clear();
  for (int i = 0; i < m; ++i) {
    if (a[p] & (1ll << i)) {
      bs.push_back(i);
    }
  }
  int k = sz(bs);
  for (int i = 0; i < (1 << k); ++i) {
    x[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    int cur = 0;
    for (int j = 0; j < k; ++j) {
      if (a[i] & (1ll << bs[j])) {
        cur |= (1 << j);
      }
    }
    ++x[cur];
  }
  for (int i = 0; i < k; ++i) {
    for (int msk = 0; msk < (1 << k); ++msk) {
      if (!(msk & (1 << i))) {
        x[msk] += x[msk | (1 << i)];
      }
    }
  }
  for (int msk = 0; msk < (1 << k); ++msk) {
    if (2 * x[msk] >= n) {
      int cnt = __builtin_popcount(msk);
      if (cnt > res) {
        res = cnt;
        long long cur = 0;
        for (int i = 0; i < k; ++i) {
          if (msk & (1 << i)) {
            cur |= (1ll << bs[i]);
          }
        }
        ans = cur;
      }
    }
  }
}

void solve() {
  res = 0;
  ans = 0;
  for (int it = 0; it < 50; ++it) {
    int p = rnd(n);
    solve1(p);
  }
  for (int i = 0; i < m; ++i) {
    if (ans & (1ll << i)) {
      printf("1");
    } else {
      printf("0");
    }
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