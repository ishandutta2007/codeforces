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

const int maxn = (int) 4e5 + 5;
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

const int maxb = 26;
pair<int, int> b[maxn], c[maxn];
int sum[maxn];

int get(int l, int r, int bb) {
  int res = sum[r] - sum[l];
  if (!bb) {
    res = r - l - res;
  }
  return res;
}

void solve() {
  int res = 0;
  for (int bit = 0; bit < maxb; bit++) {
    if (!bit) {
      for (int i = 0; i < n; i++) {
        b[i] = make_pair(0, i);
      }
    } else {
      int pos = 0;
      for (int i = 0; i < n; i++) {
        int cur = a[b[i].second];
        if (!(cur & (1 << (bit - 1)))) {
          c[pos++] = make_pair((cur & ((1 << bit) - 1)), b[i].second);
        }
      }
      for (int i = 0; i < n; i++) {
        int cur = a[b[i].second];
        if (cur & (1 << (bit - 1))) {
          c[pos++] = make_pair((cur & ((1 << bit) - 1)), b[i].second);
        }
      }
      for (int i = 0; i < n; i++) {
        b[i] = c[i];
      }
    }
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
      sum[i + 1] = sum[i] + ((a[b[i].second] >> bit) & 1);
    }
    int cnt = 0;
    int pos = n;
    for (int i = 0; i < n; i++) {
      int cur = b[i].first;
      while (pos > 0 && b[pos - 1].first + cur >= (1 << bit)) {
        pos--;
      }
      int bb = ((a[b[i].second] >> bit) & 1);
      cnt += get(0, pos, (bb ^ 1));
      cnt += get(pos, n, bb);
      if ((a[b[i].second] * 2) & (1 << bit)) {
        cnt += 3;
      }
      cnt %= 4;
    }
    cnt /= 2;
    if (cnt & 1) {
      res ^= (1 << bit);
    }
  }
  printf("%d\n", res);
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