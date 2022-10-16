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
int p[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
  }
  return true;
}

void solve() {
  int mx = 0, cnt = 0;
  for (int s = 0; s < n; ++s) {
    if (!((s == 0 || p[s - 1] < p[s]) && (s + 1 == n || p[s] > p[s + 1]))) {
      continue;
    }
    int l = s;
    while (l > 0 && p[l - 1] < p[l]) {
      --l;
    }
    int r = s;
    while (r + 1 < n && p[r] > p[r + 1]) {
      ++r;
    }
    int a = s - l, b = r - s;
    for (int it = 0; it < 2; ++it) {
      int cur = (!it ? a : b);
      if (cur > mx) {
        mx = cur;
        cnt = 0;
      }
      if (cur == mx) {
        ++cnt;
      }
    }
  }
  int res = 0;
  for (int s = 1; s + 1 < n; ++s) {
    if (!(p[s - 1] < p[s] && p[s] > p[s + 1])) {
      continue;
    }
    int l = s - 1;
    while (l > 0 && p[l - 1] < p[l]) {
      --l;
    }
    int r = s + 1;
    while (r + 1 < n && p[r] > p[r + 1]) {
      ++r;
    }
    int a = s - l, b = r - s;
    if (a == b && !(a & 1) && mx == a && cnt <= 2) {
      ++res;
    }
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