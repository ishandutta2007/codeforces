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
string a, b;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", tmp);
  a = tmp;
  scanf("%s", tmp);
  b = tmp;
  return true;
}

int get(const string &a) {
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == '1') {
      ++res;
    }
  }
  return res;
}

int getCnt(const string &a, const string &b) {
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      ++res;
    }
  }
  return res;
}

int getEven() {
  int ca = get(a), cb = get(b);
  if (ca == cb) {
    return getCnt(a, b);
  }
  return inf;
}

int getOdd() {
  for (int i = 0; i < n; ++i) {
    b[i] = (char) ('0' + ((b[i] - '0') ^ 1));
  }
  int ca = get(a), cb = get(b);
  int res = inf;
  if (ca == cb + 1) {
    res = getCnt(a, b);
  }
  for (int i = 0; i < n; ++i) {
    b[i] = (char) ('0' + ((b[i] - '0') ^ 1));
  }
  return res;
}

void solve() {
  int res = min(getEven(), getOdd());
  if (res >= inf) {
    res = -1;
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