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

const int maxn = (int) 2e5 + 5;
int n, m, q;
int p[maxn];
int a[maxn];
int ql[maxn], qr[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &m, &q) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &ql[i], &qr[i]);
    ql[i]--;
  }
  return true;
}

const int logn = 20;
int pp[maxn];
int lst[maxn];
int par[maxn][logn];
int rs[maxn];

int goUp(int v, int k) {
  for (int i = 0; i < logn; i++) {
    if (k & (1 << i)) {
      v = par[v][i];
    }
  }
  return v;
}

vector<int> qs[maxn];
string ans;

void solve() {
  for (int i = 0; i < n; i++) {
    pp[p[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    lst[i] = m;
  }
  for (int i = 0; i < logn; i++) {
    par[m][i] = m;
  }
  for (int i = m - 1; i >= 0; i--) {
    int x = a[i];
    lst[x] = i;
    int y;
    {
      int pos = pp[x];
      pos = (pos + 1) % n;
      y = p[pos];
    }
    par[i][0] = lst[y];
    for (int j = 1; j < logn; j++) {
      par[i][j] = par[par[i][j - 1]][j - 1];
    }
    rs[i] = goUp(i, n - 1);
  }
  for (int i = 0; i < m; i++) {
    qs[i].clear();
  }
  for (int i = 0; i < q; i++) {
    qs[ql[i]].push_back(i);
  }
  ans = string(q, '0');
  int r = m;
  for (int i = m - 1; i >= 0; i--) {
    r = min(r, rs[i]);
    for (int j = 0; j < sz(qs[i]); j++) {
      int id = qs[i][j];
      if (r < qr[id]) {
        ans[id] = '1';
      }
    }
  }
  printf("%s\n", ans.c_str());
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