#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

class SegmentTree{
private:
  struct Node{
    ll val[2][2];
    Node(int number = 0) {
      val[0][0] = number;
      val[0][1] = val[1][0] = 0;
      val[1][1] = -number;
    }
    Node operator + (Node a) {
      Node result;
      for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
          result.val[i][j] = std::max(val[i][0] + a.val[1][j], val[i][1] + a.val[0][j]);
      return result;
    }
  };
  std::vector<Node> aint;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
  }
  void build(int node, int from, int to, std::vector<int> &aux) {
    if(from < to) {
      int mid = (from + to) / 2;
      build(node * 2, from, mid, aux);
      build(node * 2 + 1, mid + 1, to, aux);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    } else
      aint[node] = aux[from];
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
  ll query() {
    return std::max(aint[1].val[0][0], aint[1].val[0][1]);
  }
};

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> v(n + 1);
  for(int i = 1; i <= n; i++)
    std::cin >> v[i];
  SegmentTree aint(n);
  aint.build(1, 1, n, v);
  std::cout << aint.query() << '\n';
  for(int i = 1;i <= q; i++) {
    int x, y;
    std::cin >> x >> y;
    std::swap(v[x], v[y]);
    aint.update(1, 1, n, x, v[x]);
    aint.update(1, 1, n, y, v[y]);
    std::cout << aint.query() << '\n';
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}