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

const int maxn = 5005;
int n;
char tmp[maxn];
string s;

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

bool isPal(const string &s) {
  int n = sz(s);
  for (int i = 0; i < n - 1 - i; i++) {
    if (s[i] != s[n - 1 - i]) {
      return false;
    }
  }
  return true;
}

void solve() {
  for (int i = 1; i < n; i++) {
    string t = s.substr(i) + s.substr(0, i);
    if (t != s && isPal(t)) {
      printf("%d\n", 1);
      return;
    }
  }
  for (int i = 1; i < n - i; i++) {
    string t = s.substr(n - i) + s.substr(i, n - i - i) + s.substr(0, i);
    if (t != s && isPal(t)) {
      printf("%d\n", 2);
      return;
    }
  }
  printf("Impossible\n");
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