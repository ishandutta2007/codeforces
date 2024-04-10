#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

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
    int mid = (from + to) / 2;
    if(from < to){
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node] = aint[node] + lazy[node];
    lazy[node] = 0;
  }

  void computenode(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      aint[node] = max(aint[node * 2], aint[node * 2 + 1]);
    }
  }

  void update(int node, int from, int to, int x, int y, ll val){
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
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return max(query(node * 2, from, mid, x, mid), query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }
  }
};
int const nmax = 200000;
int v[1 + nmax];
vector<pair<int,int>> g[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= m; i++){
    int x, y, cost;
    cin >> x >> y >> cost;
    g[y].push_back({x, cost});
  }
  SegmentTree aint(n);
  for(int i = 1;i <= n; i++){
    ll result = aint.query(1, 0, n, 0, i - 1);
    aint.update(1, 0, n, i, i, result);
    aint.update(1, 0, n, 0, i - 1, -v[i]);
    for(int h = 0; h < g[i].size(); h++){
      int x = g[i][h].first, cost = g[i][h].second;
      aint.update(1, 0, n, 0, x - 1, cost);
    }
  }
  cout << aint.query(1, 0, n, 0, n);
  return 0;
}