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

const int maxn = (int) 2e5 + 5;
int n, t;
string s;
char tmp[maxn];

int read() {
  if (scanf("%d%d", &n, &t) < 2) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

void solve() {
  int pos = 0;
  while (s[pos] != '.') {
    pos++;
  }
  pos++;
  while (pos < n && s[pos] < '5') {
    pos++;
  }
  if (pos >= n) {
    printf("%s\n", s.c_str());
    return;
  }
  t--;
  s.resize(pos);
  pos--;
  while (s[pos] == '4' && t) {
    s.resize(pos);
    pos--;
    t--;
  }
  if (s[pos] == '.') {
    s.resize(pos);
    pos--;
  }
  while (pos >= 0 && s[pos] == '9') {
    s[pos] = '0';
    pos--;
  }
  if (pos >= 0) {
    s[pos]++;
  } else {
    s = "1" + s;
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