#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const kmax = 31;
int nice[1 + kmax] = {4,7,44,47,74,77,444,447,474,477,744,747,774,777,
                      4444,4447,4474,4477,4744,4747,4774,4777,
                      7444,7447,7474,7477,7744,7747,7774,7777, 44444
                      };

int next_nice(int val) {
  for(int i = 0; i < kmax; i++)
    if(val <= nice[i])
      return i;
  return kmax;
}

class SegmentTree{
private:
  struct Node {
    int smin;
    int base;
    int _count;
    Node(int _smin = 0, int _base = 0, int __count = 0) {
      smin = _smin;
      base = _base;
      _count = __count;
    }
    Node operator + (Node a) {
      return {MIN(smin, a.smin), base,  _count + a._count};
    }
  };
public:
  std::vector<Node> aint;
  std::vector<int> lazy;
  SegmentTree(int n = 0) {
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }
  void cleannode(int node, int from, int to) {
    if(lazy[node] == 0)
      return ;
    if(from < to) {
      int mid = (from + to) / 2;
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node].smin -= lazy[node];
    aint[node].base += lazy[node];
    aint[node]._count = 0;
    lazy[node] = 0;
  }

  void computenode(int node, int from, int to) {
    if(from < to)
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
  }

  void build(int node, int from, int to, std::vector<int> &v) {
    if(from < to) {
      int mid = (from + to) / 2;
      build(node * 2, from, mid, v);
      build(node * 2 + 1, mid + 1, to, v);
      computenode(node, from, to);
    } else {
      int id = next_nice(v[from]);
      if(nice[id] == v[from])
        aint[node] = {nice[id + 1] - v[from], v[from], 1};
      else
        aint[node] = {nice[id] - v[from], v[from], 0};
    }
  }

  void _update(int node, int from, int to, int x, int y, int val) {
    cleannode(node, from, to);
    if(from == x && to == y) {
      lazy[node] += val;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        _update(node * 2, from, mid, x, MIN(y, mid), val);
      if(mid + 1 <= y)
        _update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
      computenode(node, from, to);
    }
  }

  void repair(int node, int from, int to) {
    cleannode(node, from, to);
    if(0 < aint[node].smin)
      return ;
    if(from < to) {
      int mid = (from + to) / 2;
      repair(node * 2, from, mid);
      repair(node * 2 + 1, mid + 1, to);
      computenode(node, from, to);
    } else {
      int base = aint[node].base;
      int id = next_nice(base);
      if(nice[id] == base)
        aint[node] = {nice[id + 1] - base, base, 1};
      else
        aint[node] = {nice[id] - base, base, 0};
    }
  }
  void update(int node, int from, int to, int x, int y, int val) {
    _update(node, from, to, x, y, val);
    repair(node, from, to);
  }

  Node _query(int node, int from, int to, int x, int y) {
    cleannode(node, from, to);
    if(from == x && to == y) {
      return aint[node];
    } else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return _query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return _query(node * 2 + 1, mid + 1, to, x, y);
      else
        return _query(node * 2, from, mid, x, mid) +
        _query(node * 2 + 1, mid + 1, to, mid + 1, y);
    }
  }

  int query(int node, int from, int to, int x, int y) {
    return _query(node, from, to, x, y)._count;  
  }
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  std::vector<int> v(1 + n);
  SegmentTree aint(n);

  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  aint.build(1, 1, n, v);
  for(int i = 1;i <= q; i++) {
    std::string op;
    std::cin >> op;
    if(op == "count") {
      int x, y;
      std::cin >> x >> y;
      std::cout << aint.query(1, 1, n, x, y) << '\n';
    } else {
      int x, y, val;
      std::cin >> x >> y >> val;
      aint.update(1, 1, n, x, y, val);
    }
  }
}