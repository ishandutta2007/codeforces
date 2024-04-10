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

const int maxn = 1005, logn = 10;
int n;
int x[maxn][logn][2];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

void solve() {
  for (int i = 0; i < logn; i++) {
    for (int j = 0; j < 2; j++) {
      vector<int> q;
      for (int k = 0; k < n; k++) {
        if (((k >> i) & 1) == j) {
          q.push_back(k);
        }
      }
      if (q.empty()) {
        for (int k = 0; k < n; k++) {
          x[k][i][j] = inf;
        }
        continue;
      }
      printf("%d\n", sz(q));
      for (int k = 0; k < sz(q); k++) {
        printf("%d ", q[k] + 1);
      }
      printf("\n");
      fflush(stdout);
      for (int k = 0; k < n; k++) {
        scanf("%d", &x[k][i][j]);
      }
    }
  }
  printf("-1\n");
  for (int i = 0; i < n; i++) {
    int res = inf;
    for (int j = 0; j < logn; j++) {
      res = min(res, x[i][j][!((i >> j) & 1)]);
    }
    printf("%d ", res);
  }
  printf("\n");
  fflush(stdout);
}

int main() {
  precalc();
  read();
  solve();
#ifdef DEBUG
  eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}