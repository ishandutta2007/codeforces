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

int a0[maxn];
pair<int, int> tosort[maxn];
vector<pair<int, int>> ans;

void solve() {
  for (int i = 0; i < n; i++) {
    a0[i] = a[i];
  }
  ans.clear();
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(a[i], i);
  }
  sort(tosort, tosort + n);
  for (int it = 0; it < n; it++) {
    int i = tosort[it].second;
    for (int j = n - 1; j > i; j--) {
      if (a0[i] > a0[j]) {
        swap(a[i], a[j]);
        ans.push_back(make_pair(i, j));
      }
    }
  }
  for (int i = 0; i + 1 < n; i++) {
    assert(a[i] <= a[i + 1]);
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
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