#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

const int MAXN = 300005;

int stim[MAXN], etim[MAXN];
int par[MAXN];
int dep[MAXN];
std::pair<int, int> depv[MAXN];
std::vector<int> path;
int n;
std::vector<int> Adj[MAXN];
int ct;

struct seg
{
  std::vector<int> arr, lazy;

  void push(int id, int l, int r) {
    lazy[left] += lazy[id];
    lazy[right] += lazy[id];
    arr[left] += lazy[id];
    arr[right] += lazy[id];
    lazy[id] = 0;
  }

  void upd(int x, int y, int v, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      lazy[id] += v;
      arr[id] += v;
      return;
    }

    push(id, l, r);
    upd(x, y, v, left, l, mid);
    upd(x, y, v, right, mid+1, r);

    arr[id] = std::max(arr[left], arr[right]);
  }
};

seg tree;
int imp;

void dfs(int u, int p, int d) {
  par[u] = p;
  stim[u] = ++ct;
  dep[u] = d;
  if(dep[u] > dep[imp]) {
    imp = u;
  }
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs(j, u, d+1);
  }
  etim[u] = ct;
}

int tv, nv;
int it, pt;

bool test() {
  while(it < n && depv[it].first > tv) {
    int x = depv[it].second;
    tree.upd(stim[x], stim[x], MAXN);
    it++;
  }
  
  return tree.arr[0] <= tv;
}

void moveUp() {
  tree.upd(stim[path[pt]], etim[path[pt]], 2);
  tree.upd(0, n-1, -1);
  pt++;
}

void moveDown() {
  pt--;
  tree.upd(stim[path[pt]], etim[path[pt]], -2);
  tree.upd(0, n-1, 1);
}

void dfs2(int u, int p, int d) {
  tree.upd(stim[u], stim[u], d-MAXN);
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs2(j, u, d+1);
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> n;

    for(int i = 0; i < n; i++) {
      Adj[i].clear();
      par[i] = -1;
    }

    for(int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }

    imp = 0;
    ct = -1;
    dfs(0, -1, 0);

    for(int i = 0; i < n; i++)
      depv[i] = {dep[i], i};

    std::sort(depv, depv+n);
    std::reverse(depv, depv+n);
    it = 0;

    path.clear();

    int x = imp;
    while(x > 0) {
      path.push_back(x);
      x = par[x];
    }

    tv = dep[imp]-1;
    pt = 0;
    nv = imp;
    int ans[n];

    for(int i = dep[imp]; i <= n; i++)
      ans[i-1] = dep[imp];

    tree.arr = tree.lazy = std::vector<int>(2*n-1, 0);
    dfs2(nv, -1, 0);

    tree.upd(0, n-1, dep[imp]-1);
    for(int i = dep[imp]-1; i > 0; i--) {
      while(test() && pt > 0) {
        tv--;
        moveDown();
      }

      //std::cout << i << " " << tv << " " << test() << std::endl;

      ans[i-1] = tv+1-test();

      moveUp();
      tree.upd(0, n-1, -1);
    }

    for(int i = 0; i < n; i++)
      std::cout << ans[i] << " \n"[i == n-1];
  }

  return 0;
}