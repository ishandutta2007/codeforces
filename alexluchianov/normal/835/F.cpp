#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
using ld = long double;

int const nmax = 200000;
ll const inf = 1000000000000000000;

struct Edge{
  int to;
  int cost;
};
vector<Edge> g[1 + nmax];
int seen[1 + nmax];
Edge far[1 + nmax];

int dfs(int node, int parent, vector<Edge> &cycle){
  seen[node] = 1;
  for(int h = 0; h < g[node].size(); h++){
    Edge e = g[node][h];
    if(e.to != parent){
      if(seen[e.to] == 0) {
        far[e.to] = {node, e.cost};
        if(dfs(e.to, node, cycle))
          return 1;
      } else {
        cycle.push_back({node, e.cost});
        int target = e.to, start = node;
        while(start != target){
          cycle.push_back(far[start]);
          start = far[start].to;
        }
        return 1;
      }
    }
  }
  return 0;
}

int active[1 + nmax];
ll coef[1 + nmax];

void solve(int node, int parent, ll &defaultdiam){
  for(int h = 0; h < g[node].size(); h++){
    Edge e = g[node][h];
    if(e.to != parent && active[e.to] == 0) {
      solve(e.to, node, defaultdiam);
      defaultdiam = max(defaultdiam, coef[node] + coef[e.to] + e.cost);
      coef[node] = max(coef[node], coef[e.to] + e.cost);
    }
  }
}

class SegmentTree{
private:
  struct Node{
    ll result;
    ll val1, val2;
    Node operator + (Node const &a) const {
      Node product;
      product.result = max(max(result, a.result), val1 + a.val2);
      product.val1 = max(val1, a.val1);
      product.val2 = max(val2, a.val2);
      return product;
    }
  };
  vector<Node> aint;
public:
  SegmentTree(int n){
    aint.resize(1 + 4 * n);
  }
  void update(int node, int from, int to, int x, ll val1, ll val2){
    if(from < to){
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, val1, val2);
      else
        update(node * 2 + 1, mid + 1, to, x, val1, val2);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    } else
      aint[node] = {0, val1, val2};
  }

  Node _query(int node, int from, int to, int x, int y){
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return _query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return _query(node * 2 + 1, mid + 1, to, x, y);
      else
        return _query(node * 2, from, mid, x, mid) + _query(node * 2 + 1, mid + 1, to, mid + 1, y);
    }
  }
  ll query(int node, int from, int to, int x, int y){
    return _query(node, from, to, x, y).result;
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++){
    int x, y, cost;
    cin >> x >> y >> cost;
    g[x].push_back({y, cost});
    g[y].push_back({x, cost});
  }
  vector<Edge> cycle;
  dfs(2, 0, cycle);
  for(int i = 0; i < cycle.size(); i++)
    active[cycle[i].to] = 1;

  ll defaultdiam = 0;
  for(int i = 0; i < cycle.size(); i++)
    solve(cycle[i].to, 0, defaultdiam);

  vector<Edge> cycle2 = cycle;
  int k = cycle2.size();
  cycle.insert(cycle.end(), cycle2.begin(), cycle2.end());

  int csize = cycle.size();
  SegmentTree aint(1 + cycle.size());

  ll sum = 0;
  for(int i = 0; i < cycle.size(); i++) {
    sum += cycle[i].cost;
    aint.update(1, 0, csize, i, coef[cycle[i].to] - sum, coef[cycle[i].to] + sum);
  }
  ll diammin = inf;
  for(int i = k - 1; i < cycle.size(); i++)
    diammin = min(diammin, aint.query(1, 0, csize, i - k + 1, i));

  cout << max(diammin, defaultdiam);
  return 0;
}