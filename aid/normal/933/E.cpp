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

const int maxn = (int) 3e5 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

const int L = 10;
long long s[maxn], ss[maxn];
long long dp[maxn][2];
pair<int, int> p[maxn][2];

long long getCost(int l, int r, int tl, int tr) {
  assert(l < r);
  if (r - l == 1) {
    if (!tl || !tr) {
      if (a[l]) {
        return infll;
      }
    }
    return 0;
  }
  if (!tl && a[l] > a[l + 1]) {
    return infll;
  }
  if (!tr && a[r - 1] > a[r - 2]) {
    return infll;
  }
  if (r - l == 2) {
    return min(a[l], a[r - 1]);
  }
  long long res = 0;
  long long lx = 0, rx = 0;
  if (!tl) {
    res += a[l];
    lx = a[l];
    l++;
  }
  if (!tr) {
    res += a[r - 1];
    rx = a[r - 1];
    r--;
  }
  if (r - l == 1) {
    if (lx + rx > a[l]) {
      return infll;
    }
    return res;
  }
  long long sum = s[r - 1] - s[l + 1];
  sum += (a[l] - lx) * ((l & 1) ? -1 : 1);
  sum += (a[r - 1] - rx) * (((r - 1) & 1) ? -1 : 1);
  long long ssum = ss[r - 1] - ss[l + 1];
  ssum += a[l] - lx;
  ssum += a[r - 1] - rx;
  res += (ssum - abs(sum)) / 2;
  return res;
}

vector<int> ans;

void doOp(int i) {
  int x = min(a[i], a[i + 1]);
  if (!x) {
    return;
  }
  a[i] -= x;
  a[i + 1] -= x;
  ans.push_back(i);
}

void getAns(int l, int r, int tl, int tr) {
  assert(l < r);
  if (r - l == 1) {
    if (!tl || !tr) {
      assert(!a[l]);
    }
    return;
  }
  assert(!(!tl && a[l] > a[l + 1]));
  assert(!(!tr && a[r - 1] > a[r - 2]));
  if (r - l == 2) {
    doOp(l);
    return;
  }
  if (!tl) {
    doOp(l);
    l++;
  }
  if (!tr) {
    doOp(r - 2);
    r--;
  }
  for (int i = l; i < r - 1; i++) {
    doOp(i);
  }
}

void solve() {
  s[0] = 0;
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + a[i] * ((i & 1) ? -1 : 1);
  }
  ss[0] = 0;
  for (int i = 0; i < n; i++) {
    ss[i + 1] = ss[i] + a[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      dp[i][j] = infll;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int t = 0; t < 2; t++) {
      auto cur = dp[i][t];
      if (cur >= infll) {
        continue;
      }
      for (int j = i + 1; j <= n && j - i <= L; j++) {
        int l = (t ^ 1);
        for (int r = 0; r < 2; r++) {
          auto &nxt = dp[j][r];
          auto val = getCost(i, j, l, r);
          if (cur + val < nxt) {
            nxt = cur + val;
            p[j][r] = make_pair(i, t);
          }
        }
      }
    }
  }
  ans.clear();
  for (int i = n, t = 1; i > 0;) {
    int pi = p[i][t].first, pt = p[i][t].second;
    getAns(pi, i, (pt ^ 1), t);
    i = pi;
    t = pt;
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d\n", ans[i] + 1);
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