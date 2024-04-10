#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 500000;
int v[1 + nmax];
int pref[1 + nmax], suff[1 + nmax];

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
    if(lazy[node] == 0)
      return ;
    if(from < to) {
      int mid = (from + to) / 2;
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    } 
    aint[node] += lazy[node];
    lazy[node] = 0;
  }
  void computenode(int node, int from, int to) {
    if(from < to)
      aint[node] = std::min(aint[node * 2], aint[node * 2 + 1]);
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
        update(node * 2, from, mid, x, MIN(mid, y), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
      computenode(node, from, to);
    }
  }
  int query(int node, int from, int to, int x, int y) {
    cleannode(node, from, to);
    if(from == x && y == to)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return std::min(query(node * 2, from, mid, x, mid),
                        query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }
  }
};

int eval(int groups, int n) {
  if(groups == 0)
    return 1;

  int zeros = 0, acc = 0;
  for(int i = 1;i <= n; i++)
    zeros += (v[i] == 0);
  for(int i = 1;i <= n; i++) {
    pref[i] = 0;
    suff[i] = groups + 1;
  }

  for(int i = 1;i <= n; i++) {
    if(v[i] == 0)
      acc++;
    else {
      if(acc < groups)
        pref[v[i]] = std::max(pref[v[i]], acc);
      else if(groups <= acc && groups <= zeros - acc) {
        pref[v[i]] = groups;
        suff[v[i]] = 1;
      } else if(zeros - acc < groups) {
        suff[v[i]] = std::min(suff[v[i]], groups + 1 - (zeros - acc));
      }
    }
  }
  SegmentTree aint(groups);
  for(int i = 1;i <= groups; i++)
    aint.update(1, 1, groups, i, i, -i);
  std::vector<std::pair<int,int>> events;
  for(int i = 1; i <= n; i++)
    if(0 < pref[i] || suff[i] <= groups)
      events.push_back({pref[i], suff[i]});
  if(events.size() < groups)
    return 0;

  std::vector<std::vector<int>> events2(1 + groups);
  for(int i = 0; i < events.size(); i++)
    events2[events[i].first].push_back(events[i].second);
  int bonus = events.size();
  

  for(int i = 1; i <= groups; i++) {
    for(int h = 0; h < events2[i - 1].size(); h++) {
      bonus--;
      if(events2[i - 1][h] <= groups)
        aint.update(1, 1, groups, events2[i - 1][h], groups, 1);
    }
    if(aint.query(1, 1, groups, 1, groups) + bonus < 0)
      return 0;
    aint.update(1, 1, groups, 1, groups, 1);
  }
  return 1;
}

int binary_search(int from, int to, int n) {
  if(from < to) {
    int mid = (from + to + 1) / 2;
    if(eval(mid, n))
      return binary_search(mid, to, n);
    else
      return binary_search(from, mid - 1, n);
  } else
    return from;
}

void solve() {
  int n;
  std::cin >> n;
  int zeros = 0;
  for(int i = 1; i <= n; i++) { 
    std::cin >> v[i];
    zeros += (v[i] == 0);
  }
  std::cout << binary_search(0, std::min(zeros / 2, n - zeros), n) << '\n';
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