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

const int maxn = (int) 1e5 + 5;
int n;
vector<int> g[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

void solve() {
  int root = -1;
  vector<int> leaves;
  for (int i = 0; i < n; i++) {
    if (sz(g[i]) >= 3) {
      if (root != -1) {
        printf("No\n");
        return;
      }
      root = i;
    } else if (sz(g[i]) == 1) {
      leaves.push_back(i);
    }
  }
  printf("Yes\n");
  if (root == -1) {
    assert(sz(leaves) == 2);
    printf("1\n%d %d\n", leaves[0] + 1, leaves[1] + 1);
    return;
  }
  printf("%d\n", sz(leaves));
  for (int i = 0; i < sz(leaves); i++) {
    printf("%d %d\n", root + 1, leaves[i] + 1);
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