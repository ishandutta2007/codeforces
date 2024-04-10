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

long long s[maxn];

void solve() {
  sort(a, a + n, greater<int>());
  s[0] = 0;
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + a[i];
  }
  int l = 0, r = n;
  for (int i = 0, j = n; i < n; i++) {
    long long x = s[i];
    long long y = (long long) (i + 1) * i;
    while (j && a[j - 1]  <= i + 1) {
      j--;
    }
    if (j <= i) {
      y += s[n] - s[i];
    } else {
      y += (long long) (j - i) * (i + 1);
      y += s[n] - s[j];
    }
    r = min((long long) r, max((long long) a[i], y - x));
  }
  for (int i = 0, j = n; i < n; i++) {
    long long x = s[i + 1];
    long long y = (long long) (i + 1) * i;
    while (j && a[j - 1]  <= i + 1) {
      j--;
    }
    if (j <= i + 1) {
      y += s[n] - s[i + 1];
    } else {
      y += (long long) (j - i - 1) * (i + 1);
      y += s[n] - s[j];
    }
    if (i + 1 < x - y) {
      printf("-1\n");
      return;
    }
    l = max((long long) l, min((long long) a[i], x - y));
  }
  int t = 0;
  for (int i = 0; i < n; i++) {
    t ^= (a[i] & 1);
  }
  vector<int> ans;
  for (int i = l; i <= r; i++) {
    if ((i & 1) == t) {
      ans.push_back(i);
    }
  }
  if (ans.empty()) {
    printf("-1\n");
    return;
  }
  for (int i = 0; i < sz(ans); i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
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