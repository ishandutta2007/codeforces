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

void precalc() {
}

const int maxn = (int) 1e5 + 5;
const long long maxx = (long long) 1e15;
int n, k;
int a[maxn];

int read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

vector<long long> ps;
map<long long, int> mp;

void solve() {
  {
    ps.clear();
    long long cur = 1;
    ps.push_back(cur);
    cur *= k;
    if (k == 1) {
    } else if (k == -1) {
      ps.push_back(cur);
    } else {
      while (abs(cur) < maxx) {
        ps.push_back(cur);
        cur *= k;
      }
    }
  }
  mp.clear();
  mp[0]++;
  long long sum = 0;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    for (int j = 0; j < sz(ps); j++) {
      auto it = mp.find(sum - ps[j]);
      if (it != mp.end()) {
        res += it->second;
      }
    }
    mp[sum]++;
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