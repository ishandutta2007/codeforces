#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
vector<pair<int, int>> g[N];
vector<int> children[N];
int sz[N];
int parent[N];
int hld_index[N];
int hld_rt[N];
int hld_ptr = 0;

int num[N]; // index of edge leading to this vtx
int b[N];
int is_active[N];

int lazy[4*N];
int asum[4*N][2]; // 0 = current sum, 1 = sum if all active
long long bsum[4*N][2];

void dfs(int v, int p) {
  parent[v] = p;
  sz[v] = 1;
  for (pair<int, int>& e: g[v]) {
    int u = e.first;
    int k = e.second;
    if (u != p) {
      children[v].push_back(u);
      num[u] = k;
      dfs(u, v);
      sz[v] += sz[u];
    }
  }
}

void dfs2(int v, int rt) {
  hld_rt[v] = rt;
  hld_index[v] = hld_ptr++;
  for (int u: children[v]) {
    if (2*sz[u] >= sz[v]) {
      dfs2(u, rt);
    }
  }
  for (int u: children[v]) {
    if (2*sz[u] < sz[v]) {
      dfs2(u, u);
    }
  }
}

void push(int v, int tl, int tr) {
  if (!lazy[v]) return;
  lazy[2*v] ^= 1;
  lazy[2*v+1] ^= 1;
  int tm = (tl+tr)/2;
  for (int u = 0; u < 2; u++) {
    asum[2*v+u][0] = asum[2*v+u][1] - asum[2*v+u][0];
    bsum[2*v+u][0] = bsum[2*v+u][1] - bsum[2*v+u][0];
  }
  lazy[v] = 0;
}

void combine(int v, int k) {
  asum[v][k] = asum[2*v][k] + asum[2*v+1][k];
  bsum[v][k] = bsum[2*v][k] + bsum[2*v+1][k];
}

void init(int v, int tl, int tr) {
  if (tl == tr) {
    asum[v][1] = 1;
    bsum[v][1] = b[tl];
    return;
  }
  int tm = (tl+tr)/2;
  init(2*v, tl, tm);
  init(2*v+1, tm+1, tr);
  combine(v, 1);
}

void init() {
  init(1, 0, N);
}

void flip(int v, int tl, int tr, int l, int r) {
  if (l > r) return;
  if (l == tl && r == tr) {
    lazy[v] ^= 1;
    asum[v][0] = asum[v][1] - asum[v][0];
    bsum[v][0] = bsum[v][1] - bsum[v][0];
    return;
  }
  push(v, tl, tr);
  int tm = (tl+tr)/2;
  flip(2*v, tl, tm, l, min(r, tm));
  flip(2*v+1, tm+1, tr, max(l, tm+1), r);
  combine(v, 0);
}

void flip(int l, int r) {
  flip(1, 0, N, l, r);
}

void push_all(int v, int tl, int tr) {
  if (tl == tr) {
    is_active[tl] = lazy[v];
    return;
  }
  push(v, tl, tr);
  int tm = (tl+tr)/2;
  push_all(2*v, tl, tm);
  push_all(2*v+1, tm+1, tr);
  combine(v, 0);
}

void push_all() {
  push_all(1, 0, N);
}

void activate(int v) {
  // flip all vertices on path from v to 1
  flip(1, 0, N, hld_index[hld_rt[v]], hld_index[v]);
  if (hld_rt[v] == 1) return;
  activate(parent[hld_rt[v]]);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(make_pair(v, i));
    g[v].push_back(make_pair(u, i));
  }
  dfs(1, 1);
  dfs2(1, 1);
  for (int i = 1; i <= n; i++) {
    b[hld_index[i]] = num[i];
  }
  init();

  activate(1);
  int active = 1;

  while (1) {
    int q;
    cin >> q;
    if (q == 1) {
      int v;
      cin >> v;
      activate(v);
      active++;
      cout << (2*asum[1][0] == active ? bsum[1][0] : 0) << endl;
    }
    else if (q == 2) {
      if (2*asum[1][0] != active) cout << 0 << endl;
      else {
        vector<int> nums;
        push_all();
        for (int i = 1; i <= n; i++) {
          if (is_active[hld_index[i]]) nums.push_back(num[i]);
        }
        sort(nums.begin(), nums.end());
        cout << nums.size() << ' ';
        for (int val: nums) cout << val << ' ';
        cout << endl;
      }
    }
    else {
      return 0;
    }
  }
}