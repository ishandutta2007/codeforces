#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
int const nmax = 100000;
class SegmentTree{
private:
  std::vector<int> aint;
  std::vector<int> lazy;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }
  void computenode(int node, int from, int to) {
    if(from < to) {
      int mid = (from + to) / 2;
      aint[node] = std::min(aint[node * 2], aint[node * 2 + 1]);
    }
  }
  
  void cleannode(int node, int from, int to) {
    if(from < to) {
      int mid = (from + to) / 2;
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node] += lazy[node];
    lazy[node] = 0;
  }

  int update(int node, int from, int to, int x, int y, int val) {
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

  int query() {
    return aint[1];
  }
};

std::map<int,int> frec, frec2, frec3;

struct Interval {
  int x;
  int y;
  int val;
  bool operator < (Interval const &a) const {
    if(x != a.x)
      return x < a.x;
    else
      return y < a.y;
  }
};


int main() {
  int n;
  std::cin >> n;
  SegmentTree aint(n);
  std::vector<int> aux;
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    aux.push_back(val);
    if(0 == frec[val])
      frec[val] = i;
  }

  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    aux.push_back(val);
    if(0 == frec2[val])
      frec2[val] = i;
  }
  for(int i = 1; i <= n; i++) {
    int val;
    std::cin >> val;
    aux.push_back(val);
    if(0 == frec3[val])
      frec3[val] = i;
  }
  std::sort(aux.begin(), aux.end());
  aux.erase(std::unique(aux.begin(), aux.end()), aux.end());
  std::vector<std::pair<int,int>> events[1 + nmax];
  
  for(int i = 0; i < aux.size(); i++) {
    if(frec[aux[i]] == 0)
      frec[aux[i]] = n + 1;
    if(frec2[aux[i]] == 0)
      frec2[aux[i]] = n + 1;
    if(frec3[aux[i]] == 0)
      frec3[aux[i]] = 3 * n + 1;
  }

  for(int i = 0; i < aux.size(); i++) {
    int val = aux[i]; 
    events[frec[val] - 1].push_back({frec2[val] - 1, frec3[val]});
  }
  for(int i = 1;i <= n; i++)
    aint.update(1, 0, n, i, i, i);

  std::set<Interval> myset;
  int result = n * 3;
  myset.insert({0, n, 0});

  for(int i = n; 0 <= i; i--) {
    for(int h = 0; h < events[i].size(); h++){
      std::pair<int,int> temp = events[i][h];
      int lim = temp.first;
      int val = temp.second;
      std::set<Interval>::iterator it = myset.lower_bound({lim + 1, 0, 0});

      std::vector<Interval> import;
      if(it != myset.begin()) {
        it--;
        while(true) {
          if(it->val < val) {
            if(it == myset.begin()) {
              import.push_back(*it);
              myset.erase(it);
              break;
            } else {
              import.push_back(*it);
              myset.erase(it--);
            }
          } else
            break;
        }
      }
      if(0 < import.size()) {
        Interval new_int;
        new_int.x = lim;
        new_int.y = lim;
        new_int.val = val;
        for(int i = 0; i < import.size(); i++) {
          if(lim < import[i].y)
            myset.insert({lim + 1, import[i].y, import[i].val});
          aint.update(1, 0, n, import[i].x, std::min(import[i].y, lim), val - import[i].val);
          new_int.x = std::min(new_int.x, import[i].x);
        }
        myset.insert(new_int);
      }
    }
   
    result = std::min(result, i + aint.query());
  }
  std::cout << result;
}