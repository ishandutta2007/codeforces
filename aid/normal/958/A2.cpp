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

const int mod[2] = {(int) 1e9 + 7, (int) 1e9 + 9};

struct Hash {
  static const int n = 2;
  int a[n];

  Hash() {
    for (int i = 0; i < n; i++) {
      a[i] = 0;
    }
  }

  Hash(int x) {
    for (int i = 0; i < n; i++) {
      a[i] = x % mod[i];
    }
  }

  Hash operator + (const Hash &h) const {
    Hash res;
    for (int i = 0; i < n; i++) {
      res.a[i] = a[i] + h.a[i];
      if (res.a[i] >= mod[i]) {
        res.a[i] -= mod[i];
      }
    }
    return res;
  }

  Hash operator - (const Hash &h) const {
    Hash res;
    for (int i = 0; i < n; i++) {
      res.a[i] = a[i] + mod[i] - h.a[i];
      if (res.a[i] >= mod[i]) {
        res.a[i] -= mod[i];
      }
    }
    return res;
  }

  Hash operator * (const Hash &h) const {
    Hash res;
    for (int i = 0; i < n; i++) {
      res.a[i] = (long long) a[i] * h.a[i] % mod[i];
    }
    return res;
  }

  bool operator == (const Hash &h) const {
    for (int i = 0; i < n; i++) {
      if (a[i] != h.a[i]) {
        return false;
      }
    }
    return true;
  }
};

const int maxn = 4005;
Hash p[maxn];

void precalc() {
  p[0] = Hash(1);
  p[1].a[0] = rnd(500) + 500;
  p[1].a[1] = rnd(500) + 500;
  for (int i = 2; i < maxn; i++) {
    p[i] = p[i - 1] * p[1];
  }
}

int n, m;
char a[maxn][maxn], b[maxn][maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", a[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%s", b[i]);
  }
  return true;
}

Hash ha[maxn], hb[maxn];
Hash s[maxn];
int z[maxn];

bool check(int row) {
  for (int i = 0; i < m; i++) {
    s[i] = ha[i];
  }
  for (int i = 0; i < n; i++) {
    s[m + i] = hb[i];
  }
  for (int i = 0; i < n + m; i++) {
    z[i] = 0;
  }
  for (int i = 1, l = 0, r = -1; i < n + m; i++) {
    if (i + z[i - l] < r) {
      z[i] = z[i - l];
    } else {
      l = i;
      r = max(r, i);
      while (r < n + m && s[r - l] == s[r]) {
        r++;
      }
      z[i] = r - l;
    }
  }
  for (int i = 0; i < n; i++) {
    if (z[m + i] >= m) {
      printf("%d %d\n", row + 1, i + 1);
      return true;
    }
  }
  return false;
}

void solve() {
  for (int i = 0; i < n; i++) {
    auto &cur = hb[i];
    cur = Hash();
    for (int j = 0; j < m; j++) {
      cur = cur * p[1] + Hash(b[j][i]);
    }
  }
  for (int i = 0; i < m; i++) {
    auto &cur = ha[i];
    cur = Hash();
    for (int j = 0; j < m; j++) {
      cur = cur * p[1] + Hash(a[j][i]);
    }
  }
  if (check(0)) {
    return;
  }
  for (int i = 0; i + m < n; i++) {
    for (int j = 0; j < m; j++) {
      ha[j] = ha[j] - Hash(a[i][j]) * p[m - 1];
    }
    for (int j = 0; j < m; j++) {
      ha[j] = ha[j] * p[1] + Hash(a[i + m][j]);
    }
    if (check(i + 1)) {
      return;
    }
  }
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