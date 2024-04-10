#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
int const inf = 1000000000;

class SegmentTree{
private:
  std::vector<std::pair<int, int>> aint;
  std::vector<int> lazy;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }
  void cleannode(int node, int from, int to) {
    if(from < to) {
      int mid = (from + to) / 2;
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node].first += lazy[node];
    lazy[node] = 0;
  }
  void build(int node, int from, int to, std::vector<int> &aux) {
    if(from < to) {
      int mid = (from + to) / 2;
      build(node * 2, from, mid, aux);
      build(node * 2 + 1, mid + 1, to, aux);
      aint[node] = join(aint[node * 2], aint[node * 2 + 1]);
    } else
      aint[node] = {aux[from], from};
  }
  std::pair<int,int> join(std::pair<int,int> f1, std::pair<int,int> f2) {
    if(f1.first == f2.first)
      return std::max(f1, f2);
    else
      return std::min(f1, f2);
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
        update(node * 2, from, mid, x, MIN(y, mid), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
      aint[node] = join(aint[node * 2] , aint[node * 2  + 1]);
    }
  }
  std::pair<int,int> query(int node, int from, int to, int x, int y) {
    cleannode(node, from, to);
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1,mid + 1, to, x, y);
      else
        return join(query(node * 2, from, mid, x, mid),
                    query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }

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
    for(int x = pos;0 < x; x = (x & (x - 1)))
      result += aib[x];
    return result;
  }
};

struct Event{
  int type;
  int time;
  int lim;
  int id;
  bool operator < (Event const a) {
    if(time != a.time)
      return a.time < time;
    else
      return type < a.type;
  }
};

int main() {
  int n, q;
  std::cin >> n >> q;
  SegmentTree aint(n);
  std::vector<int> v(1 + n);

  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    v[i] = i - v[i];;
    if(v[i] < 0)
      v[i] = inf;
  }
  aint.build(1, 1, n, v);
  
  std::vector<Event> events;
  int smin = n;
  while(true) {
    std::pair<int,int> sol = aint.query(1, 1, n, 1, n);
    if(0 < sol.first)
      break;
    else {
      smin = std::min(smin, sol.second);
      aint.update(1, 1, n, sol.second, n, -1);
      aint.update(1, 1, n, sol.second, sol.second, inf);
      events.push_back({1, smin, sol.second, 0});
    }
  }
  for(int i = 1;i <= q; i++) {
    int x, y;
    std::cin >> x >> y;
    events.push_back({2, x + 1, n - y, i});
  }
  std::sort(events.begin(), events.end());
  std::vector<int> answer(1 + q);
  FenwickTree aib(n);
  for(int i = 0; i < events.size(); i++) {
    if(events[i].type == 1)
      aib.update(events[i].lim, 1);
    else
      answer[events[i].id] = aib.query(events[i].lim);
  }
  for(int i = 1;i <= q; i++)
    std::cout << answer[i] << '\n';
  std::cout << '\n';
  return 0;
}