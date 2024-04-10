#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 200000;
int v[5 + nmax];

struct Node{
  ll sum ;
  bool complete;
  int pref;
  int suff;
  Node(int val = 0) {
    sum = complete = pref = suff = val;
  }
  Node operator + (Node oth) {
    Node result;
    result.sum = sum + oth.sum + 1LL * suff * oth.pref;
    result.complete = (complete & oth.complete);
    if(complete == 1)
      result.pref = pref + oth.pref;
    else
      result.pref = pref;
    if(oth.complete == 1)
      result.suff = suff + oth.suff;
    else
      result.suff = oth.suff;
    return result;
  }
};

class SegmentTree{
private:
  std::vector<Node> aint;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
  }
  void update(int node, int from, int to, int x, int val) {
    if(from < to) {
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, val);
      else
        update(node * 2 + 1, mid + 1, to, x, val);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    } else
      aint[node] = val;
  }
  Node query(int node, int from, int to, int x, int y) {
    if(y < x)
      return 0;
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return query(node * 2, from, mid, x, mid) + 
               query(node * 2 + 1, mid + 1, to, mid + 1, y);
    }
  }
};

int main() {
  int n, q;
  std::cin >> n >> q;
  SegmentTree aint(n);
  for(int i = 1; i <= n; i++) 
    std::cin >> v[i];
  for(int i = 1; i < n; i++)
    aint.update(1, 1, n, i, v[i] <= v[i + 1]);
  for(int i = 1; i <= q; i++) {
    int op, x, y;
    std::cin >> op >> x >> y;
    if(op == 1) {
      v[x] = y;
      if(x < n)
        aint.update(1, 1, n, x, v[x] <= v[x + 1]);
      if(1 < x)
        aint.update(1, 1, n, x - 1, v[x - 1] <= v[x]);
    } else
      std::cout << aint.query(1, 1, n, x, y - 1).sum + (y - x + 1) << '\n';
  }
  return 0;
}