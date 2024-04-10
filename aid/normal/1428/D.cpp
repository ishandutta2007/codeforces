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

const int maxn = (int) 1e5 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

vector<pair<int, int>> ans;
vector<pair<int, int>> ones, twos;

void solve() {
  ans.clear();
  ones.clear();
  twos.clear();
  int curr = n - 1;
  for (int i = n - 1; i >= 0; --i) {
    if (!a[i]) {
      continue;
    }
    if (a[i] == 1) {
      int r = curr--;
      ans.push_back(make_pair(r, i));
      ones.push_back(make_pair(i, r));
      continue;
    }
    if (a[i] == 2) {
      if (ones.empty()) {
        printf("-1\n");
        return;
      }
      int r = ones.back().second;
      ones.pop_back();
      ans.push_back(make_pair(r, i));
      twos.push_back(make_pair(i, r));
      continue;
    }
    int c = -1;
    if (!twos.empty()) {
      c = twos.back().first;
      twos.pop_back();
    } else if (!ones.empty()) {
      c = ones.back().first;
      ones.pop_back();
    }
    if (c == -1) {
      printf("-1\n");
      return;
    }
    int r = curr--;
    ans.push_back(make_pair(r, i));
    ans.push_back(make_pair(r, c));
    twos.push_back(make_pair(i, r));
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); ++i) {
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