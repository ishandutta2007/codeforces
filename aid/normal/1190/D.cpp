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

const int maxn = (int) 2e5 + 5;
int n;
pair<int, int> ps[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    ps[i] = make_pair(-y, x);
  }
  return true;
}

vector<int> xs;
int fen[maxn];

void add(int i, int val, int n) {
  for (; i < n; i |= i + 1) {
    fen[i] += val;
  }
}

int get(int i, int n) {
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res += fen[i];
  }
  return res;
}

int used[maxn];

void solve() {
  sort(ps, ps + n);
  n = unique(ps, ps + n) - ps;
  xs.clear();
  for (int i = 0; i < n; i++) {
    ps[i].first *= -1;
    swap(ps[i].first, ps[i].second);
    xs.push_back(ps[i].first);
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  for (int i = 0; i < sz(xs); i++) {
    fen[i] = 0;
    used[i] = false;
  }
  for (int i = 0; i < n; i++) {
    int x = ps[i].first;
    x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    ps[i].first = x;
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    int x = ps[i].first, y = ps[i].second;
    if (!used[x]) {
      used[x] = true;
      add(x, 1, sz(xs));
    }
    int r = sz(xs) - 1;
    if (i + 1 < n && y == ps[i + 1].second) {
      r = ps[i + 1].first - 1;
    }
    long long ll = get(x, sz(xs));
    long long all = get(r, sz(xs));
    long long rr = all - ll;
    ll--;
    res += (ll + 1) * (rr + 1);
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