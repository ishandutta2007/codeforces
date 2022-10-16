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

const int maxl = (int) 1e6;
char tmp[maxl];
long long r;
string s;

bool read() {
  if (scanf("%lld", &r) < 1) {
    return false;
  }
  scanf(" ");
  fgets(tmp, sizeof(tmp), stdin);
  s = tmp;
  return true;
}

const int maxn = (int) 2e5 + 5;
int n;
int t[maxn];
vector<int> g[maxn];
vector<int> rs;

int newRes() {
  int v = n++;
  g[v].clear();
  t[v] = 0;
  rs.push_back(v);
  return v;
}

void readSpace(int &i) {
  while (i < sz(s) && isspace(s[i])) {
    i++;
  }
}

int buildTree(int &i) {
  readSpace(i);
  if (s[i] == '*') {
    i++;
    return newRes();
  }
  assert(s[i] == '(');
  i++;
  int v = n++;
  g[v].clear();
  t[v] = -1;
  while (true) {
    int u = buildTree(i);
    g[v].push_back(u);
    readSpace(i);
    if (s[i] == ')') {
      i++;
      break;
    }
    if (s[i] == 'S') {
      t[v] = 1;
    } else if (s[i] == 'P') {
      t[v] = 2;
    } else {
      assert(false);
    }
    i++;
  }
  assert(t[v] != -1);
  return v;
}

long long dp[maxn];

void dfs(int v) {
  if (t[v] == 0) {
    dp[v] = 1;
    return;
  }
  if (t[v] == 1) {
    dp[v] = infll;
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      dfs(u);
      dp[v] = min(dp[v], dp[u]);
    }
    return;
  }
  dp[v] = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    dfs(u);
    dp[v] = min(infll, dp[v] + dp[u]);
  }
}

long long ans[maxn];

void getAns(int v, long long need) {
  if (t[v] == 0) {
    ans[v] = need;
    return;
  }
  if (t[v] == 1) {
    int best = -1;
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (best == -1 || dp[u] < dp[best]) {
        best = u;
      }
    }
    getAns(best, need);
    return;
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    getAns(u, need);
  }
}

void solve() {
  n = 0;
  rs.clear();
  int pos = 0;
  int root = buildTree(pos);
  dfs(root);
  for (int i = 0; i < n; i++) {
    ans[i] = 0;
  }
  getAns(root, dp[root] * r);
  printf("REVOLTING ");
  for (int i = 0; i < sz(rs); i++) {
    printf("%lld ", ans[rs[i]]);
  }
  printf("\n");
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}