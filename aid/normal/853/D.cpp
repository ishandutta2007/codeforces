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

const int maxn = (int) 3e5 + 5;
int n;
int a[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int pref[maxn];
int suff[maxn];
map<int, int> mp[2];
int addbal[2], addc[2];

void solve() {
  for (int it = 0; it < 2; it++) {
    mp[it].clear();
    addbal[it] = 0;
    addc[it] = 0;
  }
  pref[0] = 0;
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + a[i];
  }
  suff[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    suff[i] = suff[i + 1] + a[i];
  }
  int res = pref[n];
  for (int i = 0; i < n; i++) {
    int t = (a[i] == 2000);
    for (int x = 100; x <= a[i]; x += 100) {
      auto it = mp[!t].lower_bound(suff[i + 1] + x - addbal[!t]);
      if (it != mp[!t].end()) {
        res = min(res, it->second + addc[!t] + a[i] - x);
      }
    }
    {
      addbal[t] -= a[i];
      while (!mp[t].empty() && mp[t].begin()->first + addbal[t] < 0) {
        mp[t].erase(mp[t].begin());
      }
      addbal[!t] += a[i] / 10;
      addc[!t] += a[i];
    }
    for (int x = 100; x <= a[i]; x += 100) {
      int c = pref[i] + a[i] - x, bal = pref[i] / 10 - x;
      if (bal < 0) {
        continue;
      }
      if (!mp[t].count(bal - addbal[t])) {
        mp[t][bal - addbal[t]] = inf - addc[t];
      }
      auto &val = mp[t][bal - addbal[t]];
      val = min(val, c - addc[t]);
    }
  }
  for (int t = 0; t < 2; t++) {
    auto it = mp[t].begin();
    if (it != mp[t].end()) {
      res = min(res, it->second + addc[t]);
    }
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