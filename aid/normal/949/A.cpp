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

const int maxn = (int) 2e5 + 5;
int n;
string s;
char tmp[maxn];

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

vector<vector<int>> ans;
set<int> st[2];

void solve() {
  ans.clear();
  st[0].clear();
  st[1].clear();
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      if (!st[1].empty()) {
        int id = *st[1].begin();
        st[1].erase(st[1].begin());
        st[0].insert(id);
        ans[id].push_back(i);
      } else {
        st[0].insert(sz(ans));
        ans.push_back({i});
      }
    } else {
      if (!st[0].empty()) {
        int id = *st[0].begin();
        st[0].erase(st[0].begin());
        st[1].insert(id);
        ans[id].push_back(i);
      } else {
        printf("-1\n");
        return;
      }
    }
  }
  if (!st[1].empty()) {
    printf("-1\n");
    return;
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d", sz(ans[i]));
    for (int j = 0; j < sz(ans[i]); j++) {
      printf(" %d", ans[i][j] + 1);
    }
    printf("\n");
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