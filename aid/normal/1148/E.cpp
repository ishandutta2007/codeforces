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
pair<int, int> a[maxn], b[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i].first);
    b[i].second = i;
  }
  return true;
}

vector<pair<int, int>> need;
vector<pair<pair<int, int>, int>> ans;

void solve() {
  sort(a, a + n);
  sort(b, b + n);
  need.clear();
  ans.clear();
  for (int i = 0; i < n; i++) {
    if (a[i].first == b[i].first) {
      continue;
    }
    if (a[i].first < b[i].first) {
      need.push_back(make_pair(a[i].second, b[i].first - a[i].first));
      continue;
    }
    int x = a[i].first - b[i].first;
    while (x) {
      if (need.empty()) {
        printf("NO\n");
        return;
      }
      int y = min(x, need.back().second);
      ans.push_back(make_pair(make_pair(need.back().first, a[i].second), y));
      x -= y;
      need.back().second -= y;
      if (!need.back().second) {
        need.pop_back();
      }
    }
  }
  if (!need.empty()) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d %d %d\n", ans[i].first.first + 1, ans[i].first.second + 1, ans[i].second);
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