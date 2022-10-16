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

const int maxn = (int) 1e6 + 5;
int n;
long long xs[maxn], ys[maxn], as[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld%lld", &xs[i], &ys[i], &as[i]);
  }
  return true;
}

pair<long long, int> tosort[maxn];
long long nxs[maxn], nys[maxn], nas[maxn];

struct line {
  long long a, b;

  line(long long _a, long long _b): a(_a), b(_b) {}

  long long eval(long long x) const {
    return a * x + b;
  }
};

bool bad(const line &l0, const line &l1, const line &l2) {
  return (ld) (l1.b - l0.b) / (l0.a - l1.a) <= (ld) (l2.b - l1.b) / (l1.a - l2.a);
}

vector<line> st;
int pos;

void add(const line &l) {
  while (sz(st) >= 2 && bad(st[sz(st) - 2], st[sz(st) - 1], l)) {
    st.pop_back();
  }
  pos = min(pos, sz(st));
  st.push_back(l);
}

long long get(long long x) {
  while (pos + 1 < sz(st) && st[pos + 1].eval(x) > st[pos].eval(x)) {
    pos++;
  }
  return st[pos].eval(x);
}

long long dp[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(xs[i], i);
  }
  sort(tosort, tosort + n);
  for (int i = 0; i < n; i++) {
    int id = tosort[i].second;
    nxs[i] = xs[id];
    nys[i] = ys[id];
    nas[i] = as[id];
  }
  for (int i = 0; i < n; i++) {
    xs[i] = nxs[i];
    ys[i] = nys[i];
    as[i] = nas[i];
  }
  st.clear();
  pos = 0;
  add(line(0, 0));
  long long res = 0;
  for (int i = 0; i < n; i++) {
    dp[i] = get(ys[i]) + xs[i] * ys[i] - as[i];
    res = max(res, dp[i]);
    add(line(-xs[i], dp[i]));
  }
  printf("%lld\n", res);
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