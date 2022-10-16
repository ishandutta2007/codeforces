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
int x, y;

bool read() {
  if (scanf("%d%d%d", &n, &x, &y) < 3) {
    return false;
  }
  return true;
}

int xs[maxn], ys[maxn];
int k;
int a[4][maxn];
int b[4][maxn];
pair<int, int> ps[4];

pair<int, int> ask(int i) {
  printf("+ %d\n", i + 1);
  fflush(stdout);
  int px = x, py = y;
  scanf("%d%d", &x, &y);
  return make_pair(x - px, y - py);
}

pair<int, int> get(int t, int i) {
  return make_pair(b[t][i] * (b[t][i] - 1) / 2,
                   (i >= 2 ? b[t][i - 2] * b[t][i - 1] : 0) +
                   ((i >= 1  && i + 1 < n) ? b[t][i - 1] * b[t][i + 1] : 0) +
                   (i + 2 < n ? b[t][i + 1] * b[t][i + 2] : 0));
}

void solve() {
  for (int i = n - 2; i >= 0; i--) {
    auto p = ask(i);
    xs[i] = p.first;
    ys[i] = p.second;
  }
  k = 0;
  for (int a0 = 0; a0 <= n; a0++) {
    if (a0 * (a0 - 1) / 2 != xs[0]) {
      continue;
    }
    for (int a1 = 0; a1 <= n; a1++) {
      if (a1 * (a1 - 1) / 2 != xs[1]) {
        continue;
      }
      a[k][0] = a0;
      a[k][1] = a1;
      bool ok = true;
      for (int i = 2; i < n; i++) {
        int cur = ys[i - 2];
        if (i - 2 >= 2) {
          cur -= a[k][i - 4] * a[k][i - 3];
        }
        if (i - 2 >= 1) {
          cur -= a[k][i - 3] * (a[k][i - 1] + 1);
        }
        if (cur < 0 || cur % (a[k][i - 1] + 1)) {
          ok = false;
          break;
        }
        cur /= a[k][i - 1] + 1;
        if (i < n - 1) {
          cur--;
          if (cur * (cur - 1) / 2 != xs[i]) {
            ok = false;
            break;
          }
        }
        a[k][i] = cur;
      }
      if (!ok) {
        continue;
      }
      k++;
    }
  }
  {
    int kk = 0;
    for (int t = 0; t < k; t++) {
      for (int i = 0; i < n - 1; i++) {
        b[t][i] = a[t][i] + 1;
      }
      b[t][n - 1] = a[t][n - 1];
      int curx = 0, cury = 0;
      for (int i = 0; i < n; i++) {
        curx += b[t][i] * (b[t][i] - 1) * (b[t][i] - 2) / 6;
      }
      for (int i = 0; i + 2 < n; i++) {
        cury += b[t][i] * b[t][i + 1] * b[t][i + 2];
      }
      if (curx == x && cury == y) {
        for (int i = 0; i < n; i++) {
          a[kk][i] = a[t][i];
          b[kk][i] = b[t][i];
        }
        kk++;
      }
    }
    k = kk;
  }
  for (int i = 0; i < n; i++) {
    bool ok = true;
    for (int j = 0; j < k && ok; j++) {
      ps[j] = get(j, i);
      for (int jj = 0; jj < j; jj++) {
        if (ps[jj] == ps[j]) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      auto p = ask(i);
      for (int j = 0; j < k; j++) {
        if (p == ps[j]) {
          printf("! ");
          for (int ii = 0; ii < n; ii++) {
            printf("%d ", a[j][ii]);
          }
          printf("\n");
          fflush(stdout);
          return;
        }
      }
      assert(false);
    }
  }
  assert(false);
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