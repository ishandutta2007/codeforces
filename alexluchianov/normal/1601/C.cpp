#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 1000000;

class SegmentTree{
private:
  std::vector<int> aint;
  std::vector<int> lazy;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }
  void cleannode(int node, int from, int to) {
    if(from < to) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    } 
    aint[node] += lazy[node];
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
      aint[node] = std::min(aint[node * 2], aint[node * 2 + 1]);
    }
  }
  
  int query() {
    return aint[1];
  }
};

class FenwickTree{
private:
  std::vector<int> aib;
  int n;
public:
  FenwickTree(int n_) {
    n = n_;
    aib.resize(1 + n);
  }
  void update(int pos, int val) {
    for(int x = pos; x <= n; x += (x ^ (x & (x - 1))))
      aib[x] += val;
  }
  int query(int pos) {
    int result = 0;
    for(int x = pos; 0 < x; x = (x & (x - 1)))
      result += aib[x];
    return result;
  }
};

int v[5 + nmax];

ll solve() {
  int n, m;
  std::cin >> n >> m;
  
  SegmentTree aux(1 + n);
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  SegmentTree aint(1 + n);
  std::vector<std::pair<int,int>> events;
  
  for(int i = 1;i <= n; i++) {
    events.push_back({v[i], -i});
    events.push_back({v[i], i});
    aint.update(1, 0, n, i, n, 1);
  }

  for(int i = 1;i <= m; i++) {
    int val;
    std::cin >> val;
    events.push_back({val, 0});
  }
  std::sort(events.begin(), events.end());
  ll result = 0;
  
  int ptr = 0;
  FenwickTree aib(n);
  
  int active = 0;

  for(int i = 0; i < events.size(); i++) {
    int ev = events[i].second;
    if(ev < 0) {
      aint.update(1, 0, n, -ev, n, -1);
      result += active - aib.query(-ev);
    } else if(0 < ev) {
      aint.update(1, 0, n, 0, ev - 1, 1);
      aib.update(ev, 1);
      ++active;
    } else
      result += aint.query();
  }
  return result;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    std::cout << solve() << '\n';
  return 0;
}