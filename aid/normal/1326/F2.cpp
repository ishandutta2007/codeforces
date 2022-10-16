#ifdef DEBUG
//#define _GLIBCXX_DEBUG
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

const int maxn = 18, pown = (1 << maxn);
long long fact[maxn + 1];

void precalc() {
  fact[0] = 1;
  for (int i = 1; i <= maxn; i++) {
    fact[i] = fact[i - 1] * i;
  }
}

int n;
int g[maxn][maxn];
char tmp[100];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    for (int j = 0; j < n; j++) {
      g[i][j] = tmp[j] - '0';
    }
  }
  return true;
}

map<vector<int>, long long> parts;
vector<int> msks[maxn + 1];
vector<int> a;
long long dp[pown][maxn];

void gen(int m) {
  if (!m) {
    long long res = 0;
    for (int i = 0; i < n; i++) {
      res += dp[(1 << n) - 1][i];
    }
    parts[a] = res;
    return;
  }
  int mx = (a.empty() ? m : min(m, a.back()));
  if (mx == 1) {
    for (int i = 0; i < m; i++) {
      a.push_back(1);
    }
    int pos = n - m;
    long long res = 0;
    for (auto msk : msks[pos]) {
      for (int i = 0; i < n; i++) {
        if (!(msk & (1 << i))) {
          continue;
        }
        auto cur = dp[msk][i];
        if (!cur) {
          continue;
        }
        res += cur;
      }
    }
    res *= fact[m];
    parts[a] = res;
    for (int i = 0; i < m; i++) {
      a.pop_back();
    }
    return;
  }
  for (int ii = 1; ii <= mx; ii++) {
    a.push_back(ii);
    int pos = n - m + ii - 1;
    if (!pos) {
      for (int i = 0; i < n; i++) {
        dp[(1 << i)][i] = 1;
      }
    } else {
      for (auto msk : msks[pos + 1]) {
        for (int i = 0; i < n; i++) {
          dp[msk][i] = 0;
        }
      }
      for (auto msk : msks[pos]) {
        for (int i = 0; i < n; i++) {
          if (!(msk & (1 << i))) {
            continue;
          }
          auto cur = dp[msk][i];
          if (!cur) {
            continue;
          }
          for (int j = 0; j < n; j++) {
            if (msk & (1 << j)) {
              continue;
            }
            if (ii > 1 && !g[i][j]) {
              continue;
            }
            dp[msk | (1 << j)][j] += cur;
          }
        }
      }
    }
    gen(m - ii);
    a.pop_back();
  }
}

long long ans[pown];

void solve() {
  for (int i = 0; i <= n; i++) {
    msks[i].clear();
  }
  for (int msk = 0; msk < (1 << n); msk++) {
    msks[__builtin_popcount(msk)].push_back(msk);
  }
  parts.clear();
  a.clear();
  gen(n);
  for (int msk = 0; msk < (1 << (n - 1)); msk++) {
    a.clear();
    for (int j = 0; j < n;) {
      int i = j;
      while (msk & (1 << j)) {
        j++;
      }
      j++;
      a.push_back(j - i);
    }
    sort(a.begin(), a.end(), greater<int>());
    ans[msk] = parts[a];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int msk = 0; msk < (1 << (n - 1)); msk++) {
      if (!(msk & (1 << i))) {
        ans[msk] -= ans[msk | (1 << i)];
      }
    }
  }
  for (int msk = 0; msk < (1 << (n - 1)); msk++) {
    printf("%lld ", ans[msk]);
  }
  printf("\n");
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