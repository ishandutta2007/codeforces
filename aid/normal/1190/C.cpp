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
int n, k;
string s;
char tmp[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

int r[2][maxn], l[2][maxn];

bool check1() {
  for (int t = 0; t < 2; t++) {
    int ll = l[t][0], rr = r[t][n];
    if (rr - ll + 1 <= k) {
      return true;
    }
  }
  return false;
}

bool check2() {
  for (int t = 0; t < 2; t++) {
    int ll = l[t][0], rr = r[t][n];
    for (int i = 0; i + k <= n; i++) {
      int curl = ll, curr = rr;
      if (i <= curl && curl < i + k) {
        curl = l[t][i + k];
      }
      if (i <= curr && curr < i + k) {
        curr = r[t][i];
      }
      if (curr - curl + 1 > k) {
        return false;
      }
    }
  }
  return true;
}

void solve() {
  for (int t = 0; t < 2; t++) {
    char need = (char) ('0' + t);
    r[t][0] = -1;
    for (int i = 0; i < n; i++) {
      r[t][i + 1] = (s[i] == need ? i : r[t][i]);
    }
    l[t][n] = -1;
    for (int i = n - 1; i >= 0; i--) {
      l[t][i] = (s[i] == need ? i : l[t][i + 1]);
    }
  }
  if (check1()) {
    printf("tokitsukaze\n");
  } else if (check2()) {
    printf("quailty\n");
  } else {
    printf("once again\n");
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