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

const int maxn = 105;
int n, k;
int a[4][maxn];

int read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
      a[i][j]--;
    }
  }
  return true;
}

pair<int, int> was[maxn];
vector<pair<int, pair<int, int>>> ans;

void solve() {
  ans.clear();
  for (int i = 0; i < n; i++) {
    if (a[1][i] != -1 && a[1][i] == a[0][i]) {
      ans.push_back(make_pair(a[1][i], make_pair(0, i)));
      a[1][i] = -1;
      a[0][i] = -1;
      k--;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[2][i] != -1 && a[2][i] == a[3][i]) {
      ans.push_back(make_pair(a[2][i], make_pair(3, i)));
      a[2][i] = -1;
      a[3][i] = -1;
      k--;
    }
  }
  if (k == 2 * n) {
    printf("-1\n");
    return;
  }
  while (k) {
    vector<pair<int, pair<int, int>>> v;
    int sh = -1;
    for (int i = 1; i < n; i++) {
      if (a[1][i] != -1) {
        if (sh == -1 && a[1][i - 1] == -1) {
          sh = sz(v);
        }
        v.push_back(make_pair(a[1][i], make_pair(1, i - 1)));
        was[a[1][i]] = make_pair(1, i);
      }
    }
    if (a[2][n - 1] != -1) {
      if (sh == -1 && a[1][n - 1] == -1) {
        sh = sz(v);
      }
      v.push_back(make_pair(a[2][n - 1], make_pair(1, n - 1)));
      was[a[2][n - 1]] = make_pair(2, n - 1);
    }
    for (int i = n - 2; i >= 0; i--) {
      if (a[2][i] != -1) {
        if (sh == -1 && a[2][i + 1] == -1) {
          sh = sz(v);
        }
        v.push_back(make_pair(a[2][i], make_pair(2, i + 1)));
        was[a[2][i]] = make_pair(2, i);
      }
    }
    if (a[1][0] != -1) {
      if (sh == -1 && a[2][0] == -1) {
        sh = sz(v);
      }
      v.push_back(make_pair(a[1][0], make_pair(2, 0)));
      was[a[1][0]] = make_pair(1, 0);
    }
    assert(sh != -1);
    rotate(v.begin(), v.begin() + sh, v.end());
    for (int i = 0; i < sz(v); i++) {
      int id = v[i].first;
      pair<int, int> s = was[id], t = v[i].second;
      assert(a[t.first][t.second] == -1);
      a[t.first][t.second] = id;
      a[s.first][s.second] = -1;
      ans.push_back(v[i]);
    }
    for (int i = 0; i < n; i++) {
      if (a[1][i] != -1 && a[1][i] == a[0][i]) {
        ans.push_back(make_pair(a[1][i], make_pair(0, i)));
        a[1][i] = -1;
        a[0][i] = -1;
        k--;
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[2][i] != -1 && a[2][i] == a[3][i]) {
        ans.push_back(make_pair(a[2][i], make_pair(3, i)));
        a[2][i] = -1;
        a[3][i] = -1;
        k--;
      }
    }
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d %d %d\n", ans[i].first + 1, ans[i].second.first + 1, ans[i].second.second + 1);
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