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

const int maxn = (int) 1e5 + 5;
int n, q;
int a[maxn];
int qs[maxn][2];
char tmp[10];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < q; i++) {
    scanf("%s%d\n", tmp, &qs[i][0]);
    qs[i][1] = (tmp[0] == '>');
  }
  return true;
}

pair<int, int> tosort[maxn];
pair<int, int> qsrt[maxn];
int s[maxn];

void solve() {
  for (int i = 0; i < q; i++) {
    if (qs[i][0] > 0) {
      if (!qs[i][1]) {
        qs[i][0]--;
      }
    } else if (qs[i][0] < 0) {
      if (qs[i][1]) {
        qs[i][0]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(abs(a[i]), i);
  }
  sort(tosort, tosort + n);
  for (int i = 0; i < q; i++) {
    qsrt[i] = make_pair(abs(qs[i][0]), i);
  }
  sort(qsrt, qsrt + q);
  s[q] = 0;
  for (int i = q - 1; i >= 0; i--) {
    s[i] = s[i + 1];
    if (qs[i][0] > 0) {
      if (!qs[i][1]) {
        s[i] ^= 1;
      }
    } else if (qs[i][0] < 0) {
      if (qs[i][1]) {
        s[i] ^= 1;
      }
    }
  }
  int lst = -1;
  for (int it = 0, p = 0; it < n; it++) {
    int i = tosort[it].second;
    while (p < q && qsrt[p].first < tosort[it].first) {
      lst = max(lst, qsrt[p].second);
      p++;
    }
    if (lst != -1) {
      if (qs[lst][1]) {
        if (a[i] > qs[lst][0]) {
          a[i] *= -1;
        }
      } else {
        if (a[i] < qs[lst][0]) {
          a[i] *= -1;
        }
      }
    }
    if (s[lst + 1]) {
      a[i] *= -1;
    }
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
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}