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

void precalc() {
}

const int maxn = 8005;
char tmp[maxn];
int n;
bitset<maxn> g[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    for (int j = 0; j < n / 4; j++) {
      int x = (isdigit(tmp[j]) ? tmp[j] - '0' : 10 + tmp[j] - 'A');
      for (int k = 0; k < 4; k++) {
        g[i][j * 4 + k] = ((x >> (3 - k)) & 1);
      }
    }
  }
  return true;
}

const int C = 614;
int deg[maxn];
vector<int> good, bad;
vector<int> gus, bus, us;

void mySort(vector<int>::iterator l, vector<int>::iterator r) {
  int k = r - l;
  if (k <= 1) {
    return;
  }
  int p = rnd(k);
  int v = *(l + p);
  const auto &gv = g[v];
  auto m0 = l, m1 = l;
  for (auto it = l; it != r; it++) {
    if (*it != v && !gv[*it]) {
      swap(*it, *m0);
      if (m1 == m0) {
        m1++;
      }
      m0++;
    }
    if (*it == v) {
      swap(*it, *m1);
      m1++;
    }
  }
  mySort(l, m0);
  mySort(m1, r);
}

bool cmp(int v, int u) {
  return g[v][u];
}

void solve() {
  {
    int t = 0;
    for (int v = 0; v < n; v++) {
      deg[v] = g[v].count();
      if (deg[v] < deg[t]) {
        t = v;
      }
    }
    good.clear();
    bad.clear();
    for (int v = 0; v < n; v++) {
      if (!g[t][v]) {
        good.push_back(v);
      } else {
        bad.push_back(v);
      }
    }
    mySort(good.begin(), good.end());
  }
  long long res = 0;
  for (int v = 0; v < n; v++) {
    gus.clear();
    for (auto u : good) {
      if (u == v) {
        continue;
      }
      if (g[v][u]) {
        res++;
        continue;
      }
      gus.push_back(u);
    }
    bus.clear();
    for (auto u : bad) {
      if (u == v) {
        continue;
      }
      if (g[v][u]) {
        res++;
        continue;
      }
      bus.push_back(u);
    }
    mySort(bus.begin(), bus.end());
    us.resize(sz(gus) + sz(bus));
    merge(gus.begin(), gus.end(), bus.begin(), bus.end(), us.begin(), cmp);
    bool b = false;
    for (int i = 0; i < sz(us); i++) {
      int u = us[i];
      int need = n - i - 1;
      assert(deg[u] <= need);
      if (deg[u] == need) {
        if (b) {
          res += 3;
        } else {
          res += C * n;
        }
      } else {
        res += 2;
        b = true;
      }
    }
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