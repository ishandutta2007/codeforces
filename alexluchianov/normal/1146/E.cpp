#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using ll = long long;

int const nmax = 100000;
int orig[5 + nmax];

class SegmentTree{
private:
  std::vector<int> lazy;
public:
  SegmentTree(int n) {
    lazy.resize(1 + 4 * n);
  }
  void build(int node, int from, int to) {
    if(from < to) {
      int mid = (from + to) / 2;
      build(node * 2, from, mid);
      build(node * 2 + 1, mid + 1, to);
      lazy[node] = 2;
    } else  {
      lazy[node] = (from % 2);
    }
  }
  /*
  0 = fixed -1
  1 = fixed 1
  2 = no change
  3 = change
  */
  
  int affect(int val, int who) {
    if(who == 0 || who == 1)
      return who;
    else if(who == 2)
      return val;
    else {
      if(val == 0 || val == 1)
        return 1 - val;
      else if(val == 2)
        return 3;
      else if(val == 3)
        return 2;
    }
    return 3;
  }

  void cleannode(int node, int from, int to) {
    if(from < to) {
      int mid = (from + to) / 2;
      lazy[node * 2] = affect(lazy[node * 2], lazy[node]);
      lazy[node * 2 + 1] = affect(lazy[node * 2 + 1], lazy[node]);
      lazy[node] = 2;
    }
  }
  void update(int node, int from, int to, int x, int y, int val) {
    if(y < x)
      return ;
    if(from == x && to == y) {
      lazy[node] = affect(lazy[node], val);
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node, from, to);
      if(x <= mid)
        update(node * 2, from, mid, x, std::min(y, mid), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, std::max(mid + 1, x), y, val);
    }
  }

  int query(int node, int from, int to, int x) {
    if(from == to)
      return lazy[node];
    else {
      cleannode(node, from, to);
      int mid = (from + to) /2;
      if(x <= mid)
        return query(node * 2, from, mid, x);
      else
        return query(node * 2 + 1, mid + 1, to, x);
    }
  }
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  for(int i = 1;i <= n; i++)
    std::cin >> orig[i];
  int lim = 2 * nmax;
  SegmentTree aint(1 + lim);
  aint.build(1, 1, lim);

  for(int i = 1; i <= q; i++) {
    char op;
    int x;
    std::cin >> op >> x;
    if(op == '<') {
      if(0 < x) {
        aint.update(1, 1, lim, 1, 2 * (x - 1), 3);
        aint.update(1, 1, lim, 2 * (x - 1) + 1, lim, 1);
      } else {
        x = -x;
        aint.update(1, 1, lim, 2 * x + 1, lim, 1);
      }
    } else {
      if(x < 0) {
        x = -x;
        aint.update(1, 1, lim, 1, 2 * (x - 1), 3);
        aint.update(1, 1, lim, 2 * (x - 1) + 1, lim, 0);
      } else {
        aint.update(1, 1, lim, 2 * x + 1, lim, 0);
      }
    }
  }
  
  /*
  for(int i = 1;i <= n; i++)
    std::cout << aint.query(1, 1, lim, 2 * std::max(orig[i], -orig[i])) << " ";
  std::cout<< '\n';
  */

  for(int i = 1;i <= n; i++) {
    if(0 < orig[i]) { 
      std::cout << orig[i] * (2 * aint.query(1, 1, lim, 2 * orig[i] - 1) - 1) << " ";
    } else {
      orig[i] = -orig[i];
      std::cout << orig[i] * (2 * aint.query(1, 1, lim, 2 * orig[i]) - 1) << " ";
    }
  }
  std::cout << '\n';
  return 0;
}