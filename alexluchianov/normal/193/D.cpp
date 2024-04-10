#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 300000;

struct Node{
  int smin;
  int frec1, frec2;
  Node(int val = 0) {
    smin = val;
    frec1 = 1;
    frec2 = 0;
  }
  Node operator + (Node oth) const {
    Node result;
    result.smin = std::min(smin, oth.smin);
    result.frec1 = result.frec2 = 0;
    if(result.smin == smin) {
      result.frec1 += frec1;
      result.frec2 += frec2;
    } else if(result.smin + 1 == smin) 
      result.frec2 += frec1;
    if(result.smin == oth.smin) {
      result.frec1 += oth.frec1;
      result.frec2 += oth.frec2;
    } else if(result.smin + 1 == oth.smin) 
      result.frec2 += oth.frec1;
    return result;
  }
};

class SegmentTree{
  private:

    std::vector<Node> aint;
    std::vector<int> lazy;
  public:
    SegmentTree(int n) {
      aint.resize(1 + 4 * n);
      lazy.resize(1 + 4 * n);
    }
    void build(int node, int from, int to) {
      if(from < to) {
        int mid = (from + to) / 2;
        build(node * 2, from, mid);
        build(node * 2 + 1, mid + 1, to);
        aint[node] = aint[node * 2] + aint[node * 2 + 1];
      } else
        aint[node] = 0;
    }

    void cleannode(int node, int from, int to) {
      if(from < to) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
      }
      aint[node].smin += lazy[node];
      lazy[node] = 0;
    }
    void update(int node, int from, int to, int x, int y, int val) {
      if(from == x && to == y) {
        lazy[node] += val;
        cleannode(node, from, to);
      } else {
        int mid = (from + to) / 2;
        cleannode(node * 2, from, mid);
        cleannode(node * 2 + 1, mid + 1, to);
        if(x <= mid)
          update(node * 2, from, mid, x, std::min(y, mid), val);
        if(mid + 1 <= y)
          update(node * 2 + 1, mid + 1, to, std::max(mid + 1, x), y, val);
        aint[node] = aint[node * 2] + aint[node * 2 + 1];
      }
    }
    Node query(int node, int from, int to, int x, int y) {
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
          return query(node * 2, from, mid, x, mid) +
            query(node * 2 + 1, mid + 1, to, mid + 1, y);
      }
    }
};
int v[1 + nmax], rev[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++) {
    std::cin >> v[i];
    rev[v[i]] = i;
  }
  SegmentTree aint(n);
  aint.build(1, 1, n);
  ll result = 0;
  for(int i = 1;i <= n; i++) {
    aint.update(1, 1, n, 1, i, 1);
    int val = rev[i];
    if(1 < val && v[val - 1] < i)
      aint.update(1, 1, n, 1, v[val - 1], -1);
    if(val < n && v[val + 1] < i)
      aint.update(1, 1, n, 1, v[val + 1], -1);
    Node sol = aint.query(1, 1, n, 1, i);
    if(sol.smin == 1)
      result += sol.frec1 + sol.frec2;
    else if(sol.smin == 2)
      result += sol.frec1;
  }
  std::cout << result - n<< '\n';
  return 0;
}