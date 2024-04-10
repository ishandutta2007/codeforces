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

const int maxn = (int) 1e6 + 5;
int lDiv[maxn], gDiv[maxn];
vector<int> pr;

void precalc() {
  for (int i = 2; i < maxn; i++) {
    if (!lDiv[i]) {
      lDiv[i] = i;
      gDiv[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < sz(pr) && pr[j] <= lDiv[i]; j++) {
      int p = i * pr[j];
      if (p >= maxn) {
        break;
      }
      lDiv[p] = pr[j];
      gDiv[p] = gDiv[i];
    }
  }
}

int x;

int read() {
  if (scanf("%d", &x) < 1) {
    return false;
  }
  return true;
}

void solve() {
  assert(lDiv[x] != x);
  int res = inf;
  for (int y = x - gDiv[x] + 1; y <= x; y++) {
    if (lDiv[y] == y) {
      continue;
    }
    res = min(res, y - gDiv[y] + 1);
  }
  printf("%d\n", res);
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