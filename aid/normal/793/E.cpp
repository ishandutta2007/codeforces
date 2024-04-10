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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 5005;
int n;
vector<int> g[maxn];
int a[4];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < 4; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    p--;
    g[p].push_back(i);
  }
  return true;
}

int ad[maxn];
int ts[maxn];
int cnt[4];
bitset<maxn> bs[4];
int coth;
bitset<maxn> oth;

void dfs(int v) {
  ad[v] = -1;
  for (int i = 0; i < 4; i++) {
    if (a[i] == v) {
      ad[v] = i;
    }
  }
  ts[v] = g[v].empty();
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    dfs(u);
    if (v && ad[u] != -1) {
      assert(ad[v] == -1);
      ad[v] = ad[u];
    }
    ts[v] += ts[u];
  }
  if (ad[v] != -1) {
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (ad[u] != -1) {
        continue;
      }
      bs[ad[v]] |= (bs[ad[v]] << ts[u]);
    }
  }
  if (!v) {
    coth = 0;
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (ad[u] != -1) {
        cnt[ad[u]] = ts[u] - 1;
        continue;
      }
      oth |= (oth << ts[u]);
      coth += ts[u];
    }
  }
}

void solve() {
  for (int i = 0; i < 4; i++) {
    bs[i].reset();
    bs[i][0] = true;
  }
  oth.reset();
  oth[0] = true;
  dfs(0);
  if (ts[0] & 1) {
    printf("NO\n");
    return;
  }
  int need = (ts[0] - 2) / 2;
  for (int it = 0; it < 2; it++) {
    int x = it * 2, y = it * 2 + 1;
    bool ok = false;
    for (int i = 0; i <= coth; i++) {
      if (!oth[i]) {
        continue;
      }
      int mid = i + cnt[x ^ 2] + 1;
      int d = need - mid - cnt[y];
      //eprintf("i = %d, mid = %d, d = %d\n", i, mid, d);
      if (d >= 0) {
        if ((bs[x] & (bs[y] << d)).any()) {
          ok = true;
          break;
        }
      } else {
        if ((bs[x] & (bs[y] >> (-d))).any()) {
          ok = true;
          break;
        }
      }
    }
    if (!ok) {
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
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