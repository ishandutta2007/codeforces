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

const int mod = 998244353;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

const int maxn = (int) 2e5 + 5;
int n, k;
int a[maxn], b[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }
  for (int i = 0; i < k; ++i) {
    scanf("%d", &b[i]);
    --b[i];
  }
  return true;
}

int p[maxn];
int used[maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    p[a[i]] = i;
    used[i] = false;
  }
  for (int i = 0; i < k; ++i) {
    used[p[b[i]]] = true;
  }
  int res = 1;
  for (int i = 0; i < k; ++i) {
    int cnt = 0;
    int pos = p[b[i]];
    for (int d = -1; d <= 1; d += 2) {
      int j = pos + d;
      if (0 <= j && j < n && !used[j]) {
        ++cnt;
      }
    }
    res = mul(res, cnt);
    used[pos] = false;
  }
  printf("%d\n", res);
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