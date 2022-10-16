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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e5 + 5;
int n;
int xs0[maxn], ys0[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &xs0[i], &ys0[i]);
  }
  return true;
}

int xs[maxn], ys[maxn];
pair<int, int> tosort[maxn];
int a[4];
vector<pair<int, pair<int, int> > > evs;

long long solve(int n) {
  for (int i = 0; i < n; i++) {
    int nx = xs[i] - ys[i];
    int ny = xs[i] + ys[i];
    xs[i] = nx;
    ys[i] = ny;
    tosort[i] = make_pair(xs[i], i);
  }
  sort(tosort, tosort + n);
  evs.clear();
  a[0] = -inf;
  a[1] = inf;
  for (int j = 0; j < n;) {
    int i = j;
    while (j < n && tosort[j].first == tosort[i].first) {
      j++;
    }
    for (int k = i; k < j; k++) {
      int id = tosort[k].second;
      a[0] = max(a[0], ys[id]);
      a[1] = min(a[1], ys[id] + 1);
    }
    evs.push_back(make_pair(tosort[i].first + 1, make_pair(0, a[0])));
    evs.push_back(make_pair(tosort[i].first + 1, make_pair(1, a[1])));
  }
  a[2] = -inf;
  a[3] = inf;
  reverse(tosort, tosort + n);
  for (int j = 0; j < n;) {
    int i = j;
    while (j < n && tosort[j].first == tosort[i].first) {
      j++;
    }
    evs.push_back(make_pair(tosort[i].first, make_pair(2, a[2])));
    evs.push_back(make_pair(tosort[i].first, make_pair(3, a[3])));
    for (int k = i; k < j; k++) {
      int id = tosort[k].second;
      a[2] = max(a[2], ys[id]);
      a[3] = min(a[3], ys[id] + 1);
    }
  }
  a[0] = -inf;
  a[1] = inf;
  sort(evs.begin(), evs.end());
  long long res = 0;
  for (int i = 0; i + 1 < sz(evs); i++) {
    a[evs[i].second.first] = evs[i].second.second;
    int lx = evs[i].first, rx = evs[i + 1].first;
    int ly = max(a[1], a[3]), ry = min(a[0], a[2]);
    if (lx >= rx || ly >= ry) {
      continue;
    }
    lx |= 1;
    rx |= 1;
    ly |= 1;
    ry |= 1;
    res += (long long) (rx - lx) * (ry - ly) / 4;
  }
  return res;
}

void solve() {
  long long res = 0;
  for (int it = 0; it < 2; it++) {
    int nn = 0;
    for (int i = 0; i < n; i++) {
      if (((xs0[i] + ys0[i]) & 1) == it) {
        xs[nn] = xs0[i];
        ys[nn] = ys0[i] - it;
        nn++;
      }
    }
    res += solve(nn);
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