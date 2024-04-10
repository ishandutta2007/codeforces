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

long long n, k;

int read() {
  if (scanf("%lld%lld", &n, &k) < 2) {
    return false;
  }
  k--;
  return true;
}

long long getD(long long n, long long k) {
  assert(k >= 2);
  k -= 2;
  map<long long, long long> mp;
  mp[n - 2] = 1;
  while (!mp.empty()) {
    auto it = mp.end();
    it--;
    long long len = it->first, cnt = it->second;
    mp.erase(it);
    if (k < cnt) {
      return (len + 1) / 2;
    }
    k -= cnt;
    for (int it = 0; it < 2; it++) {
      long long nlen = (!it ? (len - 1) / 2 : len / 2);
      if (!nlen) {
        continue;
      }
      mp[nlen] += cnt;
    }
  }
  assert(false);
}

long long getCnt(long long n, long long d) {
  map<long long, long long> mp;
  mp[n - 2] = 1;
  long long res = 2;
  while (!mp.empty()) {
    auto it = mp.end();
    it--;
    long long len = it->first, cnt = it->second;
    mp.erase(it);
    if ((len + 1) / 2 < d) {
      return res;
    }
    res += cnt;
    for (int it = 0; it < 2; it++) {
      long long nlen = (!it ? (len - 1) / 2 : len / 2);
      if (!nlen) {
        continue;
      }
      mp[nlen] += cnt;
    }
  }
  return res;
}

long long get(long long n, long long k) {
  if (!k) {
    return 0;
  }
  if (k == 1) {
    return n - 1;
  }
  if (k == 2) {
    return (n - 1) / 2;
  }
  long long d = getD(n, k);
  long long nl = (n + 1) / 2, nr = (n + 2) / 2;
  long long xl = getCnt(nl, d), xr = getCnt(nr, d + 1);
  if (k < xl + xr - 1) {
    return get(nl, k - (xr - 1));
  } else {
    return nl - 1 + get(nr, k - (xl - 1));
  }
}

void solve() {
  printf("%lld\n", get(n, k) + 1);
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