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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 1005, d = 10;
int n, m;
string a;
string b[maxn];
int c[d];
char tmp[maxn];

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  a = tmp;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    b[i] = tmp;
  }
  for (int i = 0; i < d; i++) {
    scanf("%d", &c[i]);
  }
  return true;
}

int realsz[maxn];
int p[maxn][maxn];
int q[maxn];
int dp[maxn][maxn];
int vals[maxn][d + 1];
int up[maxn][d + 1];
int psum[maxn][d + 1];
int pup[maxn][d + 1];
int ssum[maxn][d + 1];
int sup[maxn][d + 1];

void solve() {
  reverse(a.begin(), a.end());
  for (int i = 0; i < sz(a); i++) {
    if (a[i] != '?') {
      a[i] -= '0';
    }
  }
  m = sz(a);
  int realsza = sz(a);
  int nonzero = realsza - 1;
  for (int i = 0; i < n; i++) {
    reverse(b[i].begin(), b[i].end());
    for (int j = 0; j < sz(b[i]); j++) {
      b[i][j] -= '0';
    }
    realsz[i] = sz(b[i]);
    m = max(m, sz(b[i]));
  }
  a.resize(m, 0);
  for (int i = 0; i < n; i++) {
    b[i].resize(m, 0);
  }
  for (int i = 0; i < n; i++) {
    p[0][i] = i;
  }
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = -1;
    }
  }
  dp[0][n] = 0;
  for (int pos = 0; pos < m; pos++) {
    {
      int cnt[d];
      for (int i = 0; i < d; i++) {
        cnt[i] = 0;
      }
      for (int i = 0; i < n; i++) {
        cnt[b[i][pos]]++;
      }
      int s[d + 1];
      s[0] = 0;
      for (int i = 0; i < d; i++) {
        s[i + 1] = s[i] + cnt[i];
      }
      for (int i = 0; i < n; i++) {
        int id = p[pos][i];
        p[pos + 1][s[b[id][pos]]++] = id;
      }
    }
    for (int i = 0; i < n; i++) {
      q[p[pos + 1][i]] = i;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= d; j++) {
        up[i][j] = false;
        if (j == 0 && pos >= realsz[i] && pos >= realsza) {
          vals[i][j] = 0;
          continue;
        }
        int x = b[i][pos] + j;
        if (x >= d) {
          up[i][j] = true;
          x -= d;
        }
        assert(x < d);
        vals[i][j] = c[x];
      }
    }
    for (int j = 0; j <= d; j++) {
      psum[0][j] = 0;
      pup[0][j] = n;
    }
    for (int i = 0; i < n; i++) {
      int id = p[pos][i];
      for (int j = 0; j <= d; j++) {
        psum[i + 1][j] = psum[i][j] + vals[id][j];
        pup[i + 1][j] = min(pup[i][j], (up[id][j] ? q[id] : n));
      }
    }
    for (int j = 0; j <= d; j++) {
      ssum[n][j] = 0;
      sup[n][j] = n;
    }
    for (int i = n - 1; i >= 0; i--) {
      int id = p[pos][i];
      for (int j = 0; j <= d; j++) {
        ssum[i][j] = ssum[i + 1][j] + vals[id][j];
        sup[i][j] = min(sup[i + 1][j], (up[id][j] ? q[id] : n));
      }
    }
    for (int i = 0; i <= n; i++) {
      if (dp[pos][i] == -1) {
        continue;
      }
      int dl = 0, dr = d;
      if (a[pos] != '?') {
        dl = a[pos];
        dr = a[pos] + 1;
      } else if (pos == nonzero) {
        dl++;
      }
      for (int d = dl; d < dr; d++) {
        int val = dp[pos][i] + psum[i][d] + ssum[i][d + 1];
        int up = min(pup[i][d], sup[i][d + 1]);
        eprintf("pos = %d, i = %d, d = %d, val = %d, up = %d\n", pos, i, d, val, up);
        dp[pos + 1][up] = max(dp[pos + 1][up], val);
      }
    }
  }
  int res = -1;
  for (int i = 0; i <= n; i++) {
    if (dp[m][i] == -1) {
      continue;
    }
    res = max(res, dp[m][i] + (n - i) * c[1]);
  }
  assert(res != -1);
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