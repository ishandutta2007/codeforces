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

const int maxn = (int) 4e5 + 5, logn = 20;
int qs;

int read() {
  if (scanf("%d", &qs) < 1) {
    return false;
  }
  return true;
}

int p[maxn][logn], mx[maxn][logn], q[maxn][logn];
long long sum[maxn][logn];

void solve() {
  int n = 1;
  for (int i = 0; i < logn; i++) {
    p[0][i] = 0;
    mx[0][i] = 0;
    q[0][i] = -1;
    sum[0][i] = 0;
  }
  int lst = 0;
  for (int qq = 0; qq < qs; qq++) {
    int t;
    long long x, y;
    scanf("%d%lld%lld", &t, &x, &y);
    if (t == 1) {
      int v = n++;
      int u = (x ^ lst);
      u--;
      int w = (y ^ lst);
      p[v][0] = u;
      mx[v][0] = w;
      if (mx[u][0] >= w) {
        q[v][0] = u;
        sum[v][0] = mx[u][0];
      } else {
        int cur = u;
        for (int i = logn - 1; i >= 0; i--) {
          if (mx[cur][i] < w) {
            cur = p[cur][i];
          }
        }
        if (mx[cur][0] < w) {
          q[v][0] = -1;
          sum[v][0] = 0;
        } else {
          q[v][0] = cur;
          sum[v][0] = mx[cur][0];
        }
      }
      for (int i = 1; i < logn; i++) {
        p[v][i] = p[p[v][i - 1]][i - 1];
        mx[v][i] = max(mx[v][i - 1], mx[p[v][i - 1]][i - 1]);
        if (q[v][i - 1] != -1) {
          q[v][i] = q[q[v][i - 1]][i - 1];
          sum[v][i] = sum[v][i - 1] + sum[q[v][i - 1]][i - 1];
        } else {
          q[v][i] = -1;
          sum[v][i] = sum[v][i - 1];
        }
      }
    } else {
      int v = (x ^ lst);
      v--;
      long long w = (y ^ lst);
      if (mx[v][0] > w) {
        printf("0\n");
        lst = 0;
        continue;
      }
      long long curw = mx[v][0];
      int res = 1;
      for (int i = logn - 1; i >= 0; i--) {
        if (q[v][i] == -1) {
          continue;
        }
        if (curw + sum[v][i] <= w) {
          curw += sum[v][i];
          res += (1 << i);
          v = q[v][i];
        }
      }
      printf("%d\n", res);
      lst = res;
    }
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