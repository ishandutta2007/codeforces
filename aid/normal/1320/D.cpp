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

const int maxn = (int) 2e5 + 5;
Hash ps[maxn];

void precalc() {
  ps[0] = Hash(1);
  ps[1].a[0] = rnd(mod[0]);
  ps[1].a[1] = rnd(mod[1]);
  for (int i = 2; i < maxn; i++) {
    ps[i] = ps[i - 1] * ps[1];
  }
}

struct T {
  Hash h;
  int len;

  T(const Hash &hh, int l): h(hh), len(l) {}

  T operator + (const T &t) const {
    return T(h * ps[t.len] + t.h, len + t.len);
  }

  T operator - (const T &t) const {
    return T(h - t.h * ps[len - t.len], len - t.len);
  }

  bool operator == (const T &t) const {
    return h == t.h && len == t.len;
  }
};

char tmp[maxn];
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", tmp);
  for (int i = 0; i < n; i++) {
    a[i] = tmp[i] - '0';
  }
  return true;
}

int nxt[2][maxn], prv[2][maxn];
int isp[maxn];
int pid[maxn];
int nxtp[maxn], prvp[maxn];
int s[maxn];
vector<int> p;
vector<T> ts;

T getHash(int l, int r) {
  return ts[r + 1] - ts[l + 1];
}

T get(int l, int r) {
  T tl(Hash(), 0), tr(Hash(), 0);
  {
    int nl = nxt[0][l];
    if (nl >= r) {
      if ((r - l) & 1) {
        return T(Hash(1), 1) + T(Hash(1), 1);
      } else {
        return T(Hash(1), 1);
      }
    }
    if ((nl - l) & 1) {
      tl = tl + T(Hash(1), 1);
    }
    l = nl;
  }
  {
    int nr = prv[0][r];
    assert(nr > l);
    if ((r - nr) & 1) {
      tr = T(Hash(1), 1) + tr;
    }
    r = nr;
  }
  {
    int nl = nxtp[l];
    if (nl >= r) {
      int cnt = s[r] - s[l];
      T res = tl + T(Hash(cnt + 1), 1) + tr;
      return res;
    }
    int cnt = s[nl] - s[l];
    tl = tl + T(Hash(cnt + 1), 1);
    l = nl;
  }
  {
    int nr = prvp[r];
    assert(nr > l);
    int cnt = s[r] - s[nr];
    tr = T(Hash(cnt + 1), 1) + tr;
    r = nr;
  }
  T res = tl + getHash(pid[l], pid[r - 1]) + tr;
  return res;
}

void solve() {
  for (int t = 0; t < 2; t++) {
    nxt[t][n] = n;
    for (int i = n - 1; i >= 0; i--) {
      nxt[t][i] = (a[i] == t ? i : nxt[t][i + 1]);
    }
    prv[t][0] = 0;
    for (int i = 0; i < n; i++) {
      prv[t][i + 1] = (a[i] == t ? i + 1 : prv[t][i]);
    }
  }
  s[0] = 0;
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + (a[i] == 0);
  }
  p.clear();
  for (int j = 0; j < n;) {
    if (a[j] == 0) {
      j++;
      continue;
    }
    int i = j;
    while (j < n && a[j] == 1) {
      j++;
    }
    if ((j - i) & 1) {
      p.push_back(i);
    }
  }
  ts.clear();
  ts.push_back(T(Hash(), 0));
  for (int i = 0; i < sz(p); i++) {
    int cnt = s[p[i]];
    if (i) {
      cnt -= s[p[i - 1]];
    }
    T cur = ts.back() + T(Hash(cnt + 1), 1);
    ts.push_back(cur);
  }
  for (int i = 0; i < n; i++) {
    isp[i] = false;
  }
  for (int i = 0; i < sz(p); i++) {
    isp[p[i]] = true;
    pid[p[i]] = i;
  }
  nxtp[n] = n;
  for (int i = n - 1; i >= 0; i--) {
    nxtp[i] = (isp[i] ? i : nxtp[i + 1]);
  }
  prvp[0] = 0;
  for (int i = 0; i < n; i++) {
    prvp[i + 1] = (isp[i] ? i + 1 : prvp[i]);
  }
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; qq++) {
    int x, y, len;
    scanf("%d%d%d", &x, &y, &len);
    x--;
    y--;
    printf(get(x, x + len) == get(y, y + len) ? "YES\n" : "NO\n");
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