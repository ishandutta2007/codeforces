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

int mod[2] = {(int) 1e9 + 7, (int) 1e9 + 9};

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
      res.a[i] = (a[i] + mod[i] - h.a[i]);
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

  bool operator != (const Hash &h) const {
    for (int i = 0; i < n; i++) {
      if (a[i] != h.a[i]) {
        return true;
      }
    }
    return false;
  }
};

const int maxn = (int) 1e6 + 5;
Hash ps[maxn];

void precalc() {
  ps[0] = Hash(1);
  for (int i = 0; i < 2; i++) {
    ps[1].a[i] = rnd(mod[i]);
  }
  for (int i = 2; i < maxn; i++) {
    ps[i] = ps[i - 1] * ps[1];
  }
}

int n, m;
string s, t;
char tmp[maxn];

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  scanf("%s", tmp);
  t = tmp;
  m = sz(t);
  return true;
}

Hash hs[maxn];

void solve() {
  if (s[0] == '1') {
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        s[i] = '0';
      } else {
        s[i] = '1';
      }
    }
  }
  int cnt[2] = {0, 0};
  for (int i = 0; i < n; i++) {
    cnt[s[i] - '0']++;
  }
  hs[0] = Hash();
  for (int i = 0; i < m; i++) {
    hs[i + 1] = hs[i] * ps[1] + Hash(t[i] - 'a' + 1);
  }
  int res = 0;
  for (int a = 1; a * cnt[0] < m; a++) {
    int b = m - a * cnt[0];
    if (b % cnt[1]) {
      continue;
    }
    b = b / cnt[1];
    Hash h[2] = {Hash(), Hash()};
    h[0] = hs[a];
    bool fst = true;
    bool ok = true;
    for (int i = 0, j = 0; i < n; i++) {
      if (s[i] == '0') {
        if (hs[j + a] - hs[j] * ps[a] != h[0]) {
          ok = false;
          break;
        }
        j += a;
      } else {
        if (fst) {
          fst = false;
          h[1] = hs[j + b] - hs[j] * ps[b];
        }
        if (hs[j + b] - hs[j] * ps[b] != h[1]) {
          ok = false;
          break;
        }
        j += b;
      }
    }
    if (h[0] == h[1]) {
      ok = false;
    }
    if (ok) {
      res++;
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