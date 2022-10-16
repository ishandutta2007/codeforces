#ifdef DEBUG
//#define _GLIBCXX_DEBUG
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

const int sigma = 20;
vector<pair<int, int>> tosort;

void precalc() {
  tosort.clear();
  for (int i = 0; i < (1 << sigma); ++i) {
    tosort.push_back(make_pair(__builtin_popcount(i), i));
  }
  sort(tosort.begin(), tosort.end());
}

const int maxn = (int) 1e5 + 5;
char tmp[maxn];
int n;
string s, t;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  scanf("%s", tmp);
  t = tmp;
  return true;
}

int g[sigma];
int msk, used, inside;

void getComp(int v) {
  used |= (1 << v);
  for (int u = 0; u < sigma; ++u) {
    if (!(used & (1 << u)) && ((g[v] & (1 << u)) || (g[u] & (1 << v)))) {
      getComp(u);
    }
  }
}

bool getCycle(int v) {
  used |= (1 << v);
  inside |= (1 << v);
  int gg = (g[v] & ~msk & ~(1 << v));
  if (gg & inside) {
    return true;
  }
  while (gg & ~used) {
    int u = __builtin_ctz(gg & ~used);
    if (getCycle(u)) {
      return true;
    }
  }
  inside &= ~(1 << v);
  return false;
}

void solve() {
  for (int i = 0; i < sigma; ++i) {
    g[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    g[s[i] - 'a'] |= (1 << (t[i] - 'a'));
  }
  int res = sigma;
  {
    used = 0;
    for (int i = 0; i < sigma; ++i) {
      if (!(used & (1 << i))) {
        res--;
        getComp(i);
      }
    }
  }
  for (int it = 0; it < sz(tosort); ++it) {
    msk = tosort[it].second;
    used = 0;
    inside = 0;
    bool c = false;
    for (int i = 0; i < sigma; ++i) {
      if (!(used & (1 << i)) && getCycle(i)) {
        c = true;
        break;
      }
    }
    if (!c) {
      res += tosort[it].first;
      break;
    }
  }
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}