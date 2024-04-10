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

const int maxn = (int) 1e5 + 5;
int lDiv[maxn];
vector<int> pr;
int mu[maxn];

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
  mu[1] = 1;
  for (int i = 2; i < maxn; i++) {
    int pi = i / lDiv[i];
    if (lDiv[pi] == lDiv[i]) {
      mu[i] = 0;
      continue;
    }
    mu[i] = -mu[pi];
  }
}

pair<int, int> gcd(int a, int b) {
  if (!b) {
    return make_pair(1, 0);
  }
  pair<int, int> p = gcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x) {
  int res = gcd(x, mod).first;
  return (res % mod + mod) % mod;
}

int n, k;

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  return true;
}

int pk[maxn];
int cnt[2 * maxn];

void solve() {
  pk[0] = 1;
  for (int i = 1; i < maxn; i++) {
    pk[i] = mul(pk[i - 1], k);
  }
  int res = 0;
  for (int i = 1; i < n; i++) {
    add(res, pk[n - i]);
  }
  for (int d = 1; d < n; d++) {
    for (int i = 1; i * d < 2 * n; i++) {
      cnt[i] = (i - 1) / 2;
      if (i * d >= n) {
        int j = i - (n + d - 1) / d;
        cnt[i] -= j;
      }
    }
    for (int r = 2; r * d < n; r++) {
      if (!mu[r]) {
        continue;
      }
      int dd = r * d;
      for (int i = 1; i * dd < 2 * n; i++) {
        int cur = (i - 1) / 2;
        if (i * dd >= n) {
          int j = i - (n + dd - 1) / dd;
          cur -= j;
        }
        cnt[i * r] += mu[r] * cur;
      }
    }
    for (int i = 2; i * d < 2 * n; i++) {
      int cur;
      if (i * d - d <= n) {
        cur = pk[d];
      } else {
        cur = pk[i * d - n];
      }
      cur = mul(cur, mul(2, cnt[i]));
      add(res, cur);
    }
  }
  int rk = inv(k);
  for (int i = 0; i < n; i++) {
    res = mul(res, rk);
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