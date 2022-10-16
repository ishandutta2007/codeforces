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

const int mod = 998244353;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = 505, maxm = (int) 1e6 + 5;
int n, m;
int a[maxm];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  return true;
}

int dp[maxn][maxn];

int solveSmall(const vector<int> &a) {
  int n = sz(a);
  for (int i = 0; i <= n; i++) {
    dp[i][i] = 1;
  }
  for (int len = 1; len <= n; len++) {
    for (int i = 0; i + len <= n; i++) {
      int j = i + len;
      int id = inf;
      int pos = -1;
      for (int k = i; k < j; k++) {
        if (a[k] < id) {
          id = a[k];
          pos = k;
        }
      }
      int l = 0;
      for (int k = i; k <= pos; k++) {
        add(l, mul(dp[i][k], dp[k][pos]));
      }
      int r = 0;
      for (int k = pos + 1; k <= j; k++) {
        add(r, mul(dp[pos + 1][k], dp[k][j]));
      }
      dp[i][j] = mul(l, r);
    }
  }
  return dp[0][n];
}

set<pair<int, int>> st;
vector<int> ps[maxn];

void solve() {
  st.clear();
  for (int i = 0; i < n; i++) {
    ps[i].clear();
  }
  for (int i = 0; i < m; i++) {
    st.insert(make_pair(i, a[i]));
    ps[a[i]].push_back(i);
  }
  int res = 1;
  for (int c = n - 1; c >= 0; c--) {
    while (sz(ps[c]) > 1) {
      int l = ps[c][sz(ps[c]) - 2], r = ps[c][sz(ps[c]) - 1];
      auto it = st.lower_bound(make_pair(l, c));
      vector<int> cur;
      it++;
      while (it->first != r) {
        int x = it->second;
        if (x < c) {
          printf("0\n");
          return;
        }
        cur.push_back(x);
        auto del = it;
        it++;
        st.erase(del);
      }
      res = mul(res, solveSmall(cur));
      st.erase(it);
      ps[c].pop_back();
    }
  }
  {
    vector<int> cur;
    for (auto it = st.begin(); it != st.end(); it++) {
      cur.push_back(it->second);
    }
    res = mul(res, solveSmall(cur));
  }
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