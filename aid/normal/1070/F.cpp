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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

vector<int> x[4];
char tmp[10];

int read() {
  int n;
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < 4; i++) {
    x[i].clear();
  }
  for (int i = 0; i < n; i++) {
    int cur;
    scanf("%s%d", tmp, &cur);
    int id = (tmp[0] - '0') + (tmp[1] - '0') * 2;
    x[id].push_back(cur);
  }
  return true;
}

void solve() {
  for (int i = 0; i < 4; i++) {
    sort(x[i].begin(), x[i].end());
  }
  int a = 0, m = 0;
  int res = 0;
  for (int i = 0; i < sz(x[3]); i++) {
    a++;
    m++;
    res += x[3][i];
  }
  x[3].clear();
  while (!x[1].empty() && !x[2].empty()) {
    a++;
    m += 2;
    res += x[1].back() + x[2].back();
    x[1].pop_back();
    x[2].pop_back();
  }
  while (2 * a >= m + 1) {
    int id = -1;
    for (int i = 0; i < 4; i++) {
      if (x[i].empty()) {
        continue;
      }
      if (id == -1 || x[i].back() > x[id].back()) {
        id = i;
      }
    }
    if (id == -1) {
      break;
    }
    m++;
    res += x[id].back();
    x[id].pop_back();
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