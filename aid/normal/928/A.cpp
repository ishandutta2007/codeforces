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

const int maxlen = 55, maxn = 1005;
int n;
string s;
string ts[maxn];
char tmp[maxlen];

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    ts[i] = tmp;
  }
  return true;
}

bool bad(char a, char b) {
  for (int it = 0; it < 2; it++) {
    if (a == b) {
      return false;
    }
    if ((('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z')) && (a ^ 32) == b) {
      return false;
    }
    if (a == '0' && (b == 'o' || b == 'O')) {
      return false;
    }
    if (a == '1' && (b == 'l' || b == 'L' || b == 'i' || b == 'I')) {
      return false;
    }
    if ((a == 'i' || a == 'I') && (b == 'l' || b == 'L')) {
      return false;
    }
    swap(a, b);
  }
  return true;
}

bool check(const string &s, const string &t) {
  if (sz(s) != sz(t)) {
    return false;
  }
  for (int i = 0; i < sz(s); i++) {
    if (bad(s[i], t[i])) {
      return false;
    }
  }
  return true;
}

void solve() {
  for (int i = 0; i < n; i++) {
    if (check(s, ts[i])) {
      printf("No\n");
      return;
    }
  }
  printf("Yes\n");
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