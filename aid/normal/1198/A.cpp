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

const int maxn = (int) 4e5 + 5;
int n, I;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &I) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int sr[maxn];

void solve() {
  I *= 8;
  int lk = I / n;
  int k;
  if (lk > 20) {
    k = n;
  } else {
    k = 1;
    for (int i = 0; i < lk; i++) {
      k *= 2;
    }
  }
  sort(a, a + n);
  vector<pair<int, int>> b;
  for (int j = 0; j < n;) {
    int i = j;
    while (j < n && a[j] == a[i]) {
      j++;
    }
    b.push_back(make_pair(a[i], j - i));
  }
  sr[sz(b)] = 0;
  for (int i = sz(b) - 1; i >= 0; i--) {
    sr[i] = sr[i + 1] + b[i].second;
  }
  int sl = 0;
  int res = n;
  for (int i = 0; i < sz(b); i++) {
    int j = min(sz(b), i + k);
    res = min(res, sl + sr[j]);
    sl += b[i].second;
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