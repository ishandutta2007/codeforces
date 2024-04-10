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

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxx = (int) 2e6 + 5;
int lDiv[maxx];
vector<int> pr;

void precalc() {
  for (int i = 2; i < maxx; i++) {
    if (!lDiv[i]) {
      lDiv[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < sz(pr) && pr[j] <= lDiv[i]; j++) {
      int p = i * pr[j];
      if (p >= maxx) {
        break;
      }
      lDiv[p] = pr[j];
    }
  }
}

const int maxn = (int) 2e5 + 5;
int n;
int ps[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &ps[i]);
  }
  return true;
}

int p1[maxn];
int cnt[maxx];
int s[maxx];

void solve() {
  memset(cnt, 0, sizeof(cnt));
  memset(s, 0, sizeof(s));
  sort(ps, ps + n, greater<int>());
  for (int i = 0; i < n; i++) {
    if (!cnt[ps[i]]) {
      p1[i] = false;
      cnt[ps[i]] = 1;
      s[ps[i]] = 1;
      continue;
    }
    p1[i] = true;
    int x = ps[i] - 1;
    while (x > 1) {
      int p = lDiv[x];
      int k = 0;
      while (!(x % p)) {
        x /= p;
        k++;
      }
      if (cnt[p] < k) {
        cnt[p] = k;
        s[p] = 1;
      } else if (cnt[p] == k) {
        s[p]++;
      }
    }
  }
  bool one = false;
  for (int i = 0; i < n; i++) {
    if (!p1[i]) {
      continue;
    }
    bool found = false;
    int x = ps[i] - 1;
    while (x > 1) {
      int p = lDiv[x];
      int k = 0;
      while (!(x % p)) {
        x /= p;
        k++;
      }
      if (cnt[p] == k && s[p] == 1) {
        found = true;
      }
    }
    if (!found) {
      one = true;
    }
  }
  int res = 1;
  for (int i = 2; i < maxx; i++) {
    for (int j = 0; j < cnt[i]; j++) {
      res = mul(res, i);
    }
  }
  if (one) {
    add(res, 1);
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