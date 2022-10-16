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
int a[maxn], b[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  return true;
}

vector<int> bs[maxn];

void solve() {
  for (int i = 0; i < k; i++) {
    bs[i].clear();
  }
  for (int i = 0; i < n; i++) {
    bs[a[i]].push_back(b[i]);
  }
  int need = 0;
  vector<int> all;
  for (int i = 0; i < k; i++) {
    if (bs[i].empty()) {
      need++;
      continue;
    }
    sort(bs[i].begin(), bs[i].end());
    for (int j = 0; j + 1 < sz(bs[i]); j++) {
      all.push_back(bs[i][j]);
    }
  }
  sort(all.begin(), all.end());
  long long res = 0;
  for (int i = 0; i < need; i++) {
    res += all[i];
  }
  printf("%lld\n", res);
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