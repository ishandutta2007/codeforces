#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

mt19937 rng (time(NULL));

int rnd(int l, int r) {
  return rng() % (r - l + 1) + l;
}

int T;
int n, m;
vector<int> G[N];

bool vis[N], ins[N];
void dfs(int p) {
  vis[p] = ins[p] = true;
  for (auto e : G[p]) {
    if (!vis[e]) {
      dfs(e);
    } else if (!ins[e]) {
      throw 1;
    }
  }
  ins[p] = false;
}

bool check(int p) {
  fill(vis + 1, vis + n + 1, false);
  fill(ins + 1, ins + n + 1, false);
  try {
    dfs(p);
  } catch (int) {
    return false;
  }
  return true;
}

int dfc;
bool valid[N];
int dfn[N], low[N], low2[N], tour[N];

void upd_low(int p, int t) {
  if (t < low[p]) {
    swap(low[p], low2[p]);
    low[p] = t;
  } else if (t < low2[p]) {
    low2[p] = t;
  }
}

void tarjan(int p) {
  dfn[p] = low[p] = low2[p] = ++dfc;
  tour[dfc] = p;
  for (auto e : G[p]) {
    if (!dfn[e]) {
      tarjan(e);
      upd_low(p, low[e]);
      upd_low(p, low2[e]);
    } else {
      upd_low(p, dfn[e]);
    }
  }
}

void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1, u, v; i <= m; i++) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
  }
  int rt = -1;
  for (int t = 1; t <= 70; t++) {
    if (check(rt = rnd(1, n))) {
      break;
    } else {
      rt = -1;
    }
  }
  if (rt < 0) {
    puts("-1");
    return;
  }
  fill(dfn + 1, dfn + n + 1, 0);
  tarjan(rt);
  fill(valid + 1, valid + n + 1, false);
  valid[rt] = true;
  for (int i = 2; i <= n; i++) {
    int p = tour[i];
    if (low2[p] < dfn[p]) {
      continue;
    }
    int q = tour[low[p]];
    valid[p] = valid[q];
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (valid[i]) {
      ans.push_back(i);
    }
  }
  if ((signed) ans.size() * 5 < n) {
    puts("-1");
  } else {
    for (auto x : ans) {
      printf("%d ", x);
    }
    putchar('\n');
  }
}

void clear() {
  dfc = 0;
  for (int i = 1; i <= n; i++) {
    G[i].clear();
  }
}

int main() {
  scanf("%d", &T);
  while (T--) {
    solve();
    clear();
  } 
  return 0;
}