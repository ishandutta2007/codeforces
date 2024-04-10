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

void add(long long &a, long long b) {
  a += b;
  if (a > infll) {
    a = infll;
  }
}

const int maxn = 1005;
char tmp[maxn];
int n, m;
long long k;
string s;

bool read() {
  if (scanf("%d%d%lld", &n, &m, &k) < 3) {
    return false;
  }
  k--;
  scanf("%s", tmp);
  s = tmp;
  return true;
}

const int sigma = 26;
const int maxv = maxn * maxn;
int go[maxv][sigma];
int p[maxv];
char pc[maxv];
int vs;

int newNode() {
  for (int i = 0; i < sigma; i++) {
    go[vs][i] = -1;
  }
  p[vs] = -1;
  return vs++;
}

string getStr(int v) {
  if (v == 0) {
    return "";
  }
  return getStr(p[v]) + pc[v];
}

vector<int> vers;

void getVers(int v) {
  vers.push_back(v);
  for (int c = 0; c < sigma; c++) {
    int u = go[v][c];
    if (u == -1) {
      continue;
    }
    getVers(u);
  }
}

int ps[maxn];
string t;

long long dp[maxn][maxn], toadd[maxn][maxn];

long long getCnt() {
  for (int i = 0; i < n; i++) {
    auto &pos = ps[i];
    pos = i;
    while (pos < n && pos - i < sz(t) && s[pos] == t[pos - i]) {
      pos++;
    }
    if (pos - i >= sz(t)) {
      continue;
    }
    if (pos >= n) {
      pos = -1;
      continue;
    }
    if (s[pos] < t[pos - i]) {
      pos = -1;
      continue;
    }
    pos++;
  }
  ps[n] = -1;
  memset(dp, 0, sizeof(dp));
  memset(toadd, 0, sizeof(toadd));
  dp[0][0] = 1;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (j) {
        add(toadd[i][j], toadd[i][j - 1]);
      }
      auto &cur = dp[i][j];
      add(cur, toadd[i][j]);
      if (!cur || ps[j] == -1) {
        continue;
      }
      add(toadd[i + 1][ps[j]], cur);
    }
  }
  return dp[m][n];
}

void solve() {
  vs = 0;
  newNode();
  for (int i = 0; i < n; i++) {
    int v = 0;
    for (int j = i; j < n; j++) {
      if (go[v][s[j] - 'a'] == -1) {
        go[v][s[j] - 'a'] = newNode();
        p[go[v][s[j] - 'a']] = v;
        pc[go[v][s[j] - 'a']] = s[j];
      }
      v = go[v][s[j] - 'a'];
    }
  }
  vers.clear();
  getVers(0);
  int l = 0, r = sz(vers);
  while (l < r - 1) {
    int m = (l + r) / 2;
    t = getStr(vers[m]);
    if (getCnt() > k) {
      l = m;
    } else {
      r = m;
    }
  }
  t = getStr(vers[l]);
  printf("%s\n", t.c_str());
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