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

const int maxn = (int) 1e6 + 5;
int n, k;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  k--;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int get2(int l0, int r0, int l1, int r1) {
  int k0 = (r0 - l0) / k;
  r0 -= k0 * k;
  int k1 = (r1 - l1) / k;
  r1 -= k1 * k;
  int res = mul(r0 - l0, k1);
  add(res, mul(r1 - l1, k0));
  add(res, mul(k, mul(k0, k1)));
  l0 %= k;
  r0 %= k;
  l1 %= k;
  r1 %= k;
  if (l0 == r0 || l1 == r1) {
    return res;
  }
  if (l0 < r0) {
    if (l1 < r1) {
      add(res, max(0, min(r0, r1) - max(l0, l1)));
    } else {
      add(res, max(0, r0 - max(l0, l1)));
      add(res, max(0, min(r0, r1) - l0));
    }
  } else {
    if (l1 < r1) {
      add(res, max(0, r1 - max(l1, l0)));
      add(res, max(0, min(r1, r0) - l1));
    } else {
      add(res, k - max(l0, l1));
      add(res, min(r0, r1));
      add(res, max(0, r0 - l1));
      add(res, max(0, r1 - l0));
    }
  }
  return res;
}

int ls[maxn], rs[maxn];

void solve() {
  int res = 0;
  for (int i = 0; i < n; i++) {
    add(res, mod - a[i]);
  }
  vector<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.back()] < a[i]) {
      st.pop_back();
    }
    ls[i] = (st.empty() ? 0 : st.back() + 1);
    st.push_back(i);
  }
  st.clear();
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && a[st.back()] <= a[i]) {
      st.pop_back();
    }
    rs[i] = (st.empty() ? n : st.back());
    st.push_back(i);
  }
  for (int i = 0; i < n; i++) {
    int cnt = get2(ls[i], i + 1, i, rs[i]);
    add(res, mul(a[i], cnt));
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