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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 2e5 + 5;
int n;
int a[maxn], b[maxn];
pair<int, int> tosort[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &tosort[i].first);
    tosort[i].second = i;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    b[i]--;
  }
  return true;
}

int del[maxn];
int pos[3];

void solve() {
  sort(tosort, tosort + n);
  for (int i = 0; i < n; i++) {
    del[i] = false;
  }
  for (int i = 0; i < 3; i++) {
    pos[i] = 0;
  }
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; qq++) {
    int c;
    scanf("%d", &c);
    c--;
    int &p = pos[c];
    int res = -1;
    while (p < n) {
      int id = tosort[p].second;
      if (del[id] || (a[id] != c && b[id] != c)) {
        p++;
        continue;
      }
      res = tosort[p].first;
      del[id] = true;
      break;
    }
    printf("%d ", res);
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