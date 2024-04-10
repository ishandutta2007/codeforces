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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

string s[2];
int n;
char tmp[100];

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s[0] = tmp;
  scanf("%s", tmp);
  s[1] = tmp;
  scanf("%d", &n);
  return true;
}

void solve() {
  printf("%s %s\n", s[0].c_str(), s[1].c_str());
  for (int i = 0; i < n; i++) {
    string t, ns;
    scanf("%s", tmp);
    t = tmp;
    scanf("%s", tmp);
    ns = tmp;
    for (int it = 0; it < 2; it++) {
      if (s[it] == t) {
        s[it] = ns;
      }
    }
    printf("%s %s\n", s[0].c_str(), s[1].c_str());
  }
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