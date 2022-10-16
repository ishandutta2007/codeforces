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
int n;
int p[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  return true;
}

int used[maxn];
int col[maxn];

void solve() {
  for (int s = 0; s < n; s++) {
    if (p[s] == s) {
      printf("YES\n");
      for (int i = 0; i < n; i++) {
        if (i == s) {
          continue;
        }
        printf("%d %d\n", i + 1, s + 1);
      }
      return;
    }
  }
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  bool bad = false;
  int s = -1;
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    int v = i;
    int k = 0;
    while (!used[v]) {
      used[v] = true;
      col[v] = (k & 1);
      k++;
      v = p[v];
    }
    if (k & 1) {
      bad = true;
      break;
    }
    if (k == 2) {
      s = i;
    }
  }
  if (s == -1) {
    bad = true;
  }
  if (bad) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  printf("%d %d\n", s + 1, p[s] + 1);
  for (int i = 0; i < n; i++) {
    if (i == s || i == p[s]) {
      continue;
    }
    int v = i, u = (col[i] == col[s] ? s : p[s]);
    printf("%d %d\n", v + 1, u + 1);
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