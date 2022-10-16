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
char tmp[maxn];
int n;
string s;

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

const int sigma = 26;
int cnt[sigma];
long long cnt2[sigma][sigma];

void solve() {
  for (int i = 0; i < sigma; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < sigma; i++) {
    for (int j = 0; j < sigma; j++) {
      cnt2[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    int c = s[i] - 'a';
    for (int cc = 0; cc < sigma; cc++) {
      cnt2[cc][c] += cnt[cc];
    }
    cnt[c]++;
  }
  long long res = 0;
  for (int i = 0; i < sigma; i++) {
    res = max(res, (long long) cnt[i]);
  }
  for (int i = 0; i < sigma; i++) {
    for (int j = 0; j < sigma; j++) {
      res = max(res, cnt2[i][j]);
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