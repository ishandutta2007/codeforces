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

const int mod = 998244353;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = 2005;
int n;
string s;
char tmp[maxn];

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

vector<pair<int, int>> g[maxn];
int c[maxn];

void addEdge(int v, int u, int t) {
  g[v].push_back(make_pair(u, t));
  g[u].push_back(make_pair(v, t));
}

bool dfs(int v) {
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, t = g[v][i].second;
    if (c[u] != -1) {
      if (c[u] != (c[v] ^ t)) {
        return false;
      }
      continue;
    }
    c[u] = (c[v] ^ t);
    if (!dfs(u)) {
      return false;
    }
  }
  return true;
}

void solve() {
  if (s[n - 1] == '1') {
    printf("0\n");
    return;
  }
  s[n - 1] = '0';
  reverse(s.begin(), s.end());
  int res = 0;
  for (int k = 1; k < n; k++) {
    int vs = n + k + 1;
    for (int i = 0; i < vs; i++) {
      g[i].clear();
      c[i] = -1;
    }
    for (int i = 0; i < n - i - 1; i++) {
      addEdge(i, n - i - 1, 0);
    }
    for (int i = 0; i < k - i - 1; i++) {
      addEdge(n + i, n + k - i - 1, 0);
    }
    for (int i = 0; i < k; i++) {
      if (s[i] == '?') {
        continue;
      }
      addEdge(i, n + i, s[i] - '0');
    }
    for (int i = k; i < n; i++) {
      if (s[i] == '?') {
        continue;
      }
      addEdge(i, n + k, s[i] - '0');
    }
    int cnt = 0;
    bool ok = true;
    for (int i = 0; i < vs; i++) {
      if (c[i] == -1) {
        c[i] = 0;
        if (!dfs(i)) {
          ok = false;
          break;
        }
        cnt++;
      }
    }
    if (!ok) {
      continue;
    }
    cnt--;
    int cur = 1;
    for (int i = 0; i < cnt; i++) {
      cur = mul(cur, 2);
    }
    add(res, cur);
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