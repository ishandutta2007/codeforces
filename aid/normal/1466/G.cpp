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

const int maxn = (int) 1e6 + 5;
int p2[maxn];

void precalc() {
  p2[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    p2[i] = mul(p2[i - 1], 2);
  }
}

char tmp[maxn];
int n, q;
string s0, s, t;

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  scanf("%s", tmp);
  s0 = tmp;
  scanf("%s", tmp);
  t = tmp;
  return true;
}

const int sigma = 26;
int cnt[maxn][sigma];

string w;
int pr[maxn];
int go[maxn][sigma];

int solve1() {
  {
    pr[0] = -1;
    for (int c = 0; c < sigma; ++c) {
      go[0][c] = 0;
    }
    for (int i = 0; i < sz(w); ++i) {
      auto &x = pr[i + 1];
      for (x = pr[i]; x >= 0 && w[i] != w[x]; x = pr[x]) ;
      ++x;
      go[i][w[i] - 'a'] = i + 1;
      for (int c = 0; c < sigma; ++c) {
        go[i + 1][c] = go[x][c];
      }
    }
  }
  int k = 0;
  s = s0;
  while (k < n && sz(s) < sz(w)) {
    s = s + string(1, t[k]) + s;
    ++k;
  }
  int res = 0;
  int v = 0;
  for (int i = 0; i < sz(s); ++i) {
    v = go[v][s[i] - 'a'];
    if (v == sz(w)) {
      ++res;
    }
  }
  res = mul(res, p2[n - k]);
  for (int c = 0; c < sigma; ++c) {
    int tomul = cnt[n][c];
    add(tomul, mod - mul(p2[n - k], cnt[k][c]));
    if (!tomul) {
      continue;
    }
    int cur = 0;
    int u = v;
    {
      u = go[u][c];
      if (u == sz(w)) {
        ++cur;
      }
    }
    for (int i = 0; i < sz(w) - 1; ++i) {
      u = go[u][s[i] - 'a'];
      if (u == sz(w)) {
        ++cur;
      }
    }
    add(res, mul(tomul, cur));
  }
  return res;
}

void solve() {
  {
    for (int c = 0; c < sigma; ++c) {
      cnt[0][c] = 0;
    }
    for (int i = 0; i < sz(s0); ++i) {
      ++cnt[0][s0[i] - 'a'];
    }
    for (int i = 0; i < n; ++i) {
      for (int c = 0; c < sigma; ++c) {
        cnt[i + 1][c] = mul(cnt[i][c], 2);
      }
      add(cnt[i + 1][t[i] - 'a'], 1);
    }
  }
  for (int qq = 0; qq < q; ++qq) {
    scanf("%d", &n);
    scanf("%s", tmp);
    w = tmp;
    printf("%d\n", solve1());
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