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

const int maxn = 1005;
int n, m;
int es[maxn][2];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 2; ++j) {
      scanf("%d", &es[i][j]);
      --es[i][j];
    }
  }
  return true;
}

int p[maxn], ts[maxn];

int get(int x) {
  return (p[x] == x ? x : p[x] = get(p[x]));
}

bool unite(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y) {
    return false;
  }
  if (ts[x] < ts[y]) {
    swap(x, y);
  }
  ts[x] += ts[y];
  p[y] = x;
  return true;
}

vector<int> cs;

int getAns(int k) {
  cs.clear();
  for (int i = 0; i < n; ++i) {
    if (p[i] == i) {
      cs.push_back(ts[i]);
    }
  }
  nth_element(cs.begin(), cs.begin() + k, cs.end(), greater<int>());
  int res = -1;
  for (int i = 0; i < k; ++i) {
    res += cs[i];
  }
  return res;
}

void solve() {
  for (int i = 0; i < n; ++i) {
    p[i] = i;
    ts[i] = 1;
  }
  int k = 1;
  for (int i = 0; i < m; ++i) {
    if (!unite(es[i][0], es[i][1])) {
      ++k;
    }
    printf("%d\n", getAns(k));
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