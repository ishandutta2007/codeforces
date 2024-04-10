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

const int maxn = (int) 2e5 + 5;
int n, m;
int a[maxn];
int qs[maxn][2];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &qs[i][0], &qs[i][1]);
    qs[i][1]--;
  }
  return true;
}

int fen[maxn];

void add(int i, int x) {
  for (; i < n; i |= i + 1) {
    fen[i] += x;
  }
}

int getKth(int k) {
  int i = 0;
  for (int bit = 20; bit >= 0; bit--) {
    int j = i + (1 << bit) - 1;
    if (j < n && fen[j] <= k) {
      k -= fen[j];
      i = j + 1;
    }
  }
  return i;
}

pair<int, int> tosort[maxn];
int ans[maxn];
vector<pair<int, int>> qqs[maxn];

void solve() {
  for (int i = 0; i <= n; i++) {
    qqs[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int k = qs[i][0], pos = qs[i][1];
    qqs[k].push_back(make_pair(pos, i));
  }
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(-a[i], i);
  }
  sort(tosort, tosort + n);
  for (int i = 0; i < n; i++) {
    fen[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    int id = tosort[i - 1].second;
    add(id, 1);
    for (int j = 0; j < sz(qqs[i]); j++) {
      int pos = qqs[i][j].first, q = qqs[i][j].second;
      ans[q] = a[getKth(pos)];
    }
  }
  for (int i = 0; i < m; i++) {
    printf("%d\n", ans[i]);
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