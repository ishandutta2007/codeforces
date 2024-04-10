#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 500000;
int v[5 + nmax], pos[5 + nmax];

struct Node{
  int smin;
  int smax;
  int sum;
  Node(int smin_ = nmax, int smax_ = -nmax, int sum_ = 0) {
    smin = smin_;
    smax = smax_;
    sum = sum_;
  }
  Node operator + (Node oth) {
    Node result;
    result.smin = std::min(smin + oth.sum, oth.smin);
    result.smax = std::max(smax, sum + oth.smax);
    result.sum = sum + oth.sum;
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
    void update(int node, int from, int to, int x, Node val) {
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
    int findTarget(int node, int from, int to, int bonus) {
      if(from < to) {
        int mid = (from + to) / 2;
        if(0 <= aint[node * 2].smax + bonus)
          return findTarget(node * 2, from, mid, bonus);
        else
          return findTarget(node * 2 + 1, mid + 1, to, bonus + aint[node * 2].sum);
      } else
        return from;
    }

};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  std::vector<std::pair<int,int>> aux;
  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    aux.push_back({v[i], i});
  }

  aux.push_back({-nmax - 2, 0});
  std::sort(aux.begin(), aux.end());
  for(int i = 0; i < aux.size(); i++)
    pos[aux[i].second] = i;
  
  SegmentTree aint(n);

  for(int i = 1; i <= n; i++) {
    int val = v[i];
    aint.update(1, 1, n, pos[i], {v[i], v[i], 1});
    int start = aint.findTarget(1, 1, n, 0);
     
    int result = std::min(2 * aint.query(1, 1, n, start, n).sum - i, std::max(-i, aint.query(1, 1, n, start, n).smin));
    std::cout << result << '\n';
  }
  return 0;
}