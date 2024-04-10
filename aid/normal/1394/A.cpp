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
int n, d, m;
vector<int> big, small;

bool read() {
  if (scanf("%d%d%d", &n, &d, &m) < 3) {
    return false;
  }
  big.clear();
  small.clear();
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (x > m) {
      big.push_back(x);
    } else {
      small.push_back(x);
    }
  }
  return true;
}

long long sum[maxn];

void solve() {
  sort(big.begin(), big.end(), greater<int>());
  sort(small.begin(), small.end(), greater<int>());
  sum[0] = 0;
  for (int i = 0; i < sz(small); ++i) {
    sum[i + 1] = sum[i] + small[i];
  }
  long long res = sum[sz(small)];
  long long sbig = 0;
  for (int i = 0; i < sz(big); ++i) {
    sbig += big[i];
    int used = i * d + (i + 1);
    if (used > n) {
      break;
    }
    int rem = n - used;
    long long cur = sbig + sum[min(rem, sz(small))];
    res = max(res, cur);
  }
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