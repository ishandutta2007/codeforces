#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <set>

using ll = long long;

class SegmentTree{
private:
  std::vector<int> aint;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
  }
  void computenode(int node, int from, int to) {
    if(from < to)
      aint[node] = std::max(aint[node * 2], aint[node * 2 + 1]);
  }

  void update(int node, int from, int to, int x, int val) {
    if(from < to) {
      int mid = ((from + to) >> 1);
      if(x <= mid)
        update(node * 2, from, mid, x, val);
      else
        update(node * 2 + 1, mid + 1, to, x, val);
      computenode(node, from, to);
    } else
      aint[node] = val;

  }

  int query(int node, int from, int to, int x, int y) {
    if(y < x)
      return 0;

    if(from == x && to == y)
      return aint[node];
    else {
      int mid = ((from + to) >> 1);
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return std::max(query(node * 2, from, mid, x, mid),
                        query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }
  }
};

int const nmax = 100000;

int v[1 + nmax], dp[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  int lim = m + 100;
  SegmentTree aint(1 + n), aint2(1 + lim);
  std::set<std::pair<int,int>> sortedbypos,  sortedbyval;

  for(int step = 1;step <= m; step++) {
    int op, pos, val;
    std::cin >> op;
    if(op == 1) {
      std::cin >> pos >> val;
      val = val - step + m;
      v[pos] = val;

      sortedbypos.insert({pos, val});
      sortedbyval.insert({val, pos});
    } else {
      std::cin >> pos;
      std::set<std::pair<int,int>>::iterator it = sortedbypos.begin();
      for(int j = 1; j < pos; j++)
        it++;
      std::pair<int,int> sol = *it;
      
      aint.update(1, 1, n, sol.first, 0);
      aint2.update(1, 1, lim, sol.second, 0);

      sortedbypos.erase(sol);
      std::swap(sol.first ,sol.second);
      sortedbyval.erase(sol);
    }
    
    std::vector<std::pair<int,int>> events;
    std::set<std::pair<int,int>>::iterator it = sortedbypos.begin();
    for(int j = 0; j < 10 && it != sortedbypos.end(); j++) {
      events.push_back({it->first, 1});
      it++;
    }
    it = sortedbyval.begin();
    for(int j = 0; j < 10 && it != sortedbyval.end(); j++) {
      events.push_back({it->second, 2});
      it++;
    }

    std::sort(events.begin(), events.end());
    std::reverse(events.begin(), events.end());
    

    for(int i = 0; i < events.size(); i++) {
      if(0 == i || events[i].first != events[i - 1].first) {
        int pos = events[i].first;
        aint.update(1, 1, n, pos, 0);
        aint2.update(1, 1, lim, v[pos], 0);
      }
    }
    
    for(int i = 0; i < events.size(); i++) {
      if(0 == i || events[i].first != events[i - 1].first) {
        int pos = events[i].first;
        int result = 1;
        for(int j = 0; j < i; j++)
          if(v[pos] < v[events[j].first])
            result = std::max(result, dp[events[j].first] + 1);
        if(events[i].second == 1)
          result = std::max(result, 1 + aint2.query(1, 1, lim, v[pos] + 1, lim));
        else
          result = std::max(result, 1 + aint.query(1, 1, n, pos + 1, n));
        dp[pos] = result;
      }
    }

    for(int i = 0; i < events.size(); i++) {
      if(0 == i || events[i].first != events[i - 1].first) {
        int pos = events[i].first;
        aint.update(1, 1, n, pos, dp[pos]);
        aint2.update(1, 1, lim, v[pos], dp[pos]);
      }
    }
    std::cout << aint.query(1, 1, n, 1, n) << '\n';
  }
  return 0;
}