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

const int maxn = (int) 1e6 + 5;
int n;
long long a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  return true;
}

const int maxb = 60;
vector<pair<int, int>> st[2];
vector<pair<int, int>> stb[2][maxb];
vector<int> sums[2][maxb];
long long res;
int cur;

int get1(int t, int p, int b) {
  int i = lower_bound(stb[t][b].begin(), stb[t][b].end(), make_pair(p, -1)) - stb[t][b].begin() - 1;
  if (i < 0) {
    return 0;
  }
  return sums[t][b][i] + min(p, stb[t][b][i].second) - stb[t][b][i].first;
}

int get(int t, int l, int r, int b) {
  return get1(t, r, b) - get1(t, l, b);
}

void solve() {
  for (int t = 0; t < 2; ++t) {
    st[t].clear();
    for (int b = 0; b < maxb; ++b) {
      stb[t][b].clear();
      sums[t][b].clear();
      sums[t][b].push_back(0);
    }
  }
  res = 0;
  cur = 0;
  for (int i = 0; i < n; ++i) {
    int b = __builtin_popcountll(a[i]);
    for (int t = 0; t < 2; ++t) {
      while (!st[t].empty() && (a[st[t].back().first] > a[i]) != t) {
        int r = st[t].back().first + 1;
        int l = (sz(st[t]) > 1 ? st[t][sz(st[t]) - 2].first + 1 : 0);
        int bb = st[t].back().second;
        cur -= get(!t, l, r, bb);
        st[t].pop_back();
        stb[t][bb].pop_back();
        sums[t][bb].pop_back();
      }
      int r = i + 1;
      int l = (st[t].empty() ? 0 : st[t].back().first + 1);
      cur += get(!t, l, r, b);
      st[t].push_back(make_pair(i, b));
      stb[t][b].push_back(make_pair(l, r));
      int sum = sums[t][b].back();
      sums[t][b].push_back(sum + r - l);
    }
    res += cur;
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