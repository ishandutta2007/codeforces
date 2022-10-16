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

const int maxn = 11, pown = (1 << maxn), sigma = 52;
char tmp[sigma * 2 + 5];
string s;
int n;
vector<int> a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", tmp);
    s = tmp;
    a[i].resize(sz(s));
    for (int j = 0; j < sz(s); ++j) {
      if ('a' <= s[j] && s[j] <= 'z') {
        a[i][j] = s[j] - 'a';
      } else {
        a[i][j] = 26 + (s[j] - 'A');
      }
    }
  }
  return true;
}

int bad[sigma];
vector<int> ps[sigma][maxn];
int dp[sigma][pown];
int take[sigma][pown];
pair<int, int> p[sigma][pown];
vector<int> ans;

void getDp(int c, int msk) {
  auto &cur = dp[c][msk];
  auto &curtake = take[c][msk];
  auto &curp = p[c][msk];
  cur = 1;
  curtake = true;
  curp = make_pair(-1, -1);
  for (int i = 0; i < n; ++i) {
    if (msk & (1 << i)) {
      int nmsk = (msk ^ (1 << i));
      if (dp[c][nmsk] == -1) {
        getDp(c, nmsk);
      }
      if (dp[c][nmsk] > cur) {
        cur = dp[c][nmsk];
        curtake = false;
        curp = make_pair(c, nmsk);
      }
    }
  }
  for (int nc = 0; nc < sigma; ++nc) {
    if (bad[nc]) {
      continue;
    }
    int nmsk = 0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (ps[nc][i][0] >= ps[c][i][(msk >> i) & 1]) {
        ok = false;
        break;
      }
      if (sz(ps[nc][i]) >= 2 && ps[nc][i][1] < ps[c][i][(msk >> i) & 1]) {
        nmsk |= (1 << i);
      }
    }
    if (!ok) {
      continue;
    }
    if (dp[nc][nmsk] == -1) {
      getDp(nc, nmsk);
    }
    if (dp[nc][nmsk] + 1 > cur) {
      cur = dp[nc][nmsk] + 1;
      curtake = true;
      curp = make_pair(nc, nmsk);
    }
  }
}

void solve() {
  for (int c = 0; c < sigma; ++c) {
    bad[c] = false;
    for (int i = 0; i < n; ++i) {
      ps[c][i].clear();
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < sz(a[i]); ++j) {
      ps[a[i][j]][i].push_back(j);
    }
  }
  for (int c = 0; c < sigma; ++c) {
    for (int i = 0; i < n; ++i) {
      if (ps[c][i].empty()) {
        bad[c] = true;
        break;
      }
    }
  }
  for (int c = 0; c < sigma; ++c) {
    for (int msk = 0; msk < (1 << n); ++msk) {
      dp[c][msk] = -1;
    }
  }
  int res = -1;
  int lstc = -1, lstmsk = -1;
  for (int c = 0; c < sigma; ++c) {
    if (bad[c]) {
      continue;
    }
    for (int msk = 0; msk < (1 << n); ++msk) {
      bool ok = true;
      for (int i = 0; i < n; ++i) {
        if (((msk >> i) & 1) >= sz(ps[c][i])) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        continue;
      }
      if (dp[c][msk] == -1) {
        getDp(c, msk);
      }
      if (dp[c][msk] > res) {
        res = dp[c][msk];
        lstc = c;
        lstmsk = msk;
      }
    }
  }
  ans.clear();
  while (lstc >= 0) {
    if (take[lstc][lstmsk]) {
      ans.push_back(lstc);
    }
    int c = p[lstc][lstmsk].first;
    int msk = p[lstc][lstmsk].second;
    lstc = c;
    lstmsk = msk;
  }
  reverse(ans.begin(), ans.end());
  s = "";
  for (int i = 0; i < sz(ans); ++i) {
    if (ans[i] < 26) {
      s += (char) ('a' + ans[i]);
    } else {
      s += (char) ('A' + (ans[i] - 26));
    }
  }
  printf("%d\n%s\n", sz(s), s.c_str());
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