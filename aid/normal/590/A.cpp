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

const int maxn = (int) 5e5 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  a[0] = a[1];
  a[n + 1] = a[n];
  return true;
}

void solve() {
  int t = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1]) {
      continue;
    }
    if (a[i] == a[i + 1]) {
      continue;
    }
    int j = i + 1;
    while (a[j] != a[j + 1]) {
      j++;
    }
    t = max(t, (j - i + 1) / 2);
    if (a[i - 1] == a[j]) {
      for (int k = i; k < j; k++) {
        a[k] = a[i - 1];
      }
    } else {
      for (int k = i; k < j; k++) {
        if (k - i + 1 < j - k) {
          a[k] = a[i - 1];
        } else {
          a[k] = a[j];
        }
      }
    }
    i = j;
  }
  printf("%d\n", t);
  for (int i = 1; i <= n; i++) {
    printf("%d ", a[i]);
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