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

const int maxl = (int) 1e5 + 5, maxn = 260;
char tmp[maxl];
int q;
string s;
string t[3];

bool read() {
  int n;
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

const int sigma = 26;
int nxt[maxl][sigma];
int dp[maxn][maxn][maxn];
char ttt[10];

void recalc(int id, int pos) {
  int ls[3] = {0, 0, 0};
  int rs[3] = {sz(t[0]) + 1, sz(t[1]) + 1, sz(t[2]) + 1};
  ls[id] = pos;
  rs[id] = pos + 1;
  for (int i = ls[0]; i < rs[0]; i++) {
    for (int j = ls[1]; j < rs[1]; j++) {
      for (int k = ls[2]; k < rs[2]; k++) {
        auto &cur = dp[i][j][k];
        cur = inf;
        if (i) {
          auto val = dp[i - 1][j][k];
          if (val < inf) {
            cur = min(cur, nxt[val][t[0][i - 1] - 'a'] + 1);
          }
        }
        if (j) {
          auto val = dp[i][j - 1][k];
          if (val < inf) {
            cur = min(cur, nxt[val][t[1][j - 1] - 'a'] + 1);
          }
        }
        if (k) {
          auto val = dp[i][j][k - 1];
          if (val < inf) {
            cur = min(cur, nxt[val][t[2][k - 1] - 'a'] + 1);
          }
        }
      }
    }
  }
}

void solve() {
  for (int i = 0; i < sigma; i++) {
    nxt[sz(s)][i] = inf;
  }
  for (int i = sz(s) - 1; i >= 0; i--) {
    for (int j = 0; j < sigma; j++) {
      nxt[i][j] = nxt[i + 1][j];
    }
    nxt[i][s[i] - 'a'] = i;
  }
  dp[0][0][0] = 0;
  for (int i = 0; i < 3; i++) {
    t[i] = "";
  }
  for (int qq = 0; qq < q; qq++) {
    scanf("%s", ttt);
    if (ttt[0] == '+') {
      int id;
      scanf("%d%s", &id, ttt);
      id--;
      char c = ttt[0];
      t[id] += c;
      recalc(id, sz(t[id]));
    } else {
      int id;
      scanf("%d", &id);
      id--;
      int k = sz(t[id]) - 1;
      t[id].resize(k);
    }
    printf(dp[sz(t[0])][sz(t[1])][sz(t[2])] >= inf ? "NO\n" : "YES\n");
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