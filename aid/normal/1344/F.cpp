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

const int maxn = 2005;
char tmp[100];
int n, k, m;
int xs[maxn][2];
bitset<maxn> a[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    xs[i][0] = 1;
    xs[i][1] = 2;
  }
  m = 0;
  for (int i = 0; i < k; i++) {
    int l;
    scanf("%s%d", tmp, &l);
    if (tmp[0] == 'm') {
      a[m].reset();
      a[m + 1].reset();
      for (int j = 0; j < l; j++) {
        int p;
        scanf("%d", &p);
        p--;
        for (int t = 0; t < 2; t++) {
          for (int it = 0; it < 2; it++) {
            if (xs[p][t] & (1 << it)) {
              a[m + t][2 * p + it] = true;
            }
          }
        }
      }
      scanf("%s", tmp);
      int z = (tmp[0] == 'R' ? 1 : (tmp[0] == 'Y' ? 2 : (tmp[0] == 'B' ? 3 : 0)));
      a[m][2 * n] = (z & 1);
      a[m + 1][2 * n] = ((z >> 1) & 1);
      m += 2;
    } else {
      for (int j = 0; j < l; j++) {
        int p;
        scanf("%d", &p);
        p--;
        if (tmp[0] == 'R' && tmp[1] == 'Y') {
          swap(xs[p][0], xs[p][1]);
        } else if (tmp[0] == 'R' && tmp[1] == 'B') {
          xs[p][1] ^= xs[p][0];
        } else {
          xs[p][0] ^= xs[p][1];
        }
      }
    }
  }
  return true;
}

int bit[maxn];
int ans[maxn];
string s;

void solve() {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < i; j++) {
      if (bit[j] != -1 && a[i][bit[j]]) {
        a[i] ^= a[j];
      }
    }
    if (!a[i].any()) {
      bit[i] = -1;
      continue;
    }
    bit[i] = a[i]._Find_first();
    if (bit[i] >= 2 * n) {
      printf("NO\n");
      return;
    }
    for (int j = 0; j < i; j++) {
      if (a[j][bit[i]]) {
        a[j] ^= a[i];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    ans[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    if (!a[i][2 * n]) {
      continue;
    }
    int p = (bit[i] >> 1), t = (bit[i] & 1);
    ans[p] |= (1 << t);
  }
  s = "";
  for (int i = 0; i < n; i++) {
    s += (ans[i] == 0 ? '.' : (ans[i] == 1 ? 'R' : (ans[i] == 2 ? 'Y' : 'B')));
  }
  printf("YES\n%s\n", s.c_str());
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