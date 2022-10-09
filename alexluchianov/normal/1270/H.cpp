#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using ll = long long;

class SegmentTree{
  private:
    struct Node {
      int sum;
      std::pair<int,int> smin;
      Node(std::pair<int,int> init = {0, 0}) {
        sum = init.first;
        smin = {init.first, init.second};
      }
      Node operator + (Node const oth) {
        Node result;
        result.sum = sum + oth.sum;
        result.smin = oth.smin;
        if(smin.first + oth.sum < result.smin.first || result.smin.second == 0)
          result.smin = {smin.first + oth.sum, smin.second};
        else if((smin.first + oth.sum) == result.smin.first)
          result.smin.second += smin.second;
        return result;
      }
    };
    std::vector<Node> aint;
  public:
    SegmentTree(int n) {
      aint.resize(1 + 4 * n);
    }
    void update(int node, int from, int to, int x, std::pair<int,int> val) {
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
    Node _query(int node, int from, int to, int x, int y) {
      if(from == x && to == y)
        return aint[node];
      else {
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
      return _query(node, from, to, x, y).smin.second;
    }
    int query2(int node, int from, int to, int x, int y) {
      return _query(node, from, to, x, y).smin.first;
    }
};

int const nmax = 500000;
int const lim = 1000000;
int v[5 + nmax];

void reevaluate(int lim, int pos, SegmentTree &aint) {
  int score = 0;
  if(v[pos] < v[pos - 1]) 
    score--;
  else 
    score++;
  if(v[pos] < v[pos + 1])
    score--;
  else
    score++;
  aint.update(1, 1, lim, v[pos], {score, 1});
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  for(int i = 1; i <= n; i++)
    std::cin >> v[i];
  v[0] = lim + 1;

  SegmentTree aint(1 + lim);
  for(int i = 1;i <= n; i++)
    reevaluate(lim, i, aint);

  for(int i = 1; i <= q; i++) {
    int pos, val;
    std::cin >> pos >> val;
    aint.update(1, 1, lim, v[pos], {0, 0});
    v[pos] = val;
    reevaluate(lim, pos, aint);
    if(1 < pos)
      reevaluate(lim, pos - 1, aint);
    if(pos < n)
      reevaluate(lim, pos + 1, aint);
    std::cout << aint.query(1, 1, lim, 1, lim) << '\n';
  }
  return 0;
}