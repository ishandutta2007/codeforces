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

const int maxn = 1005;
int n, k;

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  return true;
}

int g[maxn][maxn];
vector<pair<int, int>> q, nq;

void merge(const pair<int, int> &a, const pair<int, int> &b, int c) {
  for (int i = a.first; i < a.second; ++i) {
    for (int j = b.first; j < b.second; ++j) {
      g[i][j] = c;
    }
  }
}

void solve() {
  q.clear();
  for (int i = 0; i < n; ++i) {
    q.push_back(make_pair(i, i + 1));
  }
  int res = 0;
  while (sz(q) > 1) {
    nq.clear();
    for (int l = 0; l < sz(q); l += k) {
      int r = min(sz(q), l + k);
      for (int i = l; i < r; ++i) {
        for (int j = i + 1; j < r; ++j) {
          merge(q[i], q[j], res);
        }
      }
      nq.push_back(make_pair(q[l].first, q[r - 1].second));
    }
    swap(q, nq);
    ++res;
  }
  printf("%d\n", res);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      printf("%d ", g[i][j] + 1);
    }
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