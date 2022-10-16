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

const int maxn = (int) 3e5 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

vector<int> xs;
int ls[maxn], rs[maxn];

void solve() {
  xs.clear();
  for (int i = 0; i < n; i++) {
    xs.push_back(a[i]);
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin();
  }
  for (int i = 0; i < sz(xs); i++) {
    ls[i] = inf;
    rs[i] = -inf;
  }
  for (int i = 0; i < n; i++) {
    ls[a[i]] = min(ls[a[i]], i);
    rs[a[i]] = max(rs[a[i]], i);
  }
  int res = sz(xs);
  for (int j = 0; j < sz(xs); j++) {
    int i = j;
    while (j + 1 < sz(xs) && rs[j] < ls[j + 1]) {
      j++;
    }
    res = min(res, sz(xs) - (j - i + 1));
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