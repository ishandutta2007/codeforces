#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 120000;

class LazyTag{
public:
  int val;
  int smin;
  int scount;
  LazyTag(int val_ = 0, int smin_ = 0, int scount_ = 0) {
    val = val_;
    smin = smin_;
    scount = scount_;
  }
  LazyTag operator + (LazyTag oth) {
    LazyTag result;
    result.val = val  + oth.val;
    result.smin = std::min(smin, val + oth.smin);
    if(result.smin == smin)
      result.scount += scount;
    if(result.smin == val + oth.smin)
      result.scount += oth.scount;
    return result;
  }
};

struct Node{
  int val;
  int valcount;
  int smin;
  ll scount;
  Node(int val_ = 0, int valcount_ = 0, int smin_ = 0, int scount_ = 0) {
    val = val_;
    valcount = valcount_;
    smin = smin_;
    scount = scount_;
  }
  Node operator + (Node oth) {
    Node result;
    result.val = std::min(val, oth.val);
    if(result.val == val)
      result.valcount += valcount;
    if(result.val == oth.val)
      result.valcount += oth.valcount;
    result.smin = std::min(smin, oth.smin);
    if(result.smin == smin)
      result.scount += scount;
    if(result.smin == oth.smin)
      result.scount += oth.scount;
    return result;
  }

  Node operator + (LazyTag oth) {
    Node result;
    result.val = val + oth.val;
    result.valcount = valcount;
    result.smin = std::min(smin, val + oth.smin);
    if(result.smin == smin)
      result.scount += scount;
    if(result.smin == val + oth.smin)
      result.scount += 1LL * valcount * oth.scount;
    return result;
  }
};

class SegmentTree{
private:
  std::vector<LazyTag> lazy;
  std::vector<Node> aint;
public:
  SegmentTree(int n) {
    lazy.resize(1 + 4 * n);
    aint.resize(1 + 4 * n);
  }
  void build(int node, int from, int to) {
    if(from < to) {
      int mid = (from + to) / 2;
      build(node * 2, from, mid);
      build(node * 2 + 1, mid + 1, to);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    } else
      aint[node] = {0, 1, 0, 1};
  }
  void cleannode(int node, int from, int to) {
    if(from < to) {
      lazy[node * 2] = lazy[node * 2] + lazy[node];
      lazy[node * 2 + 1] = lazy[node * 2 + 1] + lazy[node];
    }
    aint[node] = aint[node] + lazy[node];
    lazy[node] = 0;
  }
  void update(int node, int from, int to, int x, int y, LazyTag val) {
    if(from == x && to == y) {
      lazy[node] = lazy[node] + val;
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
int v[5 + nmax];
ll sol[5 + nmax];
std::vector<std::pair<int,int>> g[5 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  SegmentTree aint(n);
  aint.build(1, 1, n);
  int q;
  std::cin >> q;
  for(int i = 1; i <= q; i++) {
    int x, y;
    std::cin >> x >> y;
    g[y].push_back({x, i});
  }
  std::vector<std::pair<int,int>> stmax, stmin;
  stmax.push_back({n + 1, 0});
  stmin.push_back({0, 0});
  for(int i = 1;i <= n; i++) {
    std::vector<std::pair<int,int>> changes;
    int last = i;
    while(0 < stmin.size() && v[i] < stmin.back().first) {
      changes.push_back({stmin.back().second, stmin.back().first - v[i]});
      changes.push_back({last, -(stmin.back().first - v[i])});
      last = stmin.back().second;
      stmin.pop_back();
    }
    stmin.push_back({v[i], last});
    last = i;
    while(0 < stmax.size() && stmax.back().first < v[i]) {
      changes.push_back({stmax.back().second, v[i] - stmax.back().first});
      changes.push_back({last, -(v[i] - stmax.back().first)});
      last = stmax.back().second;
      stmax.pop_back();
    }
    stmax.push_back({v[i], last});

    changes.push_back({1, -(i != 1)});
    changes.push_back({i, 0});
    std::sort(changes.begin(), changes.end());
    int acc = 0;
    
    for(int j = 0; j < changes.size() - 1; j++) {
      acc += changes[j].second;
      if(changes[j].first < changes[j + 1].first) {
        aint.update(1, 1, n, 
                    changes[j].first, changes[j + 1].first - 1, {acc, acc, 1});
      }
    }
    
    for(int h = 0; h < g[i].size(); h++) {
      std::pair<int,int> el = g[i][h];
      Node answer = aint.query(1, 1, n, el.first, i);
      sol[el.second] = answer.scount;
    }
  }

  for(int i = 1;i <= q; i++)
    std::cout << sol[i] << '\n';
  return 0;
}