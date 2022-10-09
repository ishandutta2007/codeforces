#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;

int const nmax = 300000;
int v[1 + nmax];
vector<int> g[1 + nmax];
int imper[1 + nmax], level[1 + nmax];
int far[1 + nmax];

void _addcycle(int node, int to){
  int smin = node, smax = node;
  while(node != to){
    node = far[node];
    smin = min(smin, node);
    smax = max(smax, node);
  }
  imper[smin] = min(imper[smin], smax);
}

void dfs(int node, int parent){
  level[node] = level[parent] + 1;
  far[node] = parent;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent){
      if(level[to] == 0)
        dfs(to, node);
      else if(level[to] < level[node])
        _addcycle(node, to);
    }
  }
}

class SegmentTree{
private:
  vector<ll> aint;
  vector<int> lazy;
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
    aint[node] += 1LL * (to - from + 1) * lazy[node];
    lazy[node] = 0;
  }
  void computenode(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    }
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
      computenode(node, from, to);
    }
  }

  ll query(int node, int from, int to, int x, int y){
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
        return query(node * 2, from, mid, x, mid) + query(node * 2 + 1, mid + 1, to, mid + 1, y);
    }
  }
};
vector<pair<int,int>> queries[1 + nmax];
ll sol[1 + nmax];

int main()
{

  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    imper[i] = n + 1;
  for(int i = 1; i <= m; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1;i <= n; i++)
    if(level[i] == 0)
      dfs(i, 0);

  int q;
  cin >> q;
  for(int i = 1;i <= q; i++){
    int x, y;
    cin >> x >> y;
    queries[x].push_back({y, i});
  }
  ll result = 0;
  SegmentTree aint(n);
  for(int i = n; 1 <= i; i--) {
    if(i < n)
      imper[i] = min(imper[i], imper[i + 1]);
    aint.update(1, 1, n, i, imper[i] - 1, 1);
    for(int h = 0; h < queries[i].size(); h++){
      pair<int,int> quer = queries[i][h];
      sol[quer.second] = aint.query(1, 1, n, 1, quer.first);
    }
  }

  for(int i = 1; i <= q; i++)
    cout << sol[i] << '\n';
  return 0;
}