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
int n;
long long lens[maxn];
int a[maxn];
char tmp[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &lens[i]);
    lens[i] *= 2;
  }
  scanf("%s", tmp);
  for (int i = 0; i < n; i++) {
    a[i] = (tmp[i] == 'G' ? 5 : (tmp[i] == 'W' ? 3 : -1));
  }
  return true;
}

long long bal[maxn];
long long fly[maxn];

void solve() {
  bal[0] = 0;
  bool was = false;
  long long t = 0;
  for (int i = 0; i < n; i++) {
    bal[i + 1] = bal[i] + (a[i] == -1 ? -1 : 1) * lens[i];
    t += (a[i] == -1 ? 1 : a[i]) * lens[i];
    if (bal[i + 1] < 0) {
      if (was) {
        t += 3 * -bal[i + 1];
      } else {
        t += 5 * -bal[i + 1];
      }
      bal[i + 1] = 0;
    }
    if (a[i] == 3) {
      was = true;
    }
  }
  if (bal[n] == 0) {
    assert(!(t & 1));
    t >>= 1;
    printf("%lld\n", t);
    return;
  }
  for (int i = 0; i < n; i++) {
    fly[i] = 0;
  }
  long long b = bal[n];
  for (int i = n - 1; i >= 0 && b; i--) {
    if (a[i] != 5) {
      b = min(b, bal[i]);
      continue;
    }
    long long x = min(b / 2, lens[i]);
    fly[i] = x;
    b -= 2 * x;
    t -= (a[i] - 1) * x;
    b = min(b, bal[i]);
  }
  bal[0] = 0;
  for (int i = 0; i < n; i++) {
    bal[i + 1] = bal[i] + (a[i] == -1 ? -1 : 1) * (lens[i] - fly[i]) - fly[i];
    if (bal[i + 1] < 0) {
      bal[i + 1] = 0;
    }
  }
  b = bal[n];
  for (int i = n - 1; i >= 0 && b; i--) {
    if (a[i] != 3) {
      b = min(b, bal[i]);
      continue;
    }
    long long x = min(b / 2, lens[i]);
    fly[i] = x;
    b -= 2 * x;
    t -= (a[i] - 1) * x;
    b = min(b, bal[i]);
  }
  assert(!(t & 1));
  t >>= 1;
  printf("%lld\n", t);
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