#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
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
int qq;
int p25[maxn], f[maxn], inv[maxn], finv[maxn];
int ans[maxn];
char tmp[maxn];
string s;
vector< pair<int, int> > q[maxn];

int add(int a, int b) {
  int res = a + b;
  if (res >= mod) {
    res -= mod;
  }
  return res;
}

int mul(int a, int b) {
  return (long long)a * b % mod;
}

void precalc() {
  p25[0] = 1;
  for (int i = 1; i < maxn; i++) {
    p25[i] = mul(25, p25[i - 1]);
  }
  f[0] = 1;
  for (int i = 1; i < maxn; i++) {
    f[i] = mul(i, f[i - 1]);
  }
  inv[1] = 1;
  for (int i = 2; i < maxn; i++) {
    inv[i] = (mod - (long long)(mod / i) * inv[mod % i] % mod) % mod;
  }
  finv[0] = 1;
  for (int i = 1; i < maxn; i++) {
    finv[i] = mul(inv[i], finv[i - 1]);
  }
}

int read() {
  if (scanf("%d", &qq) < 1) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  int m = sz(s);
  for (int i = 0; i < maxn; i++) {
    q[i].clear();
  }
  int qqq = 0;
  for (int i = 0; i < qq; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%s", tmp);
      s = tmp;
      m = sz(s);
    }
    else {
      int n;
      scanf("%d", &n);
      q[m].push_back(make_pair(n, qqq++));
    }
  }
  qq = qqq;
  return true;
}

int c(int n, int k) {
  return mul(f[n], mul(finv[k], finv[n - k]));
}

void solve() {
  for (int m = 0; m < maxn; m++) {
    if (q[m].empty()) {
      continue;
    }
    sort(q[m].begin(), q[m].end());
    int x = 0;
    for (int i = 0, n = 0; i < sz(q[m]); i++) {
      while (n < q[m][i].first) {
        int y;
        if (n < m - 1) {
          y = 0;
        }
        else {
          y = add(mul(c(n, m - 1), p25[n - m + 1]), x);
        }
        x = add(mul(25, x), y);
        n++;
      }
      ans[q[m][i].second] = x;
    }
  }
  for (int i = 0; i < qq; i++) {
    printf("%d\n", ans[i]);
  }
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}