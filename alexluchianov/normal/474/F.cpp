#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;
int const nmax = 100000;

struct Node{
  int smin;
  int scount;
  int div;
  Node(int val = 0) {
    smin = div = val;
    scount = 1;
  }
  Node(int smin_, int scount_, int div_) {
    smin = smin_;
    scount = scount_;
    div = div_;
  }
  Node operator + (Node oth) {
    Node result;
    if(smin == oth.smin)
      result = {smin, scount + oth.scount, std::__gcd(div, oth.div)};
    else if(smin < oth.smin)
      result = {smin, scount, std::__gcd(div, oth.div)};
    else
      result = {oth.smin, oth.scount, std::__gcd(div, oth.div)};
    return result;
  }
};
int v[1 + nmax];

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

  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++)
    std::cin >> v[i];
  SegmentTree aint(n);
  for(int i = 1;i <= n; i++)
    aint.update(1, 1, n, i, v[i]);
  int q;
  std::cin >> q;
  for(int i = 1; i <= q; i++) {
    int x, y;
    std::cin >> x >> y;
    Node sol = aint.query(1, 1, n, x, y);
    if(sol.div == sol.smin)
      std::cout << y - x + 1 - sol.scount << '\n';
    else
      std::cout << y - x + 1 << '\n';
  }
  return 0;
}