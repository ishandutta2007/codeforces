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

long long k;

bool read() {
  if (scanf("%lld", &k) < 1) {
    return false;
  }
  return true;
}

const string s = "codeforces";
vector<int> cnt;

void solve() {
  cnt.clear();
  cnt.resize(sz(s), 1);
  long long cur = 1;
  for (int x = 1; cur < k; x++) {
    for (int i = 0; i < sz(s) && cur < k; i++) {
      cur /= x;
      cnt[i] = x + 1;
      cur *= x + 1;
    }
  }
  string ans;
  for (int i = 0; i < sz(s); i++) {
    ans += string(cnt[i], s[i]);
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