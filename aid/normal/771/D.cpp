#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1.01e9;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

const int mod = (int) 1e9 + 7;

void add(int & x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int sum(int x, int y) {
  add(x, y);
  return x;
}

int mult(int x, int y) {
  return (ll) x * y % mod;
}

int power(int x, ll p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
    p >>= 1;
  }
  return res;
}

int inv(int x) {
  return power(x, mod - 2);
}

void precalc() {
}

const int maxn = 80;

int n;
char s[maxn];

bool read() {
  if (scanf("%d%s", &n, s) < 2) {
    return false;
  }
  return true;
}

int stupid() {
  vector<int> perm(n);
  for (int i = 0; i < n; i++) {
    perm[i] = i;
  }
  int res = inf;
  do {
    int cnt = 0;
    bool ok = true;
    static vector<char> str;
    str.resize(n);
    for (int i = 0; i < n; i++) {
      str[i] = s[perm[i]];
    }
    for (int i = 0; i + 1 < n; i++) {
      if (str[i] == 'V' && str[i + 1] == 'K') {
        ok = false;
        break;
      }
    }
    if (!ok) {
      continue;
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (perm[i] > perm[j]) {
          cnt++;
        }
      }
    }
    res = min(res, cnt);
    if (cnt == 4) {
      for (int i = 0; i < n; i++) {
        eprintf("%d\n", perm[i]);
      }
    }
  } while (next_permutation(perm.begin(), perm.end())) ;
  return res;
}


int t[maxn];
int pos[3][maxn];
int cnt[3];
int vals[3][maxn][3][maxn];
int dp[3][maxn][maxn][maxn];

void solve() {
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; i++) {
    if (s[i] == 'V') {
      t[i] = 0;
      pos[0][cnt[0]] = i;
      cnt[0]++;
    } else if (s[i] == 'K') {
      t[i] = 1;
      pos[1][cnt[1]] = i;
      cnt[1]++;
    } else {
      t[i] = 2;
      pos[2][cnt[2]] = i;
      cnt[2]++;
    }
  }
  memset(vals, 0, sizeof(vals));
  for (int t = 0; t < 3; t++) {
    for (int i = 0; i < cnt[t]; i++) {
      for (int nt = 0; nt < 3; nt++) {
        if (nt == t) {
          continue;
        }
        for (int j = 0; j <= cnt[nt]; j++) {
          int &cur = vals[t][i][nt][j];
          cur = 0;
          for (int r = 0; r < j; r++) {
            if (pos[nt][r] > pos[t][i]) {
              cur++;
            }
          }
        }
      }
    }
  }
  for (int t = 0; t < 3; t++) {
    for (int i = 0; i <= cnt[0]; i++) {
      for (int j = 0; j <= cnt[1]; j++) {
        for (int k = 0; k <= cnt[2]; k++) {
          dp[t][i][j][k] = inf;
        }
      }
    }
  }
  dp[2][0][0][0] = 0;
  for (int i = 0; i <= cnt[0]; i++) {
    for (int j = 0; j <= cnt[1]; j++) {
      for (int k = 0; k <= cnt[2]; k++) {
        int a[3] = {i, j, k};
        for (int t = 0; t < 3; t++) {
          for (int nt = 0; nt < 3; nt++) {
            if (t == 0 && nt == 1) {
              continue;
            }
            if (dp[t][i][j][k] == inf) {
              continue;
            }
            if (a[nt] == cnt[nt]) {
              continue;
            }
            int cur = vals[nt][a[nt]][0][a[0]];
            cur += vals[nt][a[nt]][1][a[1]];
            cur += vals[nt][a[nt]][2][a[2]];
            dp[nt][i + (nt == 0)][j + (nt == 1)][k + (nt == 2)] = min(dp[nt][i + (nt == 0)][j + (nt == 1)][k + (nt == 2)], dp[t][i][j][k] + cur);
          }
        }
      }
    }
  }
  int res = inf;
  for (int i = 0; i < 3; i++) {
    res = min(res, dp[i][cnt[0]][cnt[1]][cnt[2]]);
  }
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}