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

const int maxn = (int) 1e5 + 5;
int n, k;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  return true;
}

const int K = 400, maxb = (maxn + K) / K;
int s[maxb][2 * maxn];
int toadd[maxb];
int lst[maxn];
int p[maxn];
int dp[maxn];
int bal[maxn];

void add1(int pos, int val) {
  int b = pos / K;
  auto &cur = bal[pos];
  assert(val == 1 || val == -1);
  if (val == 1) {
    add(s[b][maxn + cur], mod - dp[pos]);
    cur++;
  } else {
    cur--;
    add(s[b][maxn + cur], dp[pos]);
  }
}

void addAll(int b, int val) {
  toadd[b] += val;
}

void addSeg(int l, int r, int val) {
  while (l < r && l % K) {
    add1(l, val);
    l++;
  }
  while (l / K < r / K) {
    addAll(l / K, val);
    l += K;
  }
  while (l < r) {
    add1(l, val);
    l++;
  }
}

int get1(int pos) {
  int b = pos / K;
  return (bal[pos] + toadd[b] <= k ? dp[pos] : 0);
}

int getAll(int b) {
  return s[b][maxn + k - toadd[b]];
}

int getSum(int l, int r) {
  int res = 0;
  while (l < r && l % K) {
    add(res, get1(l));
    l++;
  }
  while (l / K < r / K) {
    add(res, getAll(l / K));
    l += K;
  }
  while (l < r) {
    add(res, get1(l));
    l++;
  }
  return res;
}

void buildBlock(int b) {
  memset(s[b], 0, sizeof(s[b]));
  int l = b * K, r = min(n, l + K);
  toadd[b] = 0;
  for (int i = l; i < r; i++) {
    add(s[b][maxn + bal[i]], dp[i]);
  }
  for (int i = 1; i < 2 * maxn; i++) {
    add(s[b][i], s[b][i - 1]);
  }
}

void solve() {
  memset(bal, 0, sizeof(bal));
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    lst[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    p[i] = lst[a[i]];
    lst[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    if (p[i] == -1) {
      addSeg(0, i + 1, 1);
    } else {
      addSeg(p[p[i]] + 1, p[i] + 1, -1);
      addSeg(p[i] + 1, i + 1, 1);
    }
    dp[i + 1] = getSum(0, i + 1);
    if (!((i + 2) % K)) {
      buildBlock((i + 1) / K);
    }
  }
  printf("%d\n", dp[n]);
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