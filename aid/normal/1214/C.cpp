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

const int maxn = (int) 2e5 + 5;
int n;
char tmp[maxn];
string s;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

bool check(const string &s) {
  int bal = 0;
  for (int i = 0; i < sz(s); i++) {
    if (s[i] == ')') {
      bal--;
    } else {
      bal++;
    }
    if (bal < 0) {
      return false;
    }
  }
  return bal == 0;
}

void solve() {
  {
    int pos = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '(') {
        pos = i;
        break;
      }
    }
    if (pos != -1) {
      string t = "(" + s.substr(0, pos) + s.substr(pos + 1);
      if (check(t)) {
        printf("Yes\n");
        return;
      }
    }
  }
  {
    int pos = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == ')') {
        pos = i;
        break;
      }
    }
    if (pos != -1) {
      string t = s.substr(0, pos) + s.substr(pos + 1) + ")";
      if (check(t)) {
        printf("Yes\n");
        return;
      }
    }
  }
  printf("No\n");
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