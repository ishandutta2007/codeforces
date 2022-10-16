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

int gcd(int a, int b) {
  return (b ? gcd(b, a % b) : a);
}

const int maxn = (int) 1e5 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int b[maxn];

vector<int> fact(int n) {
  vector<int> f;
  for (int d = 2; d * d <= n; d++) {
    if (!(n % d)) {
      f.push_back(d);
      while (!(n % d)) {
        n /= d;
      }
    }
  }
  if (n > 1) {
    f.push_back(n);
  }
  return f;
}

void solve() {
  while (true) {
    if ((double) clock() / CLOCKS_PER_SEC > 0.45) {
      break;
    }
    for (int i = 0; i < n; i++) {
      b[i] = -1;
    }
    bool ok = true;
    for (int it = 0; it < 20 && ok; it++) {
      int x = a[rnd(n)];
      vector<int> ps = fact(x);
      for (auto p : ps) {
        int msk = 0;
        vector<int> x;
        for (int i = 0; i < n; i++) {
          if (!(a[i] % p)) {
            continue;
          }
          if (b[i] != -1) {
            msk |= (1 << b[i]);
            continue;
          }
          x.push_back(i);
        }
        if (!(msk & 1)) {
          if (x.empty()) {
            ok = false;
            break;
          }
          int pos = rnd(sz(x));
          int i = x[pos];
          x.erase(x.begin() + pos);
          b[i] = 0;
          msk |= 1;
        }
        if (!(msk & 2)) {
          if (x.empty()) {
            ok = false;
            break;
          }
          int pos = rnd(sz(x));
          int i = x[pos];
          x.erase(x.begin() + pos);
          b[i] = 1;
          msk |= 2;
        }
      }
      if (!ok) {
        break;
      }
    }
    if (!ok) {
      continue;
    }
    int g[2] = {0, 0};
    for (int i = 0; i < n; i++) {
      if (b[i] == -1) {
        b[i] = rnd(2);
      }
      g[b[i]] = gcd(g[b[i]], a[i]);
    }
    if (g[0] != 1 || g[1] != 1) {
      continue;
    }
    printf("YES\n");
    for (int i = 0; i < n; i++) {
      printf("%d ", b[i] + 1);
    }
    printf("\n");
    return;
  }
  printf("NO\n");
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