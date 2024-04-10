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
int n, l;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &l) < 2) {
    return false;
  }
  a[0] = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  a[n + 1] = l;
  n += 2;
  return true;
}

ld pref[maxn], suff[maxn];

void solve() {
  pref[0] = 0;
  for (int i = 1; i < n; ++i) {
    pref[i] = pref[i - 1] + (ld) (a[i] - a[i - 1]) / i;
  }
  suff[n - 1] = 0;
  for (int i = n - 2; i >= 0; --i) {
    suff[i] = suff[i + 1] + (ld) (a[i + 1] - a[i]) / (n - 1 - i);
  }
  for (int i = 1; i < n; ++i) {
    if (suff[i] < pref[i]) {
      ld t = max(pref[i - 1], suff[i]);
      ld d = a[i] - a[i - 1];
      ld vl = i;
      ld vr = n - i;
      d -= (t - pref[i - 1]) * vl;
      d -= (t - suff[i]) * vr;
      ld res = t + d / (vl + vr);
      printf("%.12f\n", (double) res);
      break;
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