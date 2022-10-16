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

const int maxx = (int) 1.5e7 + 5;
int lDiv[maxx];
int ids[maxx];
vector<int> pr;

void precalc() {
  memset(ids, -1, sizeof(ids));
  for (int i = 2; i < maxx; i++) {
    if (!lDiv[i]) {
      lDiv[i] = i;
      ids[i] = sz(pr);
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

int gcd(int a, int b) {
  return (b ? gcd(b, a % b) : a);
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

vector<int> cnt;

void solve() {
  int g = a[0];
  for (int i = 1; i < n; i++) {
    g = gcd(g, a[i]);
  }
  for (int i = 0; i < n; i++) {
    a[i] /= g;
  }
  cnt.clear();
  cnt.resize(sz(pr));
  for (int i = 0; i < n; i++) {
    int x = a[i];
    while (x > 1) {
      int p = lDiv[x];
      while (!(x % p)) {
        x /= p;
      }
      cnt[ids[p]]++;
    }
  }
  int res = n;
  for (int i = 0; i < sz(pr); i++) {
    res = min(res, n - cnt[i]);
  }
  if (res >= n) {
    res = -1;
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