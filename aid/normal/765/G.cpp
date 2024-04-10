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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int powMod(int x, int p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mul(res, x);
    }
    p >>= 1;
    x = mul(x, x);
  }
  return res;
}

const int maxn = (int) 5e5 + 5, maxlen = 45;
int len;
long long msk;
char tmp[maxlen];
int n;
int p[maxn], a[maxn];
int pa[maxn];

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  len = strlen(tmp);
  msk = 0;
  for (int i = 0; i < len; i++) {
    if (tmp[i] == '0') {
      msk |= (1ll << i);
    }
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &p[i], &a[i]);
  }
  return true;
}

pair<int, int> tosort[maxn];

const int m = (int) 2e6 + 5;

struct HashTable {
  pair<pair<long long, int>, int> a[m];

  HashTable() {
    init();
  }

  void init() {
    memset(a, -1, sizeof(a));
  }

  int &operator [] (const pair<long long, int> &x) {
    int pos = ((x.first << 9) ^ x.second) % m;
    while (a[pos].first != x) {
      if (a[pos].second == -1) {
        a[pos].first = x;
        a[pos].second = 0;
        return a[pos].second;
      }
      pos++;
      if (pos == m) {
        pos = 0;
      }
    }
    return a[pos].second;
  }
};

HashTable h, nh;

void gen() {
  h.init();
  h[make_pair(0, 0)] = 1;
  for (int i = 0; i < n && 2 * p[i] <= len; i++) {
    long long x = 0;
    for (int j = 0; j < len; j += p[i]) {
      x |= (1ll << j);
    }
    nh.init();
    for (int iter = 0; iter < m; iter++) {
      auto it = &h.a[iter];
      long long cur = it->first.first;
      int val = it->second;
      if (val == -1) {
        continue;
      }
      for (int rem = 0; rem < p[i]; rem++) {
        long long nxt = (cur | ((x << rem) & ((1ll << len) - 1)));
        if ((nxt & msk) == nxt) {
          add(nh[make_pair(nxt, 0)], mul(pa[i], val));
        }
      }
    }
    swap(h, nh);
  }
}

int dp[maxlen];

void solve() {
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(p[i], a[i]);
  }
  sort(tosort, tosort + n);
  for (int i = 0; i < n; i++) {
    p[i] = tosort[i].first;
    a[i] = tosort[i].second;
    pa[i] = powMod(p[i], a[i] - 1);
  }
  int l = 0, r = len;
  long long y = (1ll << len) - 1;
  for (int i = 0; i < n; i++) {
    if (2 * p[i] > len && p[i] <= len) {
      l = len - p[i];
      r = p[i];
      y = (((1ll << r) - 1) ^ ((1ll << l) - 1));
      break;
    }
  }
  gen();
  nh.init();
  for (int iter = 0; iter < m; iter++) {
    auto it = &h.a[iter];
    long long cur = it->first.first;
    int cnt = 0;
    int val = it->second;
    if (val == -1) {
      continue;
    }
    cnt += __builtin_popcountll((cur & msk & y) ^ (msk & y));
    cur |= y;
    add(nh[make_pair(cur, cnt)], val);
  }
  swap(h, nh);
  for (int i = 0; i < n && p[i] <= len; i++) {
    if (2 * p[i] <= len) {
      continue;
    }
    int nl, nr;
    long long ny;
    if (i + 1 < n && p[i + 1] <= len) {
      nl = len - p[i + 1];
      nr = p[i + 1];
      ny = (((1ll << nr) - 1) ^ ((1ll << nl) - 1));
    } else {
      nl = 0;
      nr = len;
      ny = (1ll << len) - 1;
    }
    int all = __builtin_popcountll(msk & y);
    long long x = 0;
    for (int j = 0; j < len; j += p[i]) {
      x |= (1ll << j);
    }
    nh.init();
    for (int iter = 0; iter < m; iter++) {
      auto it = &h.a[iter];
      long long cur = it->first.first;
      int cnt = it->first.second;
      int val = it->second;
      if (val == -1) {
        continue;
      }
      for (int rem = 0; rem < l; rem++) {
        long long nxt = (cur | ((x << rem) & ((1ll << len) - 1)));
        if ((nxt & msk & ~y) == (nxt & ~y)) {
          int ncnt = cnt;
          ncnt += __builtin_popcountll((nxt & msk & ny) ^ (msk & ny));
          nxt |= ny;
          add(nh[make_pair(nxt, ncnt)], mul(pa[i], val));
        }
      }
      if (cnt) {
        long long nxt = cur;
        int ncnt = cnt - 1;
        ncnt += __builtin_popcountll((nxt & msk & ny) ^ (msk & ny));
        nxt |= ny;
        add(nh[make_pair(nxt, ncnt)], mul(mul(cnt, pa[i]), val));
      }
      if (all - cnt) {
        long long nxt = cur;
        int ncnt = cnt;
        ncnt += __builtin_popcountll((nxt & msk & ny) ^ (msk & ny));
        nxt |= ny;
        add(nh[make_pair(nxt, ncnt)], mul(mul(all - cnt, pa[i]), val));
      }
    }
    swap(h, nh);
    l = nl;
    r = nr;
    y = ny;
  }
  for (int i = 0; i <= len; i++) {
    dp[i] = 0;
  }
  for (int iter = 0; iter < m; iter++) {
    auto it = &h.a[iter];
    int cnt = it->first.second;
    int val = it->second;
    add(dp[cnt], val);
  }
  int all = __builtin_popcountll(msk);
  for (int i = 0; i < n; i++) {
    if (p[i] <= len) {
      continue;
    }
    for (int j = 0; j <= all; j++) {
      dp[j] = mul(p[i] - len + all - j, dp[j]);
      add(dp[j], mul(j + 1, dp[j + 1]));
      dp[j] = mul(dp[j], pa[i]);
    }
  }
  printf("%d\n", dp[0]);
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