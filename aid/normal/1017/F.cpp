#ifdef DEBUG
//#define _GLIBCXX_DEBUG
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

const int maxn = (int) 3e8 + 10;
const int len = maxn / 3 + 10;
bitset<len> bs;

void precalc() {
  bs.set();
  bs[0] = false;
  for (int i6 = 0; i6 * 6 < maxn; i6++) {
    for (int it = 0; it < 2; it++) {
      if (!bs[i6 * 2 + it]) {
        continue;
      }
      int x = i6 * 6 + (!it ? 1 : 5);
      if (x >= maxn) {
        break;
      }
      for (int j6 = 0; x * j6 * 6 < maxn; j6++) {
        for (int it1 = 0; it1 < 2; it1++) {
          int y = j6 * 6 + (!it1 ? 1 : 5);
          int z = x * y;
          if (y == 1 || z >= maxn) {
            continue;
          }
          bs[(z / 6) * 2 + ((z % 6) == 5)] = false;
        }
      }
    }
  }
}

int n;
unsigned int a, b, c, d;

int read() {
  if (scanf("%d%u%u%u%u", &n, &a, &b, &c, &d) < 5) {
    return false;
  }
  return true;
}

unsigned int get(unsigned int p) {
  unsigned int val = ((a * p + b) * p + c) * p + d;
  unsigned int x = n;
  unsigned int res = 0;
  while (x) {
    x /= p;
    res += x;
  }
  res *= val;
  return res;
}

void solve() {
  unsigned int res = get(2) + get(3);
  for (int i = 4; i <= n; i++) {
    if (!(i % 2) || !(i % 3) || !bs[(i / 6) * 2 + ((i % 6) == 5)]) {
      continue;
    }
    res += get(i);
  }
  printf("%u\n", res);
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