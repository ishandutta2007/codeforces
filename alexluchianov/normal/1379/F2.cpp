#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <set>
#include <map>

using ll = long long;

int const nmax = 200000;

struct Node{
  bool result;
  int smin;
  int smax;
  
  Node() {
    result = false;
    smin = nmax;
    smax = -1;
  }
  Node(int smin_, int smax_) {
    result = (smin_ <= smax_);
    smin = smin_;
    smax = smax_;
  }
  Node operator + (const Node oth) {
    Node answer;
    answer.result = (result | oth.result | (smin <= oth.smax));
    answer.smin = std::min(smin, oth.smin);
    answer.smax = std::max(smax, oth.smax);
    return answer;
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
  bool query() {
    return aint[1].result;
  }
};

std::set<int> activeR[5 + nmax], activeL[5 + nmax];
std::map<std::pair<int,int>,int> mp;

void toggle(int n, int m, int x, int y, SegmentTree &aint) {
  if(mp[{x, y}] == 1) {
    mp[{x, y}] = 0;
    if((y & 1) == 0)
      activeR[y / 2].erase(x / 2);
    else
      activeL[y / 2].erase(x / 2);
  } else {
    mp[{x, y}] = 1;
    if((y & 1) == 0)
      activeR[y / 2].insert(x / 2);
    else
      activeL[y / 2].insert(x / 2);
  }
  aint.update(1, 0, m - 1, y / 2, {*activeR[y / 2].begin(), *activeL[y / 2].rbegin()});
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m, q;
  std::cin >> n >> m >> q;
  SegmentTree aint(1 + m);
  
  for(int i = 0;i < m; i++)
    activeL[i].insert(-1);
  for(int i = 0;i < m; i++)
    activeR[i].insert(nmax + 1);

  for(int i = 1; i <= q; i++) {
    int x, y;
    std::cin >> x >> y;
    x--;
    y--;
    toggle(n, m, x, y, aint);
    if(aint.query())
      std::cout << "NO\n";
    else
      std::cout << "YES\n";

  }
  
  return 0;
}