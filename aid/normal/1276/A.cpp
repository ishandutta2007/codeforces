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

const int maxn = 1.5e5 + 5;
char tmp[maxn];
int n;
string s;

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

int del[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    del[i] = false;
  }
  for (int i = 0; i < n;) {
    if (i + 5 <= n && s.substr(i, 5) == "twone") {
      del[i + 2] = true;
      i += 5;
    } else if (i + 3 <= n && s.substr(i, 3) == "one") {
      del[i + 1] = true;
      i += 3;
    } else if (i + 3 <= n && s.substr(i, 3) == "two") {
      del[i + 1] = true;
      i += 3;
    } else {
      i++;
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (del[i]) {
      ans.push_back(i);
    }
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d ", ans[i] + 1);
  }
  printf("\n");
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