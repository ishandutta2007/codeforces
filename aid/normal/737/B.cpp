#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
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
int n, a, b, k;
char c[maxn];

int read() {
  if (scanf("%d%d%d%d", &n, &a, &b, &k) < 4) {
    return false;
  }
  scanf("%s", c);
  return true;
}

void solve() {
  vector<int> ans;
  int l = 0;
  c[n] = '1';
  for (int i = 0; i <= n; i++) {
    if (c[i] == '1') {
      int r = i;
      while (l + b <= r) {
        ans.push_back(l + b - 1);
        l += b;
      }
      l = i + 1;
    }
  }
  int res = max(0, sz(ans) - a + 1);
  ans.resize(res);
  printf("%d\n", res);
  for (int i = 0; i < res; i++) {
    printf("%d ", ans[i] + 1);
  }
  printf("\n");
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}