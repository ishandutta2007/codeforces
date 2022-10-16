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

const int maxn = 105;
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

pair<int, int> tosort[maxn];
int used[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(abs(a[i]), i);
  }
  sort(tosort, tosort + n);
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  int bal = 0;
  for (int i = n - 1; i >= 0; i--) {
    int p = tosort[i].second;
    used[p] = true;
    int cnt = 0;
    bool b = false;
    if (p && !used[p - 1]) {
      cnt++;
      b = true;
    }
    if (p + 1 < n && !used[p + 1]) {
      cnt++;
    }
    if (!(cnt & 1)) {
      continue;
    }
    if (bal ^ b) {
      a[p] = abs(a[p]);
    } else {
      a[p] = -abs(a[p]);
    }
    bal ^= 1;
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
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