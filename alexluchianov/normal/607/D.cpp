#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
using ld = long double;

int const nmax = 400000;
int const modulo = 1000000007;

int query[1 + nmax];
vector<int> g[1 + nmax];

class ModuloRing{
private:
  void gcd(int a, int b, int &x, int &y){
    if(b == 0){
      x = 1;
      y = 0;
    } else {
      gcd(b, a % b, x, y);
      int aux = x;
      x = y;
      y = aux - a / b * y;
    }
  }
public:
  int number;
  ModuloRing(ll number_ = 0){
    number = number_ % modulo;
  }
  ModuloRing operator + (ModuloRing const &a) const {
    return number + a.number;
  }
  ModuloRing operator - (ModuloRing const &a) const {
    return modulo + number - a.number;
  }
  ModuloRing operator * (ModuloRing const &a) const {
    return 1LL * number * a.number;
  }
  ModuloRing operator / (ModuloRing const &a) {
    int x, y;
    gcd(a.number, modulo, x, y);
    x %= modulo;
    if(x < 0)
      x += modulo;
    return 1LL * number * x;
  }
};

class SegmentTree{
private:
  struct Node{
    ModuloRing val;
    ModuloRing coef;
    Node operator + (Node const &a) const {
      Node result;
      result.coef = coef * a.coef;
      result.val = val + coef * a.val;
      return result;
    }
  };
  vector<Node> aint;
public:
  SegmentTree(int n){
    aint.resize(1 + 4 * n);
    for(int i = 1;i <= 4 * n; i++)
      aint[i].coef = 1;
  }
  void _update(int node, int from, int to, int x, Node result){
    if(from < to){
      int mid = (from + to) / 2;
      if(x <= mid)
        _update(node * 2, from, mid, x, result);
      else
        _update(node * 2 + 1, mid + 1, to, x, result);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    } else
      aint[node] = result;
  }
  Node _query(int node, int from, int to, int x, int y){
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) /2 ;
      if(x <= mid && y <= mid)
        return _query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return _query(node * 2 + 1, mid + 1, to, x, y);
      else
        return _query(node * 2, from, mid, x, mid) + _query(node * 2 + 1, mid+ 1, to, mid + 1, y);
    }
  }
  int query(int node, int from, int to, int x, int y){
    return _query(node, from, to, x, y).val.number;
  }
};

int grad[1 + nmax], start[1 + nmax], stop[1 + nmax], ptr = 0;

void dfs(int node, int parent){
  start[node] = ++ptr;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to == parent)
      g[node].erase(g[node].begin() + h);
  }
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    dfs(to, node);
  }
  stop[node] = ++ptr;
}

int queries[1 + nmax][2], far[1 + nmax], v[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n = 1, q;
  cin >> v[1] >> q;
  for(int i = 1; i <= q; i++){
    int op;
    cin >> op;
    if(op == 1){
      int parent;
      cin >> parent >> v[++n];
      g[parent].push_back(n);
      far[n] = parent;
      queries[i][0] = 0;
      queries[i][1] = n;
    } else {
      int x;
      cin >> x;
      queries[i][0] = 1;
      queries[i][1] = x;
    }
  }

  dfs(1, 0);
  SegmentTree aint(ptr);
  grad[1]++;
  aint._update(1, 1, ptr, start[1], {v[1], grad[1]});
  for(int i = 1;i <= q; i++){
    if(queries[i][0] == 0){
      int node = queries[i][1];
      grad[far[node]]++;
      aint._update(1, 1, ptr, start[far[node]], {1LL * v[far[node]] * grad[far[node]], grad[far[node]]});
      aint._update(1, 1, ptr, stop[far[node]], {0, ModuloRing(1) / grad[far[node]]} );

      grad[node] = 1;
      aint._update(1, 1, ptr, start[node], {v[node], grad[node]});
      aint._update(1, 1, ptr, stop[node], {0, ModuloRing(1) / grad[node]} );
    } else {
      int node = queries[i][1];
      cout << aint.query(1, 1, ptr, start[node], stop[node]) << '\n';
    }
  }
  return 0;
}