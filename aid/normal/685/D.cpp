#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
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

const int maxn = (int) 1e5 + 5;
int n, k;
pair<int, int> p[maxn];
long long ans[maxn];
vector<int> evs[2 * maxn];
vector< pair<int, int> > ev0, ev1, ev;
vector<int> ys;


int read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &p[i].first, &p[i].second);
  }
  return true;
}

void solve() {
  sort(p, p + n);
  ys.clear();
  for (int i = 0; i < n; i++) {
    ys.push_back(p[i].second - k + 1);
    ys.push_back(p[i].second + 1);
  }
  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());
  for (int i = 0; i < sz(ys); i++) {
    evs[i].clear();
  }
  for (int i = 0; i < n; i++) {
    int ly = lower_bound(ys.begin(), ys.end(), p[i].second - k + 1) - ys.begin(),
      ry = lower_bound(ys.begin(), ys.end(), p[i].second + 1) - ys.begin();
    for (int j = ly; j < ry; j++) {
      evs[j].push_back(p[i].first - k + 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    ans[i] = 0;
  }
  for (int i = 0; i + 1 < sz(ys); i++) {
    ev0.clear();
    ev1.clear();
    for (int j = 0; j < sz(evs[i]); j++) {
      ev0.push_back(make_pair(evs[i][j], 1));
      ev1.push_back(make_pair(evs[i][j] + k, -1));
    }
    ev.clear();
    ev.resize(sz(ev0) + sz(ev1));
    merge(ev0.begin(), ev0.end(), ev1.begin(), ev1.end(), ev.begin());
    int cur = 0;
    for (int j = 0; j < sz(ev); j++) {
      cur += ev[j].second;
      if (cur) {
        ans[cur] += (long long) (ys[i + 1] - ys[i]) *
          (ev[j + 1].first - ev[j].first);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%lld ", ans[i]);
  }
  printf("\n");
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}