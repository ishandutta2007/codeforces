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
int q;
int qs[maxn][2];
char tmp[10];

bool read() {
  if (scanf("%d", &q) < 1) {
    return false;
  }
  for (int i = 0; i < q; i++) {
    int x;
    scanf("%s%d", tmp, &x);
    qs[i][0] = (tmp[0] == '+' ? 1 : -1);
    qs[i][1] = x;
  }
  return true;
}

int n;
int a[maxn];
int alive[maxn];
long long fen[maxn];

void add(int i, int val) {
  for (; i < n; i |= i + 1) {
    fen[i] += val;
  }
}

int getPos(long long &sum) {
  int res = 0;
  int maxb = 31 - __builtin_clz(n);
  for (int b = maxb; b >= 0; b--) {
    int pos = res + (1 << b) - 1;
    if (pos < n && fen[pos] <= sum) {
      sum -= fen[pos];
      res += (1 << b);
    }
  }
  return res;
}

void solve() {
  n = 0;
  for (int qq = 0; qq < q; qq++) {
    if (qs[qq][0] == 1) {
      a[n++] = qs[qq][1];
    }
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    alive[i] = 0;
  }
  for (int qq = 0; qq < q; qq++) {
    int x = qs[qq][1];
    int pos = lower_bound(a, a + n, x) - a;
    if (qs[qq][0] == 1) {
      qs[qq][1] = pos + alive[pos];
      alive[pos]++;
    } else {
      alive[pos]--;
      qs[qq][1] = pos + alive[pos];
    }
  }
  for (int i = 0; i < n; i++) {
    fen[i] = 0;
  }
  int k = 0;
  for (int qq = 0; qq < q; qq++) {
    {
      int pos = qs[qq][1];
      add(pos, qs[qq][0] * a[pos]);
      k += qs[qq][0];
    }
    {
      long long sum = 0;
      int pos = 0;
      int res = k;
      while (pos < n) {
        long long rem = 3 * sum;
        pos = getPos(rem);
        sum = 3 * sum - rem;
        if (pos < n) {
          if (a[pos] > 2 * sum) {
            res--;
          }
          sum += a[pos];
          pos++;
        }
      }
      printf("%d\n", res);
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