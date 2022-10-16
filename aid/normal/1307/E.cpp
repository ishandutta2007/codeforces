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

const int maxn = 5005;
int n, m;
int s[maxn];
vector<int> h[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &s[i]);
    s[i]--;
  }
  for (int i = 0; i < n; i++) {
    h[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int f, hh;
    scanf("%d%d", &f, &hh);
    f--;
    h[f].push_back(hh);
  }
  return true;
}

int c[maxn][maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    c[0][i] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c[i + 1][j] = c[i][j];
    }
    c[i + 1][s[i]]++;
  }
  int res = -1, cnt = 0;
  for (int p = 0; p <= n; p++) {
    int cur = 0, curcnt = 1;
    bool bad = false;
    for (int i = 0; i < n; i++) {
      if (p < n && s[p] == i) {
        int l = c[p][i], r = c[n][i] - l;
        bool found = false;
        int lc = 0;
        for (int j = 0; j < sz(h[i]); j++) {
          if (h[i][j] == r) {
            found = true;
            continue;
          }
          if (h[i][j] <= l) {
            lc++;
          }
        }
        if (!found) {
          bad = true;
          break;
        }
        if (lc) {
          cur += 2;
          curcnt = mul(curcnt, lc);
        } else {
          cur++;
        }
        continue;
      }
      int l = c[p][i], r = c[n][i] - l;
      if (l > r) {
        swap(l, r);
      }
      int lc = 0, rc = 0;
      for (int j = 0; j < sz(h[i]); j++) {
        if (h[i][j] <= l) {
          lc++;
        }
        if (h[i][j] <= r) {
          rc++;
        }
      }
      if (lc >= 1 && rc >= 2) {
        cur += 2;
        curcnt = mul(curcnt, lc);
        curcnt = mul(curcnt, rc - 1);
      } else if (rc >= 1) {
        cur++;
        curcnt = mul(curcnt, lc + rc);
      }
    }
    if (bad) {
      continue;
    }
    if (cur > res) {
      res = cur;
      cnt = 0;
    }
    if (cur == res) {
      add(cnt, curcnt);
    }
  }
  printf("%d %d\n", res, cnt);
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