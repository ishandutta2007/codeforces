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

const int maxn = (int) 3e5 + 5;
int a, b, c;
int n;
vector<int> x[3];
char tmp[10];

int read() {
  if (scanf("%d%d%d%d", &a, &b, &c, &n) < 4) {
    return false;
  }
  x[0].clear();
  x[1].clear();
  x[2].clear();
  for (int i = 0; i < n; i++) {
    int val;
    scanf("%d%s", &val, tmp);
    if (tmp[0] == 'U') {
      x[0].push_back(val);
    } else {
      x[1].push_back(val);
    }
  }
  return true;
}

void solve() {
  int cnt = 0;
  long long cost = 0;
  for (int it = 0; it < 3; it++) {
    int &need = (it == 0 ? a : (it == 1 ? b : c));
    sort(x[it].begin(), x[it].end(), greater<int>());
    while (need && !x[it].empty()) {
      need--;
      cnt++;
      cost += x[it].back();
      x[it].pop_back();
    }
    if (it < 2) {
      for (int i = 0; i < sz(x[it]); i++) {
        x[2].push_back(x[it][i]);
      }
    }
  }
  printf("%d %lld\n", cnt, cost);
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