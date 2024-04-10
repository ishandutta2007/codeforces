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
char tmp[maxn];
string t;

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  t = tmp;
  n = sz(t);
  return true;
}

void solve() {
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (t[i] != 'a') {
      k++;
    }
  }
  if (k & 1) {
    printf(":(\n");
    return;
  }
  k >>= 1;
  string s = t.substr(0, n - k);
  string s1 = t.substr(n - k);
  string ss;
  for (int i = 0; i < sz(s); i++) {
    if (s[i] != 'a') {
      ss += s[i];
    }
  }
  if (ss != s1) {
    printf(":(\n");
    return;
  }
  printf("%s\n", s.c_str());
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