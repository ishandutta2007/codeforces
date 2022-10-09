#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 1000;
int const edgemax = nmax * (nmax - 1) / 2;

struct Edge{
  int x;
  int y;
  int cost;
  bool operator < (Edge const &a) const {
    return cost < a.cost;
  }
} v[1 + edgemax];

namespace Dsu{
  vector<int> mult;
  vector<int> sz;
  vector<int> cost;
  void initialize(int n){
    mult.resize(1 + n);
    sz.resize(1 + n);
    cost.resize(1 + n);
    for(int i = 1;i <= n; i++)
      mult[i] = i;
    for(int i = 1;i <= n; i++)
      sz[i] = 1;
    for(int i = 1;i <= n; i++)
      cost[i] = 0;
  }

  int jump(int gala){
    if(gala != mult[gala]) {
      int parent = mult[gala];
      mult[gala] = jump(mult[gala]);
      cost[gala] = cost[gala] ^ cost[parent];
    }
    return mult[gala];
  }

  int unite(int gala, int galb){
    jump(gala);
    jump(galb);
    if(mult[gala] == mult[galb]){
      if((cost[gala] ^ cost[galb]) == 0)
        return -1;
      else
        return 0;
    } else {
      int off = cost[gala] ^ cost[galb];
      gala = jump(gala);
      galb = jump(galb);

      if(sz[galb] < sz[gala])
        swap(gala, galb);
      mult[gala] = galb;
      cost[gala] = 1 ^ off;
      sz[galb] += sz[gala];
      return 1;
    }
  }

  void cleartaint(vector<Edge> edges){
    for(int i = 0; i < edges.size(); i++){
      int x = edges[i].x;
      int y = edges[i].y;
      mult[x] = x;
      mult[y] = y;
      sz[x] = sz[y] = 1;
      cost[x] = cost[y] = 0;
    }
  }
}
int n;

class SegmentTree{
private:
  struct Node{
    vector<Edge> edges;
    Node operator + (Node a){
      Node result;
      merge(edges.begin(), edges.end(), a.edges.begin(), a.edges.end(), back_inserter(result.edges));
      vector<Edge> real;
      Dsu::cleartaint(result.edges);

      for(int i = result.edges.size() - 1; 0 <= i; i--){
        Edge e = result.edges[i];
        int verdict = Dsu::unite(e.x, e.y);
        if(0 != verdict)
          real.push_back(e);
        if(verdict == -1)
          break;
      }

      reverse(real.begin(), real.end());
      result.edges = real;
      return result;
    }
  };
  vector<Node> aint;
public:
  SegmentTree(int n_){
    aint.resize(1 + 4 * n_);
  }
  void build(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      build(node * 2, from, mid);
      build(node * 2 + 1, mid + 1, to);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    } else
      aint[node].edges.push_back(v[from]);
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
  int query(int node, int from, int to, int x, int y){
    Node result = _query(node, from, to, x, y);
    Dsu::cleartaint(result.edges);

    for(int i = result.edges.size() - 1; 0 <= i; i--){
      Edge e = result.edges[i];
      if(Dsu::unite(e.x, e.y) == -1)
        return e.cost;

    }
    return -1;
  }
};

int main()
{
  //*
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //*/

  int m, q;
  cin >> n >> m >> q;
  for(int i = 1;i <= m; i++)
    cin >> v[i].x >> v[i].y >> v[i].cost;
  Dsu::initialize(n);
  SegmentTree aint(m);
  aint.build(1, 1, m);
  for(int i = 1;i <= q;i++){
    int x, y;
    cin >> x >> y;
    cout << aint.query(1, 1, m, x, y) << '\n';
  }
  return 0;
}