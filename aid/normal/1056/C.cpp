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
int n, m;
int a[maxn];
int p[maxn];
int used[maxn];
int who;

bool read() {
  int m;
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  n *= 2;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    p[i] = -1;
    used[i] = false;
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    p[v] = u;
    p[u] = v;
  }
  scanf("%d", &who);
  who--;
  return true;
}

void solve() {
  int lst = -1;
  for (int iter = 0; iter < n; iter++, who = !who) {
    if (!who) {
      int x = -1;
      if (lst != -1 && p[lst] != -1 && !used[p[lst]]) {
        x = p[lst];
      }
      if (x != -1) {
        used[x] = true;
        printf("%d\n", x + 1);
        fflush(stdout);
        continue;
      }
      for (int i = 0; i < n && x == -1; i++) {
        if (!used[i] && p[i] != -1 && a[i] >= a[p[i]]) {
          x = i;
        }
      }
      if (x != -1) {
        used[x] = true;
        printf("%d\n", x + 1);
        fflush(stdout);
        continue;
      }
      for (int i = 0; i < n; i++) {
        if (!used[i] && (x == -1 || a[i] > a[x])) {
          x = i;
        }
      }
      used[x] = true;
      printf("%d\n", x + 1);
      fflush(stdout);
    } else {
      int x;
      scanf("%d", &x);
      x--;
      used[x] = true;
      lst = x;
    }
  }
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