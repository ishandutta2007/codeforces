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

const int maxn = 505;
int n;
int a[2 * maxn][maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < 2 * n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
      --a[i][j];
    }
  }
  return true;
}

int del[2 * maxn];
int found[maxn][maxn], cnt[maxn][maxn];
vector<pair<int, int>> q;
vector<int> ans;

void delRow(int i) {
  del[i] = true;
  for (int j = 0; j < n; ++j) {
    int x = a[i][j];
    --cnt[j][x];
    if (!found[j][x] && cnt[j][x] == 1) {
      q.push_back(make_pair(j, x));
    }
  }
}

void delRows(int pos, int val) {
  for (int i = 0; i < 2 * n; ++i) {
    if (!del[i] && a[i][pos] == val) {
      delRow(i);
    }
  }
}

int used[2 * maxn];

void dfs(int v, bool take) {
  used[v] = true;
  if (take) {
    ans.push_back(v);
  }
  for (int u = 0; u < 2 * n; ++u) {
    if (del[u] || used[u]) {
      continue;
    }
    bool edge = false;
    for (int i = 0; i < n; ++i) {
      if (a[v][i] == a[u][i]) {
        edge = true;
        break;
      }
    }
    if (edge) {
      dfs(u, !take);
    }
  }
}

void solve() {
  for (int i = 0; i < 2 * n; ++i) {
    del[i] = false;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      found[i][j] = false;
      cnt[i][j] = 0;
    }
  }
  q.clear();
  for (int i = 0; i < 2 * n; ++i) {
    for (int j = 0; j < n; ++j) {
      ++cnt[j][a[i][j]];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (cnt[i][j] == 1) {
        q.push_back(make_pair(i, j));
      }
    }
  }
  ans.clear();
  for (int l = 0; l < sz(q); ++l) {
    int pos = q[l].first, val = q[l].second;
    if (found[pos][val]) {
      continue;
    }
    int i = 0;
    while (del[i] || a[i][pos] != val) {
      ++i;
    }
    delRow(i);
    ans.push_back(i);
    for (int j = 0; j < n; ++j) {
      found[j][a[i][j]] = true;
      delRows(j, a[i][j]);
    }
  }
  for (int i = 0; i < 2 * n; ++i) {
    used[i] = false;
  }
  int res = 1;
  for (int i = 0; i < 2 * n; ++i) {
    if (!del[i] && !used[i]) {
      dfs(i, true);
      res = mul(res, 2);
    }
  }
  printf("%d\n", res);
  for (int i = 0; i < sz(ans); ++i) {
    printf("%d ", ans[i] + 1);
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