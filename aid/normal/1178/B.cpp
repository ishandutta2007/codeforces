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

const int maxn = (int) 1e6 + 5;
int n;
string s;
char tmp[maxn];

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

int pref[maxn], suff[maxn];

void solve() {
  pref[0] = 0;
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i];
    if (i && s[i - 1] == 'v' && s[i] == 'v') {
      pref[i + 1]++;
    }
  }
  suff[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    suff[i] = suff[i + 1];
    if (i + 1 < n && s[i] == 'v' && s[i + 1] == 'v') {
      suff[i]++;
    }
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'o') {
      res += (long long) pref[i] * suff[i + 1];
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