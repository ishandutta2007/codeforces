#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100000;
int v[1 + nmax];

struct Node{
  ll smin;
  ll sum;
  ll smax;
  Node(ll val_ = 0) {
    smin = val_;
    sum = val_;
    smax = val_;
  }
  Node operator + (Node oth) const{
    Node result;
    result.smin = std::min(smin, sum + oth.smin);
    result.sum = sum + oth.sum;
    result.smax = std::max(smax, sum + oth.smax);
    return result;
  }
};

class SegmentTree{
private:
  std::vector<Node> aint;
public:
  SegmentTree(int n)  {
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
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    int val;
    std::cin >> val;
    v[i] -= val;
  }
  for(int i = 1; i <= n; i++) {
    int val;
    std::cin >> val;
    v[i] += val;
  }
  SegmentTree aint(n);
  for(int i = 1;i <= n; i++)
    aint.update(1, 1, n, i, v[i]);
  

  for(int i = 1;i <= q; i++) {
    int l, r;
    std::cin >> l >> r;
    Node sol = aint.query(1, 1, n, l, r);
    if(sol.smin < 0 || sol.sum != 0)
      std::cout << -1 << '\n';
    else
      std::cout << sol.smax << '\n';
  }
  return 0;
}