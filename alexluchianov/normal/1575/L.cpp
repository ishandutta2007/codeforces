#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cassert>

using ll = long long;

int const nmax = 200000;

class SegmentTree{
private:
  std::vector<std::set<std::pair<int,int>>> aint;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
  }

  void insert(std::set<std::pair<int,int>> &myset, std::pair<int,int> sol) {

    std::set<std::pair<int,int>>::iterator it = myset.lower_bound({sol.first, 0}), it2;
    it2 = it;
    if(it != myset.end()) {
      if(sol.second <= it->second) {
        return ;
      }
    }
    if(it2 != myset.begin()) {
      it2--;
      while(it2 != myset.begin() && it2->second <= sol.second) {
        myset.erase(it2--);
      }
      if(it2->second <= sol.second)
        myset.erase(it2);
    }
    if(it != myset.end() && it->first == sol.first)
      myset.erase(it);
    myset.insert(sol);
  }

  void update(int node, int from, int to, int x, std::pair<int,int> sol) {
    if(from < to) {
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, sol);
      else
        update(node * 2 + 1, mid + 1, to, x, sol);
    }
    insert(aint[node], sol);
  }

  int _query(std::set<std::pair<int,int>> &myset, int target) {
    std::set<std::pair<int,int>>::iterator it = myset.lower_bound({target, 0});
    if(it == myset.end())
      return 0;
    else
      return it->second;
  }

  int query(int node, int from, int to, int x, int y, int target) {
    if(from == x && to == y) {
      return _query(aint[node], target);
    } else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y, target);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y, target);
      else
        return std::max(query(node * 2, from, mid, x, mid, target),
                        query(node * 2 + 1, mid + 1, to, mid + 1, y, target));
    }
  }
};
int v[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++)
    std::cin >> v[i];
  int lim = nmax;
  SegmentTree aint(1 + lim);
  int answer = 0;
  aint.update(1, 0, lim, 0, {0, 1});
  for(int i = 1;i <= n; i++) {
    int result = aint.query(1, 0, lim, 0, v[i] - 1, v[i] - i);
    if(0 < result) {
      aint.update(1, 0, lim, v[i], {v[i] - i, result + 1});
    }
    answer = std::max(answer, result);
  }
  std::cout << answer << '\n';
  return 0;
}