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

vector<int> msks;
vector<int> need;

void precalc() {
  {
    int all = ((1 << 4) - 1);
    for (int i = 0; i < 4; ++i) {
      msks.push_back(all ^ (1 << i));
    }
  }
  need.resize(1 << 4, -1);
  for (int msk = 0; msk < (1 << 4); ++msk) {
    int cur = 0;
    for (int i = 0; i < 4; ++i){
      if (msk & (1 << i)) {
        cur ^= msks[i];
      }
    }
    need[cur] = msk;
  }
}

const int maxn = 105;
int n, m;
char c[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", c[i]);
  }
  return true;
}

vector<vector<int>> ans;

void addOp(const vector<int> &op) {
  ans.push_back(op);
  for (int i = 0; i < sz(op); i += 2) {
    int x = op[i], y = op[i + 1];
    c[x][y] ^= 1;
  }
}

void solve() {
  ans.clear();
  if (n & 1) {
    for (int j = 0; j < m; ++j) {
      if (c[n - 1][j] == '1') {
        if (j + 1 < m) {
          addOp({n - 1, j, n - 2, j, n - 2, j + 1});
        } else {
          addOp({n - 1, j, n - 2, j, n - 2, j - 1});
        }
      }
    }
    --n;
  }
  if (m & 1) {
    for (int i = 0; i < n; ++i) {
      if (c[i][m - 1] == '1') {
        if (i + 1 < n) {
          addOp({i, m - 1, i, m - 2, i + 1, m - 2});
        } else {
          addOp({i, m - 1, i, m - 2, i - 1, m - 2});
        }
      }
    }
    --m;
  }
  for (int i = 0; i < n; i += 2) {
    for (int j = 0; j < m; j += 2) {
      int msk = 0;
      int it = 0;
      for (int x = 0; x < 2; ++x) {
        for (int y = 0; y < 2; ++y) {
          if (c[i + x][j + y] == '1') {
            msk ^= (1 << it);
          }
          ++it;
        }
      }
      msk = need[msk];
      for (int b = 0; b < 4; ++b) {
        if (msk & (1 << b)) {
          int op = msks[b];
          vector<int> v;
          int it = 0;
          for (int x = 0; x < 2; ++x) {
            for (int y = 0; y < 2; ++y) {
              if (op & (1 << it)) {
                v.push_back(i + x);
                v.push_back(j + y);
              }
              ++it;
            }
          }
          addOp(v);
        }
      }
    }
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); ++i) {
    for (int j = 0; j < sz(ans[i]); ++j) {
      printf("%d ", ans[i][j] + 1);
    }
    printf("\n");
  }
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