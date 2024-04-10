#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;

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
        update(node * 2, from, mid, x, std::min(mid, y), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, std::max(mid + 1, x), y, val);
      aint[node] = std::min(aint[node * 2], aint[node * 2 + 1]);
    }
  }
  
  int query(int node, int from, int to, int x, int y) {
    if(from == x && to == y) {
      cleannode(node, from, to);
      return aint[node];
    } else {
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

  int find_first(int node, int from, int to, int start, int target) {
    assert(from <= start && start <= to);
    cleannode(node, from, to);
    if(from < to) {
      int mid = (from + to) / 2;
      if(from == start && target < aint[node])
        return to + 1;

      if(start <= mid) {
        int result = find_first(node * 2, from, mid, start, target);
        if(result <= mid)
          return result;
        else
          return find_first(node * 2 + 1, mid + 1, to, mid + 1, target);
      } else
        return find_first(node * 2 + 1, mid + 1, to, start, target);
    } else {
      if(aint[node] <= target)
        return from;
      else
        return from + 1;
    }
  }
};

int const nmax = 200000;
int const inf = 1000000000;

int v[5 + nmax];
std::map<int,int> frec;

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, k, d;
  std::cin >> n >> k >> d;
  
  int result = 1, resultpos = 1, lim = 1;
  
  if(d == 0) {
    int last = 1;
    for(int i = 1;i <= n; i++) {
      std::cin >> v[i];
      if(v[i - 1] != v[i])
        last = i;
      if(result < i - last + 1) {
        result = i - last + 1;
        resultpos = last;
      }
    }
    std::cout << resultpos << " " << resultpos + result - 1 << '\n';
    return 0;
  }

  SegmentTree aint(1 + n);
  std::vector<std::pair<int,int>> stmin, stmax;
  stmin.push_back({-inf - 1, 0});
  stmax.push_back({inf + 1, 0});

  
  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    int r1 = v[i - 1] % d, r2 = v[i] % d;
    if(r1 < 0)
      r1 += d;
    if(r2 < 0)
      r2 += d;

    if(r1 != r2 % d)
      lim = i;
    
    lim = std::max(lim, frec[v[i]] + 1);
    frec[v[i]] = i;
    int last = i;
    int orig = v[i];
    v[i] = (v[i] - r2) / d;

    while(0 < stmin.size() && v[i] < stmin.back().first) {
      aint.update(1, 1, n, stmin.back().second, last - 1, stmin.back().first - v[i]);
      last = stmin.back().second;
      stmin.pop_back();
    }
    stmin.push_back({v[i], last});

    last = i;
    while(0 < stmax.size() && stmax.back().first < v[i]) {
      aint.update(1, 1, n, stmax.back().second, last - 1, -stmax.back().first + v[i]);
      last = stmax.back().second;
      stmax.pop_back();
    }
    stmax.push_back({v[i], last});
    
    if(1 < i)
      aint.update(1, 1, n, 1, i - 1, -1);
    
    int pos = aint.find_first(1, 1, n, lim, k);
    if(result < i - pos + 1) {
      result = i - pos + 1;
      resultpos = pos;
    }
    v[i] = orig;
  }
  
  std::cout << resultpos << " " << resultpos + result - 1 << '\n';
  return 0;
}