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

int n, m, k;

int read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  return true;
}

void printAns(vector<string> ans, bool rev) {
  if (rev) {
    vector<string> ans0(m, string(n, '.'));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans0[j][i] = ans[i][j];
      }
    }
    ans = ans0;
    swap(n, m);
  }
  for (int i = 0; i < n; i++) {
    printf("%s\n", ans[i].c_str());
  }
}

const int maxn = 10;
const int gox[] = {1, 0, -1, 0}, goy[] = {0, 1, 0, -1};
int used[maxn][maxn];
vector<string> c;

void dfs(int x, int y) {
  used[x][y] = true;
  for (int dir = 0; dir < 4; dir++) {
    int nx = x + gox[dir], ny = y + goy[dir];
    if (0 <= nx && nx < n && 0 <= ny && ny < m && c[nx][ny] == '*' && !used[nx][ny]) {
      dfs(nx, ny);
    }
  }
}

void solve() {
  int s = 4 * (n - 1) * (m - 1);
  if (k > s) {
    printf("-1\n");
    return;
  }
  if (k == s - 1 || k == s - 2 || k == s - 5) {
    printf("-1\n");
    return;
  }
  if (n < 5 && m < 5) {
    for (int msk = 0; msk < (1 << (n * m)); msk++) {
      c = vector<string>(n, string(m, '.'));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (msk & (1 << (i * m + j))) {
            c[i][j] = '*';
          }
        }
      }
      int cur = 0;
      for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j + 1 < m; j++) {
          int x = (c[i][j] == '*') + (c[i][j + 1] == '*') + (c[i + 1][j] == '*') + (c[i + 1][j + 1] == '*');
          if (x == 4) {
            cur += 4;
          } else if (x == 3) {
            cur++;
          }
        }
      }
      if (cur != k) {
        continue;
      }
      memset(used, 0, sizeof(used));
      int cnt = 0;
      for (int i = 0; i < n && cnt <= 1; i++) {
        for (int j = 0; j < m && cnt <= 1; j++) {
          if (c[i][j] == '*' && !used[i][j]) {
            dfs(i, j);
            cnt++;
          }
        }
      }
      if (cnt != 1) {
        continue;
      }
      printAns(c, false);
      return;
    }
    printf("-1\n");
    return;
  }
  bool rev = false;
  if (m < 5) {
    swap(n, m);
    rev = true;
  }
  if (k == s - 4) {
    if (n > 2) {
      printf("-1\n");
      return;
    }
    string row = string(m - 1, '*') + ".";
    vector<string> ans = {row, row};
    printAns(ans, rev);
    return;
  }
  if (k == s - 8) {
    if (n > 3) {
      printf("-1\n");
      return;
    }
    if (n == 3) {
      string row = string(m - 1, '*') + ".";
      vector<string> ans = {row, row, row};
      printAns(ans, rev);
      return;
    }
    string row = string(m - 2, '*') + "..";
    vector<string> ans = {row, row};
    printAns(ans, rev);
    return;
  }
  vector<string> ans(n, string(m, '.'));
  int i = 0;
  while (4 * i * (m - 1) <= k) {
    for (int j = 0; j < m; j++) {
      ans[i][j] = '*';
    }
    i++;
  }
  if (4 * (i - 1) * (m - 1) == k) {
    printAns(ans, rev);
    return;
  }
  int j = 0;
  while (4 * (i - 1) * (m - 1) + (j ? 1 + 4 * (j - 1) : 0) + (m - j - 1) < k) {
    ans[i][j] = '*';
    j++;
  }
  int r = k - (4 * (i - 1) * (m - 1) + (j ? 1 + 4 * (j - 1) : 0));
  if (r >= 0) {
    for (int j = 0; j < r; j += 2) {
      ans[i][m - r + j] = '*';
    }
    printAns(ans, rev);
    return;
  }
  j--;
  ans[i][j] = '.';
  r = k - (4 * (i - 1) * (m - 1) + (j ? 1 + 4 * (j - 1) : 0));
  int rup = r - (m - j - 1);
  assert(rup <= 2);
  if (rup == 1) {
    assert(j >= 2);
    ans[i + 1][0] = '*';
  } else {
    assert(j >= 3);
    ans[i + 1][1] = '*';
  }
  r -= rup;
  for (int j = 0; j < r; j += 2) {
    ans[i][m - r + j] = '*';
  }
  printAns(ans, rev);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  bool fst = true;
  while (read()) {
    if (fst) {
      fst = false;
    } else {
      printf("\n");
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}