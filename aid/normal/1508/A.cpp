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
char tmp[maxn];
int n;
string s[3];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < 3; ++i) {
    scanf("%s", tmp);
    s[i] = tmp;
  }
  return true;
}

int cnt[3];
string t[2];
string ans;

void solve() {
  for (int i = 0; i < 3; ++i) {
    cnt[i] = 0;
    for (int j = 0; j < 2 * n; ++j) {
      if (s[i][j] == '1') {
        ++cnt[i];
      }
    }
  }
  bool found = false;
  bool ones = false;
  for (int i = 0; i < 3 && !found; ++i) {
    for (int j = i + 1; j < 3 && !found; ++j) {
      if (cnt[i] >= n && cnt[j] >= n) {
        t[0] = s[i];
        t[1] = s[j];
        found = true;
        ones = true;
      } else if (cnt[i] <= n && cnt[j] <= n) {
        t[0] = s[i];
        t[1] = s[j];
        found = true;
        ones = false;
      }
    }
  }
  char need = (char) ('0' + ones);
  int i = 0, j = 0;
  ans.clear();
  for (int it = 0; it < n; ++it) {
    while (t[0][i] != need) {
      ans += t[0][i];
      ++i;
    }
    while (t[1][j] != need) {
      ans += t[1][j];
      ++j;
    }
    ans += need;
    ++i;
    ++j;
  }
  while (i < 2 * n) {
    ans += t[0][i];
    ++i;
  }
  while (j < 2 * n) {
    ans += t[1][j];
    ++j;
  }
  printf("%s\n", ans.c_str());
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