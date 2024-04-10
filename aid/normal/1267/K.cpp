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

const int maxk = 25;
long long c[maxk][maxk];

void precalc() {
  for (int i = 0; i < maxk; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  }
}

long long x;

bool read() {
  if (scanf("%lld", &x) < 1) {
    return false;
  }
  return true;
}

vector<int> a;

void solve() {
  a.clear();
  int k = 2;
  while (x) {
    a.push_back(x % k);
    x /= k;
    k++;
  }
  sort(a.begin(), a.end(), greater<int>());
  long long res = 1;
  for (int j = 0; j < sz(a);) {
    int i = j;
    while (j < sz(a) && a[j] == a[i]) {
      j++;
    }
    int cnt = (k - max(a[i] + 1, 2)) - i;
    res *= c[cnt][j - i];
  }
  if (a.back() == 0) {
    a.pop_back();
    k--;
    long long r = 1;
    for (int j = 0; j < sz(a);) {
      int i = j;
      while (j < sz(a) && a[j] == a[i]) {
        j++;
      }
      int cnt = (k - max(a[i] + 1, 2)) - i;
      r *= c[cnt][j - i];
    }
    res -= r;
  }
  res--;
  printf("%lld\n", res);
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