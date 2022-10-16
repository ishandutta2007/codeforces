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
int n;
long long k;
vector<int> g[maxn];

bool read() {
  if (scanf("%d%lld", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

int ts[maxn];

void getTs(int v, int p) {
  ts[v] = 1;
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    getTs(u, v);
    ts[v] += ts[u];
  }
}

int cnt[maxn];
int a[maxn];
vector<int> *vs[maxn];
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> ans;

void dfs(int v, int p) {
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs(u, v);
  }
  while (!pq.empty()) {
    pq.pop();
  }
  {
    vs[v] = new vector<int>(1, v);
    pq.push(make_pair(1, v));
  }
  int sum = 1;
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    if (!vs[u]->empty()) {
      pq.push(make_pair(sz(*vs[u]), u));
      sum += sz(*vs[u]);
    }
  }
  while (sum > a[v]) {
    assert(!pq.empty());
    int x = pq.top().second;
    pq.pop();
    assert(!pq.empty());
    int y = pq.top().second;
    pq.pop();
    ans.push_back(make_pair(vs[x]->back(), vs[y]->back()));
    vs[x]->pop_back();
    vs[y]->pop_back();
    sum -= 2;
    if (!vs[x]->empty()) {
      pq.push(make_pair(sz(*vs[x]), x));
    }
    if (!vs[y]->empty()) {
      pq.push(make_pair(sz(*vs[y]), y));
    }
  }
  if (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    while (!pq.empty()) {
      int w = pq.top().second;
      pq.pop();
      for (int i = 0; i < sz(*vs[w]); ++i) {
        vs[u]->push_back((*vs[w])[i]);
      }
      delete vs[w];
    }
    vs[v] = vs[u];
  }
}

void solve() {
  getTs(0, -1);
  long long cur = 0, mx = 0;
  for (int i = 0; i <= n; ++i) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    cur += (ts[i] & 1);
    int x = min(ts[i], n - ts[i]);
    mx += x;
    ++cnt[x];
  }
  if (k < cur || k > mx || (k & 1) != (cur & 1)) {
    printf("NO\n");
    return;
  }
  int c[2] = {n - (int) cur, (int) cur};
  c[0] -= cnt[0];
  c[1] -= cnt[1];
  for (int i = 2; i <= n; ++i) {
    if (cur + c[i & 1] * 2 >= k) {
      a[0] = 0;
      for (int v = 0; v < n; ++v) {
        int val = ((ts[v] & 1) == (i & 1) ? i - 2 : i - 1);
        val = min(val, min(ts[v], n - ts[v]));
        a[v] = val;
      }
      int need = k - cur;
      for (int v = 0; v < n && need; ++v) {
        if ((ts[v] & 1) == (i & 1) && a[v] + 2 <= min(ts[v], n - ts[v])) {
          a[v] += 2;
          need -= 2;
        }
      }
      break;
    }
    cur += c[i & 1] * 2;
    c[i & 1] -= cnt[i];
  }
  ans.clear();
  dfs(0, -1);
  printf("YES\n");
  for (int i = 0; i < sz(ans); ++i) {
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