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

const int maxn = 105;
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

const int d = 10;
int cnt[d];

void solve() {
  for (int i = 0; i < d; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cnt[s[i] - '0']++;
  }
  if (!cnt[0]) {
    printf("cyan\n");
    return;
  }
  cnt[0]--;
  int s = 0;
  bool even = false;
  for (int i = 0; i < d; i++) {
    s += cnt[i] * i;
    if (!(i & 1) && cnt[i]) {
      even = true;
    }
  }
  if (even && !(s % 3)) {
    printf("red\n");
    return;
  }
  printf("cyan\n");
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