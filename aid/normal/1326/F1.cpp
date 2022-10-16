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

const int maxn = 18, pown = (1 << maxn);
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
vector<int> a;
vector<int> s;
long long dp[pown][maxn];

void gen(int m) {
  if (!m) {
    for (int msk = 0; msk < (1 << n); msk++) {
      for (int i = 0; i < n; i++) {
        dp[msk][i] = 0;
      }
    }
    for (int msk = 0; msk < (1 << n); msk++) {
      for (int i = 0; i < n; i++) {
        if (!(msk & (1 << i))) {
          continue;
        }
        if (msk == (1 << i)) {
          dp[msk][i] = 1;
        }
        int pos = __builtin_popcount(msk) - 1;
        auto cur = dp[msk][i];
        for (int j = 0; j < n; j++) {
          if (msk & (1 << j)) {
            continue;
          }
          if (s[pos] && !g[i][j]) {
            continue;
          }
          dp[msk | (1 << j)][j] += cur;
        }
      }
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
      res += dp[(1 << n) - 1][i];
    }
    parts[a] = res;
    return;
  }
  int mx = (a.empty() ? m : min(m, a.back()));
  int ss = sz(s);
  for (int i = 1; i <= mx; i++) {
    a.push_back(i);
    for (int j = 0; j < i - 1; j++) {
      s.push_back(1);
    }
    s.push_back(0);
    gen(m - i);
    a.pop_back();
    s.resize(ss);
  }
}

long long ans[pown];

void solve() {
  parts.clear();
  a.clear();
  s.clear();
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