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
int n, c;
int x[maxn];

int read() {
  if (scanf("%d%d", &c, &n) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  return true;
}

int st[maxn];
int p[maxn];

void solve() {
  sort(x, x + n, greater<int>());
  x[n] = 1;
  int pos = n;
  n++;
  while (pos > 0 && x[pos] >= x[pos - 1]) {
    swap(x[pos], x[pos - 1]);
    pos--;
  }
  int m = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    p[i] = -1;
  }
  while (true) {
    int l = m ? st[m - 1] + 1 : 0;
    int id = lower_bound(x + l, x + n, c - sum, greater<int>()) - x;
    if (id == n) {
      break;
    }
    p[id] = m;
    st[m++] = id;
    sum += x[id];
  }
  /*for (int i = 0; i < m; i++) {
    eprintf("%d ", x[st[i]]);
  }
  eprintf("\n");*/
  if (sum < c) {
    printf("%d\n", x[pos]);
    return;
  }
  while (x[pos] < c) {
    x[pos]++;
    if (p[pos] != -1) {
      sum++;
    }
    while (pos > 0 && x[pos] >= x[pos - 1]) {
      swap(x[pos], x[pos - 1]);
      if (p[pos] != -1 && p[pos - 1] == -1) {
        st[p[pos]]--;
        swap(p[pos], p[pos - 1]);
      }
      pos--;
    }
    if (sum > c) {
      p[st[m - 1]] = -1;
      m--;
      sum -= x[st[m]];
    }
    while (true) {
      int l = m ? st[m - 1] + 1 : 0;
      int id = lower_bound(x + l, x + n, c - sum, greater<int>()) - x;
      if (id == n) {
        break;
      }
      p[id] = m;
      st[m++] = id;
      sum += x[id];
    }
    /*for (int i = 0; i < m; i++) {
      eprintf("%d ", x[st[i]]);
    }
    eprintf("\n");*/
    if (sum < c) {
      printf("%d\n", x[pos]);
      return;
    }
  }
  printf("Greed is good\n");
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