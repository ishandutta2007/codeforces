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

void precalc() {
}

const int maxn = (int) 1e5 + 5;
int n;
int v[maxn], t[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i]);
  }
  return true;
}

long long s[maxn];
vector<int> evs[maxn];

void solve() {
  s[0] = 0;
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + t[i];
  }
  for (int i = 0; i < n; i++) {
    evs[i].clear();
  }
  for (int i = 0; i < n; i++) {
    if (s[n] - s[i] <= v[i]) {
      continue;
    }
    int l = i, r = n;
    while (l < r - 1) {
      int m = (l + r) / 2;
      if (s[m] - s[i] <= v[i]) {
        l = m;
      } else {
        r = m;
      }
    }
    evs[l].push_back(v[i] - (s[l] - s[i]));
  }
  int k = 0;
  for (int i = 0; i < n; i++) {
    k++;
    long long cur = 0;
    for (int j = 0; j < sz(evs[i]); j++) {
      cur += evs[i][j];
      k--;
    }
    cur += (long long) k * t[i];
    printf("%lld ", cur);
  }
  printf("\n");
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