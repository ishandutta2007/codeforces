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

long long gcd(long long a, long long b) {
  return (b ? gcd(b, a % b) : a);
}

const long long maxx = (long long) 1e12;
const int maxn = (int) 1e6 + 5;
int n;
long long b;
long long a[maxn];
int e[maxn];

bool read() {
  if (scanf("%d%lld", &n, &b) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &e[i]);
  }
  return true;
}

pair<long long, int> tosort[maxn];
int isGood[maxn];
int k;
vector<long long> ps;
vector<vector<int>> good;

bool add(int msk, int id) {
  if (sz(good[msk]) >= k && e[good[msk].back()] <= e[id]) {
    return false;
  }
  if (sz(good[msk]) >= k) {
    good[msk].pop_back();
  }
  int pos = sz(good[msk]);
  good[msk].push_back(id);
  while (pos && e[good[msk][pos]] < e[good[msk][pos - 1]]) {
    swap(good[msk][pos], good[msk][pos - 1]);
    pos--;
  }
  return true;
}

vector<vector<long long>> dp, ndp;

void solve() {
  long long g = a[0];
  for (int i = 1; i < n; i++) {
    g = gcd(g, a[i]);
  }
  if (g == 1) {
    printf("0\n");
    return;
  }
  {
    ps.clear();
    long long x = g;
    for (long long d = 2; d * d <= x; d++) {
      if (!(x % d)) {
        ps.push_back(d);
        while(!(x % d)) {
          x /= d;
        }
      }
    }
    if (x > 1) {
      ps.push_back(x);
    }
  }
  k = sz(ps);
  for (int i = 0; i < n; i++) {
    long long x = 1;
    auto &cur = a[i];
    for (int j = 0; j < k; j++) {
      while (!(cur % ps[j])) {
        cur /= ps[j];
        x *= ps[j];
      }
    }
    cur = x;
  }
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(a[i], e[i]);
  }
  sort(tosort, tosort + n);
  for (int i = 0; i < n; i++) {
    a[i] = tosort[i].first;
    e[i] = tosort[i].second;
  }
  good.clear();
  good.resize((1 << k));
  for (int i = 0; i < n; i++) {
    isGood[i] = false;
  }
  for (int j = 0; j < n;) {
    int i = j;
    while (j < n && a[j] == a[i]) {
      j++;
    }
    vector<int> qs(k, 0);
    {
      long long x = a[i];
      for (int it = 0; it < k; it++) {
        while (!(x % ps[it])) {
          x /= ps[it];
          qs[it]++;
        }
      }
    }
    for (int msk = 0; msk < (1 << k); msk++) {
      long long y = 1;
      for (int it = 0; it < k; it++) {
        if (!(msk & (1 << it))) {
          continue;
        }
        for (int it0 = 0; it0 < qs[it]; it0++) {
          y *= ps[it];
        }
      }
      if (y > b) {
        continue;
      }
      int pos = i;
      while (pos < j) {
        if (!add(msk, pos)) {
          break;
        }
        isGood[pos] = true;
        pos++;
      }
    }
  }
  dp = vector<vector<long long>>((1 << k), vector<long long>(k + 1, infll));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    if (!isGood[i]) {
      continue;
    }
    ndp = vector<vector<long long>>((1 << k), vector<long long>(k + 1, infll));
    vector<int> qs(k, 0);
    {
      long long x = a[i];
      for (int it = 0; it < k; it++) {
        while (!(x % ps[it])) {
          x /= ps[it];
          qs[it]++;
        }
      }
    }
    vector<int> ok(1 << k);
    for (int msk = 0; msk < (1 << k); msk++) {
      long long y = 1;
      for (int it = 0; it < k; it++) {
        if (!(msk & (1 << it))) {
          continue;
        }
        for (int it0 = 0; it0 < qs[it]; it0++) {
          y *= ps[it];
        }
      }
      ok[msk] = (y <= b);
    }
    for (int msk = 0; msk < (1 << k); msk++) {
      for (int cnt = 0; cnt <= k; cnt++) {
        auto cur = dp[msk][cnt];
        if (cur >= infll) {
          continue;
        }
        {
          auto &nxt = ndp[msk][cnt];
          nxt = min(nxt, cur);
        }
        if (cnt >= k) {
          continue;
        }
        int msk1 = (((1 << k) - 1) ^ msk);
        for (int nmsk = msk1; nmsk > 0; nmsk = ((nmsk - 1) & msk1)) {
          if (!ok[nmsk]) {
            continue;
          }
          auto &nxt = ndp[msk | nmsk][cnt + 1];
          nxt = min(nxt, cur + e[i]);
        }
      }
    }
    swap(dp, ndp);
  }
  long long res = infll;
  for (int cnt = 1; cnt <= k; cnt++) {
    if (dp[(1 << k) - 1][cnt] < infll) {
      res = min(res, cnt * dp[(1 << k) - 1][cnt]);
    }
  }
  if (res >= infll) {
    res = -1;
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