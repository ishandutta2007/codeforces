#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
int const nmax = 500000;
ll const inf = 100000000000000000LL;

vector<pair<int,int>> g[1 + nmax];
ll path[1 + nmax];
int sz[1 + nmax], isleaf[1 + nmax];

void computepath(int node){
  sz[node] = 1;
  for(int h = 0; h < g[node].size(); h++){
    path[g[node][h].first] = path[node] + g[node][h].second;
    computepath(g[node][h].first);
    sz[node] += sz[g[node][h].first];
  }
}

class SegmentTree{
private:
  vector<ll> aint;
  vector<ll> lazy;
public:
  SegmentTree(int n){
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }

  void cleannode(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node] += lazy[node];
    lazy[node] = 0;
  }

  void computenode(int node, int from, int to){
    if(from < to)
      aint[node] = MIN(aint[node * 2], aint[node * 2 + 1]);
  }

  void build(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      build(node * 2, from, mid);
      build(node * 2 + 1, mid + 1, to);
      computenode(node, from, to);
    } else {
      if(isleaf[from] == 1)
        aint[node] = path[from];
      else
        aint[node] = inf;
    }
  }

  void update(int node, int from, int to, int x, int y, int val){
    cleannode(node, from, to);

    if(from == x && to == y){
      lazy[node] += val;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);

      if(x <= mid)
        update(node * 2, from, mid, x, MIN(mid, y), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
      computenode(node, from, to);
    }
  }

  ll query(int node, int from, int to, int x, int y){
    cleannode(node, from, to);
    if(from == x && to == y)
      return aint[node];
    else{
      int mid = (from + to) / 2;
      ll result = inf, result2 = inf;
      if(x <= mid)
        result = query(node * 2, from, mid, x, MIN(y, mid));
      if(mid + 1 <= y)
        result2 = query(node * 2 + 1,mid + 1, to, MAX(mid + 1, x), y);
      return MIN(result, result2);
    }
  }
};

struct Query{
  int x;
  int y;
  int id;
};
ll sol[1 + nmax];
vector<Query> queries[1 + nmax];

void dfs(int node, SegmentTree &aint, int n){
  for(int h = 0; h < queries[node].size(); h++) {
    int id = queries[node][h].id;
    sol[id] = aint.query(1, 1, n, queries[node][h].x, queries[node][h].y);
  }

  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first, cost = g[node][h].second;
    aint.update(1, 1, n, 1, n, cost);
    aint.update(1, 1, n, to, to + sz[to] - 1, -2 * cost);
    dfs(to, aint, n);
    aint.update(1, 1, n, 1, n, -cost);
    aint.update(1, 1, n, to, to + sz[to] - 1, 2 * cost);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q;
  cin >> n >> q;
  for(int i = 1;i <= n; i++)
    isleaf[i] = 1;

  for(int i = 2; i <= n; i++){
    int parent, cost;
    cin >> parent >> cost;
    isleaf[parent] = 0;
    g[parent].push_back({i, cost});
  }
  computepath(1);
  SegmentTree aint(n);
  aint.build(1, 1, n);

  for(int i = 1;i <= q; i++){
    int node, x, y;
    cin >> node >> x >> y;
    queries[node].push_back({x, y, i});
  }
  dfs(1, aint, n);
  for(int i = 1;i <= q; i++)
    cout << sol[i] << '\n';
  return 0;
}