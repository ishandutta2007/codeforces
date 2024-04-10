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

vector<int> ans;

void doOp(int i) {
  int x = (a[i] ^ a[i + 1] ^ a[i + 2]);
  if (a[i] == x && a[i + 1] == x && a[i + 2] == x) {
    return;
  }
  a[i] = x;
  a[i + 1] = x;
  a[i + 2] = x;
  ans.push_back(i);
}

void solve() {
  ans.clear();
  int s = 0;
  for (int i = 0; i < n; ++i) {
    s ^= a[i];
  }
  if (s) {
    printf("NO\n");
    return;
  }
  int pos = -1;
  s = 0;
  for (int i = 0; i < n; ++i) {
    s ^= a[i];
    if (a[i] == 0 && s == 0) {
      pos = i;
      break;
    }
  }
  if (pos == -1) {
    for (int j = 0; j < n;) {
      if (a[j] == 1) {
        ++j;
        continue;
      }
      int i = j;
      while (j < n && a[j] == 0) {
        ++j;
      }
      if ((j - i) & 1) {
        while (i < j) {
          doOp(i - 1);
          i += 2;
        }
        pos = j - 1;
        break;
      }
    }
    if (pos == -1) {
      printf("NO\n");
      return;
    }
  }
  for (int i = pos - 1; i >= 0; --i) {
    if (!a[i]) {
      continue;
    }
    if (i - 2 >= 0) {
      doOp(i - 2);
    }
    if (!a[i]) {
      continue;
    }
    doOp(i - 1);
  }
  for (int i = pos + 1; i < n; ++i) {
    if (!a[i]) {
      continue;
    }
    if (i + 2 < n) {
      doOp(i);
    }
    if (!a[i]) {
      continue;
    }
    doOp(i - 1);
  }
  printf("YES\n");
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); ++i) {
    printf("%d ", ans[i] + 1);
  }
  printf("\n");
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}