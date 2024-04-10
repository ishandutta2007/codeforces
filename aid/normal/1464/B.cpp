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
char tmp[maxn];
int n;
string s;
int x, y;

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  scanf("%d%d", &x, &y);
  return true;
}

int cnt[maxn][2];

long long solve1() {
  cnt[0][0] = 0;
  cnt[0][1] = 0;
  for (int i = 0; i < n; ++i) {
    cnt[i + 1][0] = cnt[i][0] + (s[i] == '0');
    cnt[i + 1][1] = cnt[i][1] + (s[i] == '1');
  }
  long long cur = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      cur += (long long) (i - cnt[i][1]) * x;
    } else {
      cur += (long long) cnt[i][1] * y;
    }
  }
  long long res = cur;
  for (int i = 0; i < n; ++i) {
    if (s[i] != '?') {
      continue;
    }
    cur -= (long long) (i - cnt[i][0]) * y;
    cur -= (long long) (cnt[n][1] - cnt[i + 1][1]) * x;
    cur += (long long) cnt[i][0] * x;
    cur += (long long) ((n - (i + 1)) - (cnt[n][1] - cnt[i + 1][1])) * y;
    res = min(res, cur);
  }
  return res;
}

void solve() {
  long long res = solve1();
  reverse(s.begin(), s.end());
  swap(x, y);
  res = min(res, solve1());
  printf("%lld\n", res);
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