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

const int maxn = (int) 2e5 + 5;
int lDiv[maxn];
vector<int> pr;

void precalc() {
  for (int i = 2; i < maxn; i++) {
    if (!lDiv[i]) {
      lDiv[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < sz(pr) && pr[j] <= lDiv[i]; j++) {
      int p = pr[j] * i;
      if (p >= maxn) {
        break;
      }
      lDiv[p] = pr[j];
    }
  }
}

int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int mn[maxn][2];
int cnt[maxn];

void solve() {
  for (int i = 0; i < maxn; i++) {
    for (int j = 0; j < 2; j++) {
      mn[i][j] = inf;
    }
    cnt[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int x = a[i];
    while (x > 1) {
      int p = lDiv[x];
      int k = 0;
      while (!(x % p)) {
        x /= p;
        k++;
      }
      cnt[p]++;
      if (k < mn[p][0]) {
        mn[p][1] = mn[p][0];
        mn[p][0] = k;
      } else if (k < mn[p][1]) {
        mn[p][1] = k;
      }
    }
  }
  long long res = 1;
  for (int i = 0; i < sz(pr); i++) {
    int p = pr[i];
    if (cnt[p] <= n - 2) {
      continue;
    }
    int k = 0;
    if (cnt[p] == n - 1) {
      k = mn[p][0];
    } else {
      k = mn[p][1];
    }
    for (int j = 0; j < k; j++) {
      res *= p;
    }
  }
  printf("%lld\n", res);
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