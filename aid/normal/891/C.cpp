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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 5e5 + 5;
int n, m, q;
pair<pair<int, int>, int> es[maxn];
vector<int> wes[maxn];
vector< pair<int, int> > wqs[maxn];
int ans[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < maxn; i++) {
    wes[i].clear();
    wqs[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    v--;
    u--;
    es[i] = make_pair(make_pair(v, u), w);
    wes[w].push_back(i);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      int id;
      scanf("%d", &id);
      id--;
      wqs[es[id].second].push_back(make_pair(i, id));
    }
    ans[i] = true;
  }
  return true;
}

int p[maxn], ts[maxn];
vector< pair<int, int> > st;

int get(int x) {
  return x == p[x] ? x : get(p[x]);
}

bool unite(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y) {
    return false;
  }
  if (ts[x] < ts[y]) {
    swap(x, y);
  }
  p[y] = x;
  ts[x] += ts[y];
  st.push_back(make_pair(x, y));
  return true;
}

void rollback() {
  assert(!st.empty());
  int x = st.back().first, y = st.back().second;
  st.pop_back();
  p[y] = y;
  ts[x] -= ts[y];
}

void solve() {
  st.clear();
  for (int i = 0; i < n; i++) {
    p[i] = i;
    ts[i] = 1;
  }
  for (int x = 0; x < maxn; x++) {
    for (int j = 0; j < sz(wqs[x]);) {
      int i = j;
      int id = wqs[x][i].first;
      while (j < sz(wqs[x]) && wqs[x][j].first == id) {
        j++;
      }
      int s = sz(st);
      for (int k = i; k < j && ans[id]; k++) {
        if (!unite(es[wqs[x][k].second].first.first, es[wqs[x][k].second].first.second)) {
          ans[id] = false;
        }
      }
      while (sz(st) > s) {
        rollback();
      }
    }
    for (int i = 0; i < sz(wes[x]); i++) {
      unite(es[wes[x][i]].first.first, es[wes[x][i]].first.second);
    }
  }
  for (int i = 0; i < q; i++) {
    printf(ans[i] ? "YES\n" : "NO\n");
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