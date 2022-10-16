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

const int maxn = 505;
char tmp[maxn];
string s, t;

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  t = tmp;
  return true;
}

void solve() {
  for (int i = 0; i < sz(s); ++i) {
    for (int j = i; j < sz(s); ++j) {
      if (j - i >= sz(t) || s[j] != t[j - i]) {
        break;
      }
      if (j - i == sz(t) - 1) {
        printf("YES\n");
        return;
      }
      for (int k = j - 1; k >= 0; --k) {
        if (j - i + j - k >= sz(t) || s[k] != t[j - i + j - k]) {
          break;
        }
        if (j - i + j - k == sz(t) - 1) {
          printf("YES\n");
          return;
        }
      }
    }
  }
  printf("NO\n");
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