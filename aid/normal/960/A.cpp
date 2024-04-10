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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 5e3 + 5;
string s;
char tmp[maxn];

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  return true;
}

void solve() {
  int a = 0, b = 0, c = 0;
  int i = 0;
  while (i < sz(s) && s[i] == 'a') {
    i++;
    a++;
  }
  while (i < sz(s) && s[i] == 'b') {
    i++;
    b++;
  }
  while (i < sz(s) && s[i] == 'c') {
    i++;
    c++;
  }
  if (i < sz(s) || !a || !b || !(c == a || c == b)) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
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