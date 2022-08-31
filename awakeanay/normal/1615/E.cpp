#include <iostream>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

int n;

const int INF = 1000'000'000'000'000;

struct seg
{
  std::vector<std::pair<int, int> > arr;
  std::vector<int> lazy;

  void build(int id = 0, int l = 0, int r = n-1) {
    if(l == r) {
      arr[id] = {0, l};
      return;
    }

    build(left, l, mid);
    build(right, mid+1, r);
    arr[id] = std::max(arr[left], arr[right]);
  }

  void push(int id, int l, int r) {
    lazy[left] += lazy[id];
    lazy[right] += lazy[id];
    arr[left].first += lazy[id];
    arr[right].first += lazy[id];
    lazy[id] = 0;
  }

  int query(int x, int id = 0, int l = 0, int r = n-1) {
    if(l == r)
      return arr[id].first;

    push(id, l, r);
    if(x <= mid)
      return query(x, left, l, mid);
    else
      return query(x, right, mid+1, r);
  }

  void update(int x, int y, int v, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      arr[id].first += v;
      lazy[id] += v;
      return;
    }

    push(id, l, r);
    update(x, y, v, left, l, mid);
    update(x, y, v, right, mid+1, r);

    arr[id] = std::max(arr[left], arr[right]);
  }
};

const int MAXN = 200005;

int par[MAXN];
int rev[MAXN];
int etim[MAXN], stim[MAXN];
std::vector<int> Adj[MAXN];
int ct = -1;

void dfs(int u, int p) {
  par[u] = p;
  stim[u] = ++ct;
  rev[stim[u]] = u;
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs(j, u);
  }
  etim[u] = ct;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n;
  int k;
  std::cin >> k;

  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }

  seg tree;
  dfs(0, -1);
  tree.arr = std::vector<std::pair<int, int> >(2*n-1);
  tree.lazy = std::vector<int>(2*n-1, 0);
  tree.build();

  int ans = -INF;
  for(int i = 0; i < n; i++) {
    tree.update(stim[i], etim[i], 1);
    //std::cout << stim[i] << " " << etim[i] << std::endl;
  }

  int ct2 = n;
  int take = n/2;
  // n-i-x
  // i-x
  for(int i = 0; i <= k; i++) {
    int cur = (n-i)*(i);
    cur = std::min(cur, (n-i-ct2)*(i-ct2));
    if(take <= ct2)
      cur = std::min(cur, (n-i-take)*(i-take));
    //std::cout << i << " " << ct2 << std::endl;

    int u = rev[tree.arr[0].second];
    //std::cout << u << std::endl;
    while(u != -1 && tree.query(stim[u])) {
      ct2--;
      tree.update(stim[u], etim[u], -1);
      u = par[u];
    }

    ans = std::max(ans, cur);
  } 

  std::cout << ans << std::endl;

  return 0;
}