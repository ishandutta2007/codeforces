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

const int maxx = 7005;
int sqfree[maxx];
bitset<maxx> divs[maxx];
bitset<maxx> muls[maxx];

void precalc() {
  for (int x = 1; x < maxx; x++) {
    divs[x].reset();
    muls[x].reset();
  }
  for (int x = 1; x < maxx; x++) {
    int y = x;
    bool ok = true;
    for (int d = 2; d * d <= y; d++) {
      if (!(y % d)) {
        y /= d;
        if (!(y % d)) {
          ok = false;
          break;
        }
      }
    }
    sqfree[x] = ok;
  }
  for (int x = 1; x < maxx; x++) {
    for (int y = x; y < maxx; y += x) {
      divs[y][x] = true;
      if (sqfree[y / x]) {
        muls[x][y] = true;
      }
    }
  }
}

const int maxn = (int) 1e5 + 5;
int n, q;

bool read() {
  if (scanf("%d%d", &n, &q) < 1) {
    return false;
  }
  return true;
}

bitset<maxx> bs[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    bs[i].reset();
  }
  string ans;
  for (int qq = 0; qq < q; qq++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int pos, x;
      scanf("%d%d", &pos, &x);
      pos--;
      bs[pos] = divs[x];
    } else if (t == 2) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      a--;
      b--;
      c--;
      bs[a] = (bs[b] ^ bs[c]);
    } else if (t == 3) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      a--;
      b--;
      c--;
      bs[a] = (bs[b] & bs[c]);
    } else {
      int pos, x;
      scanf("%d%d", &pos, &x);
      pos--;
      ans += (char) ('0' + ((bs[pos] & muls[x]).count() & 1));
    }
  }
  printf("%s\n", ans.c_str());
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