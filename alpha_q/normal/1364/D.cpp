#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

bitset <N> vis;
vector <int> g[N], cyc, col[2];
int n, m, k, deg[N], h[N], par[N], found, pos[N];

void go (int u = 1, int pr = -1, int far = 0) {
  if (found) return;
  vis[u] = 1, par[u] = pr;
  for (int v : g[u]) {
    if (found) return;
    if (vis[v]) {
      if (v == pr) continue;
      int at = u;
      while (at != v) {
        cyc.emplace_back(at);
        at = par[at];
      }
      cyc.emplace_back(v);
      found = 1; return;
    } else {
      go(v, u);
      if (found) return;
    }
  } 
}

void dfs (int u = 1, int pr = -1, int c = 0) {
  col[c].emplace_back(u);
  for (int v : g[u]) if (v ^ pr) dfs(v, u, c ^ 1);
}

int main() {
  cin >> n >> m >> k;
  for (int i = 1, u, v; i <= m; ++i) {
    scanf("%d %d", &u, &v);
    ++deg[u], ++deg[v];
    g[u].emplace_back(v); 
    g[v].emplace_back(u);
  }
  if (m == n - 1) {
    dfs();
    int id = 0;
    if (col[1].size() > col[0].size()) id = 1;
    puts("1");
    int req = 1 + k >> 1;
    for (int i = 0; i < req; ++i) {
      printf("%d ", col[id][i]);
    }
    cout << '\n';
    return 0;
  }
  go();
  // cout << "yo\n";
  if (cyc.size() <= k) {
    puts("2");
    cout << cyc.size() << '\n';
    for (int x : cyc) printf("%d ", x); 
    cout << '\n';
    return 0;
  }
  int sz = cyc.size();
  assert(sz > 2);
  memset(pos, -1, sizeof pos);
  for (int i = 0; i < sz; ++i) pos[cyc[i]] = i;
  int mn = sz, l = 0, r = sz - 1;
  for (int i = 0; i < sz; ++i) {
    int u = cyc[i];
    for (int v : g[u]) if (pos[v] != -1) {
      int lt = min(i, pos[v]), rt = max(i, pos[v]);
      if (rt > lt + 1 and rt - lt + 1 < mn) {
        mn = rt - lt + 1;
        l = lt, r = rt;
      }
      if ((rt + 1) % sz != lt and sz - (rt - lt) + 1 < mn) {
        mn = sz - (rt - lt) + 1;
        l = rt, r = lt;
      }
    }
  }
  for (int i = 0; i < sz; ++i) cyc.emplace_back(cyc[i]);
  vector <int> ref;
  if (l > r) r += sz;
  for (int i = l; i <= r; ++i) ref.emplace_back(cyc[i]);
  assert(ref.size() > 2);
  if (ref.size() <= k) {
    puts("2");
    cout << ref.size() << '\n';
    for (int x : ref) printf("%d ", x); 
    cout << '\n';
    return 0; 
  }
  int req = 1 + k >> 1;
  puts("1");
  for (int i = 0, j = 0; i < req; ++i, j += 2) {
    printf("%d ", ref[j]);
  }
  cout << '\n';
  return 0;
}