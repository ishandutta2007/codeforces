#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <set>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const lgmax = 20;

class SegmentTree{
private:
  vector<pair<int,int>> aint;
  vector<int> lazy;
public:
  SegmentTree(int n = 0){
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }
  void cleannode(int node, int from, int to){
    if(lazy[node] == 0)
      return ;
    if(from < to){
      int mid = (from + to) / 2;
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node].first += lazy[node];
    lazy[node] = 0;
  }

  pair<int,int> join(pair<int,int> f1, pair<int,int> f2){
    if(f1.first == f2.first)
      return {f1.first, f1.second + f2.second};
    else
      return min(f1, f2);
  }

  void build(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      build(node * 2, from, mid);
      build(node * 2 + 1, mid + 1, to);
      aint[node] = join(aint[node * 2], aint[node * 2 + 1]);
    } else
      aint[node] = {0, 1};
  }

  void update(int node, int from, int to, int x, int y, int val){
    if(from == x && to == y){
      lazy[node] += val;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        update(node * 2, from, mid, x, MIN(y, mid), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
      aint[node] = join(aint[node * 2], aint[node * 2 + 1]);
    }
  }

  pair<int,int> query(int node, int from, int to, int x, int y){
    cleannode(node, from, to);
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return join(query(node * 2, from, mid, x, mid), query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }
  }
};

vector<int> g[1 + nmax];
int far[1 + lgmax][1 + nmax], level[1 + nmax];
int start[1 + nmax], stop[1 + nmax], ptr = 0;

void dfs(int node, int parent){
  far[0][node] = parent;
  level[node] = level[parent] + 1;
  start[node] = ++ptr;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      dfs(to, node);
  }

  stop[node] = ptr;
}

void computefar(int n){
  for(int h = 1; h <= lgmax; h++)
    for(int i = 1; i <= n; i++)
      far[h][i] = far[h - 1][far[h - 1][i]];
}

int getlca(int x, int y){
  if(level[x] < level[y])
    swap(x, y);
  for(int h = lgmax; 0 <= h; h--)
    if(level[y] + (1 << h) <= level[x])
      x = far[h][x];
  if(x == y)
    return x;
  for(int h = lgmax; 0 <= h; h--)
    if(far[h][x] != far[h][y]){
      x = far[h][x];
      y = far[h][y];
    }
  return far[0][x];
}

SegmentTree aint;

int jump(int node, int height){
  for(int h = lgmax; 0 <= h; h--)
    if((1 << h) <= height){
      node = far[h][node];
      height -= (1 << h);
    }
  return node;
}

void update(int x, int y, int val, int n){
  if(level[x] < level[y])
    swap(x, y);
  int lca = getlca(x, y);
  if(lca == y){
    int oth = jump(x, level[x] - level[y] - 1);
    aint.update(1, 1, n, start[oth], stop[oth], val);
    aint.update(1, 1, n, start[x], stop[x], -val);
  } else {
    aint.update(1, 1, n, 1, n, val);
    aint.update(1, 1, n, start[x], stop[x], -val);
    aint.update(1, 1, n, start[y], stop[y], -val);
  }
}

set<pair<int,int>> myset;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  computefar(n);

  aint = SegmentTree(n);
  aint.build(1, 1, n);

  for(int i = 1;i <= q; i++){
    int x, y;
    cin >> x >> y;
    if(y < x)
      swap(x, y);
    int sign = 1;
    if(myset.find({x, y}) == myset.end()) {
      myset.insert({x, y});
      sign = 1;
    } else {
      myset.erase({x, y});
      sign = -1;
    }
    update(x, y, sign, n);
    pair<int,int> result = aint.query(1, 1, n, 1, n);

    if(result.first == 0)
      cout << result.second << '\n';
    else
      cout << 0 << '\n';
  }
  return 0;
}