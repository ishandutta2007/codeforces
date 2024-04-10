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
int n, w, h;
int dir[maxn], x[maxn], t[maxn];

int read() {
  if (scanf("%d%d%d", &n, &w, &h) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &dir[i], &x[i], &t[i]);
    dir[i]--;
  }
  return true;
}

pair<int, pair<pair<int, int>, int> > tosort[maxn];
pair<int, int> ans[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(x[i] - t[i], make_pair(make_pair(!dir[i], x[i] * (1 - 2 * dir[i])), i));
  }
  sort(tosort, tosort + n);
  for (int j = 0; j < n;) {
    int i = j;
    vector< pair<int, int> > a;
    while (j < n && tosort[j].first == tosort[i].first) {
      int id = tosort[j].second.second;
      a.push_back(make_pair(dir[id], x[id] * (1 - 2 * dir[id])));
      j++;
    }
    sort(a.begin(), a.end());
    for (int k = i; k < j; k++) {
      int id = tosort[k].second.second;
      int xx, yy;
      if (!a[k - i].first) {
        xx = a[k - i].second;
        yy = h;
      } else {
        xx = w;
        yy = -a[k - i].second;
      }
      ans[id] = make_pair(xx, yy);
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
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