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

const int maxn = (int) 5e5 + 5;
int m, k, n, s;
int a[maxn], b[maxn];

bool read() {
  if (scanf("%d%d%d%d", &m, &k, &n, &s) < 4) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < s; i++) {
    scanf("%d", &b[i]);
  }
  return true;
}

int bal[maxn];
int taken[maxn];

void solve() {
  int bad = 0;
  for (int i = 0; i < maxn; i++) {
    bal[i] = 0;
  }
  for (int i = 0; i < s; i++) {
    auto cur = b[i];
    if (!bal[cur]) {
      bad++;
    }
    bal[cur]++;
  }
  for (int i = 0, j = 0; i < m; i++) {
    while (j < m && (bad || j - i < k)) {
      auto cur = a[j];
      if (bal[cur] > 0) {
        bad--;
      }
      bal[cur]--;
      if (bal[cur] > 0) {
        bad++;
      }
      j++;
    }
    if (bad || j - i < k) {
      printf("-1\n");
      return;
    }
    int x = i % k;
    if ((m - x - (j - i)) / k + 1 >= n) {
      vector<int> ans;
      for (int l = 0; l < x; l++) {
        ans.push_back(l);
      }
      for (int l = 0; l < maxn; l++) {
        bal[l] = 0;
      }
      for (int l = 0; l < s; l++) {
        auto cur = b[l];
        bal[cur]++;
      }
      int cnt = 0;
      for (int l = i; l < j; l++) {
        auto cur = a[l];
        if (bal[cur]) {
          bal[cur]--;
          taken[l] = true;
          cnt++;
        } else {
          taken[l] = false;
        }
      }
      for (int l = i; l < j; l++) {
        if (!taken[l]) {
          if (cnt < k) {
            taken[l] = true;
            cnt++;
          } else {
            ans.push_back(l);
          }
        }
      }
      printf("%d\n", sz(ans));
      for (int l = 0; l < sz(ans); l++) {
        printf("%d ", ans[l] + 1);
      }
      printf("\n");
      return;
    }
    {
      auto cur = a[i];
      if (bal[cur] > 0) {
        bad--;
      }
      bal[cur]++;
      if (bal[cur] > 0) {
        bad++;
      }
    }
  }
  printf("-1\n");
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