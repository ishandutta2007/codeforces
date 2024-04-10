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

const int maxn = 155;
int n;

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

vector<int> a[maxn];

void solve() {
  a[0] = {1};
  a[1] = {0, 1};
  for (int i = 2; i <= n; i++) {
    bool found = false;
    for (int sgn = -1; sgn <= 1; sgn += 2) {
      vector<int> b(i + 1);
      bool ok = true;
      for (int j = 0; j <= i; j++) {
        b[j] = (j <= i - 2 ? a[i - 2][j] : 0) + sgn * (j ? a[i - 1][j - 1] : 0);
        if (abs(b[j]) > 1) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        continue;
      }
      a[i] = b;
      found = true;
      break;
    }
    assert(found);
    if (a[i].back() == -1) {
      for (int j = 0; j <= i; j++) {
        a[i][j] *= -1;
      }
    }
  }
  for (int it = 0; it < 2; it++) {
    int id = n - it;
    printf("%d\n", id);
    for (int i = 0; i <= id; i++) {
      printf("%d ", a[id][i]);
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