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

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = (int) 2e5 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

vector<long long> xs;
vector<int> fen[2];
int cnt[2];

void upd(int i, int t) {
  for (; i < sz(fen[t]); i |= i + 1) {
    ++fen[t][i];
  }
}

void update(long long x, int t) {
  int pos = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
  upd(pos, t);
  ++cnt[t];
}

int getSum(int i, int t) {
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res += fen[t][i];
  }
  return res;
}

int get(long long x, int t) {
  int pos = upper_bound(xs.begin(), xs.end(), -x) - xs.begin() - 1;
  return cnt[t] - getSum(pos, t);
}

void solve() {
  if (n == 1) {
    printf("1\n");
    return;
  }
  int res = 1;
  for (int l = 0; l <= 1; ++l) {
    for (int r = n - 1; r <= n; ++r) {
      long long bal = 0;
      if (l == 1) {
        bal += a[0];
      }
      if (r == n - 1) {
        bal -= a[n - 1];
      }
      {
        xs.clear();
        long long s = 0, t = 0;
        for (int i = l; i < r; ++i) {
          xs.push_back(s - t);
          s -= a[i];
          t = -a[i] - t;
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
      }
      for (int t = 0; t < 2; ++t) {
        fen[t].clear();
        fen[t].resize(sz(xs));
        cnt[t] = 0;
      }
      long long all = 0;
      for (int i = l; i < r; ++i) {
        all += a[i];
      }
      {
        long long s = 0, t = 0;
        for (int i = l; i < r; ++i) {
          long long cur = s - t;
          if (l == 0 || i - l >= 2) {
            update(cur, (i & 1));
          }
          if (i > l) {
            long long val = all + s + t;
            add(res, get(val + bal, (i & 1)));
          }
          s -= a[i];
          t = -a[i] - t;
        }
      }
    }
  }
  long long suff = 0;
  for (int i = 0; i < n; ++i) {
    suff += a[i];
  }
  long long pref = 0;
  for (int i = 0; i < n; ++i) {
    if (pref > suff) {
      add(res, 1);
    }
    pref += a[i];
    suff -= a[i];
  }
  printf("%d\n", res);
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