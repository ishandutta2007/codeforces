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

int d, m;

bool read() {
  if (scanf("%d%d", &d, &m) < 2) {
    return false;
  }
  return true;
}

int mul(int a, int b) {
  return (long long) a * b % m;
}

void add(int &a, int b) {
  a += b;
  if (a >= m) {
    a -= m;
  }
}

vector<int> cnt;
vector<int> dp;

void solve() {
  int bs = 32 - __builtin_clz(d);
  cnt.clear();
  cnt.resize(bs);
  for (int bit = 0; bit < bs; bit++) {
    if (bit < bs - 1) {
      cnt[bit] = (1 << bit);
    } else {
      cnt[bit] = d + 1 - (1 << bit);
    }
    cnt[bit] %= m;
  }
  dp.clear();
  dp.resize(bs);
  int res = 0;
  for (int bit = 0; bit < bs; bit++) {
    auto &cur = dp[bit];
    cur = 1 % m;
    for (int prv = 0; prv < bit; prv++) {
      add(cur, dp[prv]);
    }
    cur = mul(cur, cnt[bit]);
    add(res, cur);
  }
  printf("%d\n", res);
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