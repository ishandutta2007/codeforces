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

const int maxx = (int) 1e6 + 5;
int lDiv[maxx];
vector<int> pr;

void precalc() {
  for (int i = 2; i < maxx; ++i) {
    if (!lDiv[i]) {
      lDiv[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < sz(pr) && pr[j] <= lDiv[i]; ++j) {
      int p = pr[j] * i;
      if (p >= maxx) {
        break;
      }
      lDiv[p] = pr[j];
    }
  }
}

const int maxn = (int) 2e5 + 5;
int n, e;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &e) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

int m;
int b[maxn];

long long solve1() {
  long long res = 0;
  for (int i = 0; i < m; ++i) {
    if (lDiv[b[i]] != b[i]) {
      continue;
    }
    int j = i;
    while (j > 0 && b[j - 1] == 1) {
      --j;
    }
    int k = i + 1;
    while (k < m && b[k] == 1) {
      ++k;
    }
    res += (long long) (i - j + 1) * (k - i) - 1;
  }
  return res;
}

void solve() {
  long long res = 0;
  for (int r = 0; r < e; ++r) {
    m = 0;
    for (int i = r; i < n; i += e) {
      b[m++] = a[i];
    }
    res += solve1();
  }
  printf("%lld\n", res);
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