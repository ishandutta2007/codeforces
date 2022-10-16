#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 25;
int n, m;
int a[maxn][maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      a[i][j]--;
    }
  }
  return true;
}

bool check(int t) {
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    if (a[t][i] != i) {
      cnt++;
    }
  }
  return cnt <= 2;
}

void solve() {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < n; k++) {
        swap(a[k][i], a[k][j]);
      }
      bool ok = true;
      for (int k = 0; k < n; k++) {
        if (!check(k)) {
          ok = false;
          break;
        }
      }
      if (ok) {
        printf("YES\n");
        return;
      }
      for (int k = 0; k < n; k++) {
        swap(a[k][i], a[k][j]);
      }
    }
  }
  printf("NO\n");
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}