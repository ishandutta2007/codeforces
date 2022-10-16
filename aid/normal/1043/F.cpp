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

int gcd(int a, int b) {
  return (b ? gcd(b, a % b) : a);
}

const int maxn = (int) 3e5 + 5;
int lDiv[maxn];
vector<int> pr;
int mu[maxn];

void precalc() {
  for (int i = 2; i < maxn; i++) {
    if (!lDiv[i]) {
      lDiv[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < sz(pr) && pr[j] <= lDiv[i]; j++) {
      int p = pr[j] * i;
      if (p >= maxn) {
        break;
      }
      lDiv[p] = pr[j];
    }
  }
  mu[1] = 1;
  for (int i = 2; i < maxn; i++) {
    int p = lDiv[i];
    int pi = i / p;
    if (lDiv[pi] == lDiv[i]) {
      mu[i] = 0;
      continue;
    }
    mu[i] = -1 * mu[pi];
  }
}

int n;
int xs[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &xs[i]);
  }
  return true;
}

long long a[maxn], b[maxn];

void solve() {
  {
    int g = 0;
    for (int i = 0; i < n; i++) {
      g = gcd(g, xs[i]);
    }
    if (g > 1) {
      printf("-1\n");
      return;
    }
  }
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (int i = 0; i < n; i++) {
    a[xs[i]]++;
  }
  for (int i = 0; i < maxn; i++) {
    a[i] = (a[i] > 0);
    b[i] = a[i];
  }
  for (int i = 1; i < maxn; i++) {
    for (int j = 2 * i; j < maxn; j += i) {
      a[i] += a[j];
    }
  }
  int res = 1;
  while (!b[1]) {
    for (int i = 1; i < maxn; i++) {
      for (int j = 2 * i; j < maxn; j += i) {
        b[i] += b[j];
      }
    }
    for (int i = 0; i < maxn; i++) {
      b[i] *= a[i];
    }
    for (int i = 1; i < maxn; i++) {
      for (int j = 2 * i; j < maxn; j += i) {
        b[i] += mu[j / i] * b[j];
      }
    }
    for (int i = 0; i < maxn; i++) {
      b[i] = (b[i] > 0);
    }
    res++;
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