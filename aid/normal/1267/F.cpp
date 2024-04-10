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
int n, m, ka, kb;
int a[maxn], b[maxn];

bool read() {
  if (scanf("%d%d%d%d", &n, &m, &ka, &kb) < 4) {
    return false;
  }
  for (int i = 0; i < ka; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for (int i = 0; i < kb; i++) {
    scanf("%d", &b[i]);
    b[i]--;
  }
  return true;
}

int deg[maxn];
vector<pair<int, int>> ans;
set<int> ls;

void solve() {
  if (ka > m - 1 || kb > n - 1) {
    printf("No\n");
    return;
  }
  while (ka < m - 1) {
    a[ka++] = 0;
  }
  while (kb < n - 1) {
    b[kb++] = n;
  }
  for (int i = 0; i < n + m; i++) {
    deg[i] = 1;
  }
  for (int i = 0; i < ka; i++) {
    deg[a[i]]++;
  }
  for (int i = 0; i < kb; i++) {
    deg[b[i]]++;
  }
  ans.clear();
  ls.clear();
  for (int i = 0; i < n + m; i++) {
    if (deg[i] == 1) {
      ls.insert(i);
    }
  }
  int pa = 0, pb = 0;
  for (int it = 0; it < n + m - 1; it++) {
    int v = *ls.begin();
    ls.erase(ls.begin());
    int u;
    if (it == n + m - 2) {
      u = *ls.begin();
      ls.erase(ls.begin());
    } else {
      if (v < n) {
        u = b[pb++];
      } else {
        u = a[pa++];
      }
    }
    ans.push_back(make_pair(v, u));
    deg[v]--;
    deg[u]--;
    if (deg[u] == 1) {
      ls.insert(u);
    }
  }
  printf("Yes\n");
  for (int i = 0; i < sz(ans); i++) {
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
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