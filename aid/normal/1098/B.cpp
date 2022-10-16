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
vector<string> c;
char tmp[maxn];

bool read() {
  int n, m;
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  c.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    c[i] = tmp;
  }
  return true;
}

const string chs = "ACGT";

int solve1(const vector<string> &c, vector<string> &ans) {
  int res = inf;
  int n = sz(c);
  int m = sz(c[0]);
  for (int c0 = 0; c0 < 4; c0++) {
    for (int c1 = c0 + 1; c1 < 4; c1++) {
      vector<string> curAns = c;
      int cur = 0;
      string a, b;
      for (int i = 0; i < 4; i++) {
        if (i == c0 || i == c1) {
          a += chs[i];
        } else {
          b += chs[i];
        }
      }
      for (int i = 0; i < n; i++) {
        int cnt0 = 0, cnt1 = 0;
        const auto &t = (!(i & 1) ? a : b);
        for (int j = 0; j < m; j++) {
          if (c[i][j] != t[j & 1]) {
            cnt0++;
          }
          if (c[i][j] != t[!(j & 1)]) {
            cnt1++;
          }
        }
        int sh = (cnt0 < cnt1 ? 0 : 1);
        cur += min(cnt0, cnt1);
        for (int j = 0; j < m; j++) {
          curAns[i][j] = t[(j & 1) ^ sh];
        }
      }
      if (cur < res) {
        res = cur;
        ans = curAns;
      }
    }
  }
  return res;
}

vector<string> flip(const vector<string> &c) {
  int n = sz(c);
  int m = sz(c[0]);
  vector<string> ans(m, string(n, ' '));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans[j][i] = c[i][j];
    }
  }
  return ans;
}

void solve() {
  vector<string> ans;
  int res = inf;
  for (int it = 0; it < 2; it++) {
    vector<string> curAns;
    int cur = solve1(c, curAns);
    if (cur < res) {
      res = cur;
      if (it) {
        ans = flip(curAns);
      } else {
        ans = curAns;
      }
    }
    c = flip(c);
  }
  for (int i = 0; i < sz(ans); i++) {
    printf("%s\n", ans[i].c_str());
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