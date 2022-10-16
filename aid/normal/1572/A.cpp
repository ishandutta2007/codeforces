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
int n;
int deg[maxn];
vector<int> g[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &deg[i]);
    for (int j = 0; j < deg[i]; ++j) {
      int v;
      scanf("%d", &v);
      --v;
      g[v].push_back(i);
    }
  }
  return true;
}

set<int> st;

void solve() {
  st.clear();
  for (int i = 0; i < n; ++i) {
    if (!deg[i]) {
      st.insert(i);
    }
  }
  int cur = 0;
  int need = n;
  int res = 1;
  while (need) {
    if (st.empty()) {
      printf("-1\n");
      return;
    }
    auto it = st.lower_bound(cur);
    if (it == st.end()) {
      ++res;
      it = st.begin();
    }
    cur = *it;
    --need;
    st.erase(it);
    for (int i = 0; i < sz(g[cur]); ++i) {
      int v = g[cur][i];
      --deg[v];
      if (!deg[v]) {
        st.insert(v);
      }
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