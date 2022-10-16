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

const int maxn = (int) 1e6 + 5;
const int sigma = 26;
int n;
string s;
char tmp[maxn];

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  string a = tmp;
  scanf("%s", tmp);
  string b = tmp;
  s.clear();
  for (int i = 0; i < sz(a); i++) {
    s += a[i];
    s += b[i];
  }
  n = sz(s);
  return true;
}

int vs;
map<char, int> go[maxn];
int len[maxn];
int diff[maxn];
int link[maxn], slink[maxn];
int plen[maxn];
int dp[maxn];
int splen[maxn];
int sdp[maxn];

int newNode(int _len, int _link) {
  go[vs].clear();
  len[vs] = _len;
  link[vs] = _link;
  diff[vs] = len[vs] - len[link[vs]];
  slink[vs] = (diff[vs] == diff[link[vs]] ? slink[link[vs]] : link[vs]);
  sdp[vs] = inf;
  return vs++;
}

void solve() {
  vs = 0;
  slink[0] = 0;
  newNode(-1, 0);
  int v = newNode(0, 0);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    while (len[v] >= i || s[i] != s[i - len[v] - 1]) {
      v = link[v];
    }
    if (v == 0) {
      v = 1;
    } else {
      if (!go[v].count(s[i])) {
        int u = link[v];
        while (len[u] >= i || s[i] != s[i - len[u] - 1]) {
          u = link[u];
        }
        if (u == 0) {
          u = 1;
        } else {
          u = go[u][s[i]];
        }
        go[v][s[i]] = newNode(len[v] + 2, u);
      }
      v = go[v][s[i]];
    }
    auto &cur = dp[i + 1];
    cur = inf;
    if (!(i & 1)) {
      continue;
    }
    auto &p = plen[i + 1];
    for (int u = v; len[u] > 0; u = slink[u]) {
      sdp[u] = dp[i + 1 - (len[slink[u]] + diff[u])];
      splen[u] = len[slink[u]] + diff[u];
      if (diff[u] == diff[link[u]] && sdp[link[u]] < sdp[u]) {
        sdp[u] = sdp[link[u]];
        splen[u] = splen[link[u]] + diff[u];
      }
      if (sdp[u] + 1 < cur) {
        cur = sdp[u] + 1;
        p = splen[u];
      }
    }
    if (i && s[i] == s[i - 1] && dp[i - 1] < cur) {
      cur = dp[i - 1];
      p = 2;
    }
    //eprintf("%d: %d\n", (i + 1) / 2, cur);
  }
  if (dp[n] >= inf) {
    printf("-1\n");
    return;
  }
  printf("%d\n", dp[n]);
  for (int i = n; i > 0; i -= plen[i]) {
    if (plen[i] > 2) {
      printf("%d %d\n", (i - plen[i]) / 2 + 1, i / 2);
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