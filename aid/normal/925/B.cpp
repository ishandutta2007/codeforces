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

const int maxn = (int) 3e5 + 5;
int n;
int x[2];
int c[maxn];

int read() {
  if (scanf("%d%d%d", &n, &x[0], &x[1]) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
  }
  return true;
}

int need[maxn][2];
pair<pair<int, int>, int> tosort[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      auto &cur = need[i][j];
      cur = (x[j] + c[i] - 1) / c[i];
      cur = min(cur, n + 1);
    }
  }
  for (int iter = 0; iter < 2; iter++) {
    for (int i = 0; i < n; i++) {
      tosort[i] = make_pair(make_pair(need[i][0], need[i][1]), i);
    }
    sort(tosort, tosort + n);
    vector<int> st;
    for (int i = 1, pos = 0; i <= n; i++) {
      while (pos < n && tosort[pos].first.first <= i) {
        pos++;
      }
      if (pos <= i) {
        st.clear();
        continue;
      }
      while (sz(st) > pos - i) {
        st.pop_back();
      }
      while (sz(st) < pos - i) {
        int id = tosort[sz(st)].second;
        int val = min((st.empty() ? inf : st.back()), need[id][1] - sz(st) - 1);
        st.push_back(val);
      }
      if (st.back() <= 0) {
        vector<int> ans[2];
        for (int it = 0; it < i; it++) {
          int id = tosort[pos - i + it].second;
          ans[0].push_back(id);
        }
        for (int it = 0; it < pos - i; it++) {
          int id = tosort[it].second;
          ans[1].push_back(id);
          if (need[id][1] - sz(ans[1]) <= 0) {
            break;
          }
        }
        if (iter) {
          swap(ans[0], ans[1]);
        }
        printf("Yes\n");
        printf("%d %d\n", sz(ans[0]), sz(ans[1]));
        for (int it = 0; it < 2; it++) {
          for (int j = 0; j < sz(ans[it]); j++) {
            printf("%d ", ans[it][j] + 1);
          }
          printf("\n");
        }
        return;
      }
    }
    for (int i = 0; i < n; i++) {
      swap(need[i][0], need[i][1]);
    }
  }
  printf("No\n");
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