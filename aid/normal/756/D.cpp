#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
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

const int maxn = 5005, sigma = 27, mod = (int) 1e9 + 7;
int n;
char a[maxn];

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", a);
  return true;
}

int prv[maxn];
int lst[sigma];
int dpc[maxn][sigma];
int dpsum[maxn];
int c[maxn][maxn];

void solve() {
  int len = n;
  n = 1;
  for (int i = 1; i < len; i++) {
    if (a[i] != a[n - 1]) {
      a[n++] = a[i];
    }
  }
  for (int i = 0; i < sigma; i++) {
    lst[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    prv[i] = lst[a[i] - 'a'];
    lst[a[i] - 'a'] = i;
  }
  memset(dpc, 0, sizeof(dpc));
  memset(dpsum, 0, sizeof(dpsum));
  dpsum[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j > 0; j--) {
      int ch = a[i] - 'a';
      int pdp = dpc[j][ch];
      dpc[j][ch] = dpsum[j - 1];
      add(dpc[j][ch], mod - dpc[j - 1][ch]);
      int diff = dpc[j][ch];
      add(diff, mod - pdp);
      add(dpsum[j], diff);
    }
  }
  for (int i = 0; i <= len; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = c[i - 1][j - 1];
      add(c[i][j], c[i - 1][j]);
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    add(res, mul(dpsum[i], c[len - 1][i - 1]));
    //eprintf("i = %d, dpsum = %d\n", i, dpsum[i]);
  }
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}