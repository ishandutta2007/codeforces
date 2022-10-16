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
int a, b, c, d;

bool read() {
  if (scanf("%d%d%d%d", &a, &b, &c, &d) < 4) {
    return false;
  }
  return true;
}

int ans[maxn];

void solve() {
  int even = a + c, odd = b + d;
  int n = even + odd;
  if (abs(even - odd) > 1) {
    printf("NO\n");
    return;
  }
  bool rev = false;
  if (odd > even) {
    swap(even, odd);
    swap(a, d);
    swap(b, c);
    rev = true;
  }
  for (int i = 0; i < a; i++) {
    ans[2 * i] = 0;
  }
  for (int i = 0; i < c; i++) {
    ans[2 * (a + i)] = 2;
  }
  int rem = b;
  for (int i = 0; i < a; i++) {
    if (2 * i + 1 >= n) {
      break;
    }
    if (!rem) {
      printf("NO\n");
      return;
    }
    ans[2 * i + 1] = 1;
    rem--;
  }
  for (int i = 2 * a + 1; i < n; i += 2) {
    if (rem) {
      ans[i] = 1;
      rem--;
    } else {
      ans[i] = 3;
    }
  }
  if (rev) {
    for (int i = 0; i < n; i++) {
      ans[i] = 3 - ans[i];
    }
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
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