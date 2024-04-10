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

const int maxn = (int) 1e5 + 5;
int lDiv[maxn];
vector<int> pr;

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
}

int n, k;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

map<vector<int>, int> mp;

void solve() {
  mp.clear();
  long long res = 0;
  for (int i = 0; i < n; i++) {
    vector<int> f;
    int x = a[i];
    while (x > 1) {
      int p = lDiv[x];
      int l = 0;
      while (!(x % p)) {
        x /= p;
        l++;
      }
      l %= k;
      if (l) {
        f.push_back(p);
        f.push_back(l);
      }
    }
    res += mp[f];
    for (int i = 1; i < sz(f); i += 2) {
      f[i] = k - f[i];
    }
    mp[f]++;
  }
  printf("%lld\n", res);
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