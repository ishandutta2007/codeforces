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
string s;

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

void solve() {
  int pos = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '#') {
      pos = i;
    }
  }
  assert(pos != -1);
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (s[i] == '#') {
      ans.push_back(1);
      s[i] = ')';
    }
  }
  int bal = 0;
  for (int i = 0; i < n; i++) {
    bal += (s[i] == '(' ? 1 : -1);
    if (bal < 0) {
      printf("-1\n");
      return;
    }
  }
  ans.back() += bal;
  s.insert(pos, string(bal, ')'));
  n = sz(s);
  bal = 0;
  for (int i = 0; i < n; i++) {
    bal += (s[i] == '(' ? 1 : -1);
    if (bal < 0) {
      printf("-1\n");
      return;
    }
  }
  assert(bal == 0);
  for (int i = 0; i < sz(ans); i++) {
    printf("%d\n", ans[i]);
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