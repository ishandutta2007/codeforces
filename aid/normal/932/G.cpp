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

const int maxn = (int) 1e6 + 5;
int n;
string s;
char tmp[maxn];

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

int vs;
map<char, int> go[maxn];
int len[maxn];
int diff[maxn];
int plen[maxn];
int link[maxn], slink[maxn];
int dp[maxn];
int sdp[maxn];

int newNode(int _len, int _link) {
  go[vs].clear();
  len[vs] = _len;
  link[vs] = _link;
  diff[vs] = len[vs] - len[link[vs]];
  slink[vs] = (diff[vs] == diff[link[vs]] ? slink[link[vs]] : link[vs]);
  sdp[vs] = 0;
  return vs++;
}

void solve() {
  {
    string a = s.substr(0, n / 2), b = s.substr(n / 2, n / 2);
    reverse(b.begin(), b.end());
    s.clear();
    for (int i = 0; i < n / 2; i++) {
      s += a[i];
      s += b[i];
    }
  }
  vs = 0;
  slink[0] = 0;
  newNode(-1, 0);
  int v = newNode(0, 0);
  for (char c = 'a'; c <= 'z'; c++) {
    go[0][c] = 1;
  }
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    while (len[v] >= i || s[i] != s[i - len[v] - 1]) {
      v = link[v];
    }
    if (!go[v].count(s[i])) {
      int u = link[v];
      while (len[u] >= i || s[i] != s[i - len[u] - 1]) {
        u = link[u];
      }
      u = go[u][s[i]];
      go[v][s[i]] = newNode(len[v] + 2, u);
    }
    v = go[v][s[i]];
    auto &cur = dp[i + 1];
    cur = 0;
    if (!(i & 1)) {
      continue;
    }
    for (int u = v; len[u] > 0; u = slink[u]) {
      sdp[u] = dp[i + 1 - (len[slink[u]] + diff[u])];
      if (diff[u] == diff[link[u]]) {
        add(sdp[u], sdp[link[u]]);
      }
      add(cur, sdp[u]);
    }
  }
  printf("%d\n", dp[n]);
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