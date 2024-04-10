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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

const int maxn = (int) 1e5 + 5, mod = (int) 1e9 + 7;
int n, m, h;
int f[maxn], inv[maxn], finv[maxn];

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

pair<int, int> gcd(int a, int b) {
  if (!b) {
    return make_pair(1, 0);
  }
  pair<int, int> p = gcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

int getInv(int x) {
  int res = gcd(x, mod).first;
  if (res < 0) {
    res += mod;
  }
  return res;
}

int c(int n, int k) {
  return mul(f[n], mul(finv[k], finv[n - k]));
}

void precalc() {
  f[0] = 1;
  for (int i = 1; i < maxn; i++) {
    f[i] = mul(f[i - 1], i);
  }
  inv[1] = 1;
  for (int i = 2; i < maxn; i++) {
    inv[i] = (mod - (long long) (mod / i) * inv[mod % i] % mod) % mod;
  }
  finv[0] = 1;
  for (int i = 1; i < maxn; i++) {
    finv[i] = mul(finv[i - 1], inv[i]);
  }
}

int read() {
  if (scanf("%d%d%d", &n, &m, &h) < 3) {
    return false;
  }
  return true;
}

void solve() {
  int all = 0;
  for (int it = 0; it < 2; it++) {
    for (int len = 1; (len + 1) / 2 <= n && len / 2 <= m; len++) {
      if (len == 1) {
        if (!m) {
          add(all, 1);
        }
        continue;
      }
      add(all, mul(c(n - 1, (len + 1) / 2 - 1), c(m - 1, len / 2 - 1)));
    }
    swap(n, m);
  }
  int good = 0;
  for (int it = 0; it < 2; it++) {
    for (int len = 1; (len + 1) / 2 * (it ? h + 1 : 1) <= n && len / 2 * (it ? 1 : h + 1) <= m; len++) {
      if (len == 1) {
        if (!m) {
          if (it) {
            if (n > h) {
              add(good, 1);
            }
          } else {
            add(good, 1);
          }
        }
        continue;
      }
      add(good, mul(c(n - it * (len + 1) / 2 * h - 1, (len + 1) / 2 - 1), c(m - (1 - it) * len / 2 * h - 1, len / 2 - 1)));
    }
    swap(n, m);
  }
  eprintf("%d %d\n", all, good);
  printf("%d\n", mul(good, getInv(all)));
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