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

const int maxn = (int) 5e5 + 5;
string s, t;
char tmp[maxn];

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  scanf("%s", tmp);
  t = tmp;
  return true;
}

int pi[maxn];

int getPi(const string &s) {
  int n = sz(s);
  pi[0] = -1;
  for (int i = 0; i < sz(s); i++) {
    auto &cur = pi[i + 1];
    for (cur = pi[i]; cur >= 0 && s[i] != s[cur]; cur = pi[cur]) ;
    cur++;
  }
  return pi[n];
}

void solve() {
  int bor = getPi(t);
  int a = 0, b = 0;
  for (int i = 0; i < sz(s); i++) {
    if (s[i] == '0') {
      a++;
    } else {
      b++;
    }
  }
  for (int i = 0; i < sz(t); i++) {
    if (t[i] == '0') {
      a--;
    } else {
      b--;
    }
  }
  if (a < 0 || b < 0) {
    printf("%s\n", s.c_str());
    return;
  }
  string ans = t;
  int x = 0, y = 0;
  for (int i = bor; i < sz(t); i++) {
    if (t[i] == '0') {
      x++;
    } else {
      y++;
    }
  }
  while (a >= x && b >= y) {
    ans += t.substr(bor);
    a -= x;
    b -= y;
  }
  while (a) {
    ans += '0';
    a--;
  }
  while (b) {
    ans += '1';
    b--;
  }
  printf("%s\n", ans.c_str());
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