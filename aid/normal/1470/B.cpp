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
      int p = i * pr[j];
      if (p >= maxx) {
        break;
      }
      lDiv[p] = pr[j];
    }
  }
}

const int maxn = (int) 3e5 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

int get(int x) {
  int res = 1;
  while (x > 1) {
    int p = lDiv[x];
    int k = 0;
    while (!(x % p)) {
      x /= p;
      ++k;
    }
    if (k & 1) {
      res *= p;
    }
  }
  return res;
}

void solve() {
  for (int i = 0; i < n; ++i) {
    a[i] = get(a[i]);
  }
  sort(a, a + n);
  int res0 = 0;
  int cnt0 = 0;
  for (int j = 0; j < n;) {
    int i = j;
    while (j < n && a[j] == a[i]) {
      ++j;
    }
    int k = j - i;
    res0 = max(res0, k);
    if (a[i] == 1 || !(k & 1)) {
      cnt0 += k;
    }
  }
  int res1 = max(res0, cnt0);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    long long w;
    scanf("%lld", &w);
    if (!w) {
      printf("%d\n", res0);
    } else {
      printf("%d\n", res1);
    }
  }
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