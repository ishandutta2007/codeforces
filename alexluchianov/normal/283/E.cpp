#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
int const nmax = 100000;

class SegmentTree{
private:
  std::vector<int> aint;
  std::vector<int> lazy;
  void cleannode(int node, int from, int to) {
    if(lazy[node] == 0)
      return ;
    if(from < to) {
      lazy[node * 2] ^= lazy[node];
      lazy[node * 2 + 1] ^= lazy[node];
    }
    if(lazy[node] == 1)
      aint[node] = to - from + 1 - aint[node];
    lazy[node] = 0;
  }
  void computenode(int node, int from, int to) {
    if(from < to) {
      int mid = (from + to) / 2;
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    }
  }
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }
  void update(int node, int from, int to, int x, int y) {
    if(from == x && to == y) {
      lazy[node] ^= 1;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        update(node * 2, from, mid, x, MIN(y, mid));
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y);
      computenode(node, from, to);
    }
  }

  int query(int node, int from, int to, int x, int y) {
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

int queries[5 + nmax][2];
std::vector<int> start[5 + nmax];
std::vector<int> stop[5 + nmax];

int lowerbound(int n, int target, std::vector<int> &s) {
  int x = 0;
  for(int jump = (1 << 17); 0 < jump; jump /= 2) {
    if(x + jump <= n && s[x + jump] <= target)
      x += jump;
  }
  return x;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> s(n + 1);
  for(int i = 1;i <= n; i++)
    std::cin >> s[i];
  std::sort(s.begin() + 1, s.end());
  ll result = 1LL * n * (n - 1) * (n - 2) / 6;
  for(int i = 1;i <= m; i++) {
    std::cin >> queries[i][0] >> queries[i][1];
    queries[i][0] = lowerbound(n, queries[i][0] - 1, s) + 1;
    queries[i][1] = lowerbound(n, queries[i][1], s);
    if(queries[i][0] < queries[i][1]) {
      start[queries[i][0]].push_back(i);
      stop[queries[i][1] + 1].push_back(i);
    }
  }
  SegmentTree aint(n);

  aint.update(1, 1, n, 1, n);
  
  int suma = 0;

  for(int i = 1; i <= n; i++) {
    for(int h = 0;h < start[i].size();h++) {
      int id = start[i][h];
      aint.update(1, 1, n, queries[id][0], queries[id][1]);
      suma ^= 1;
    }
    for(int h = 0; h < stop[i].size(); h++) {
      int id = stop[i][h];
      aint.update(1, 1, n, queries[id][0], queries[id][1]);
      suma ^= 1;
    }

    aint.update(1, 1, n, i, i);
    int coef = aint.query(1, 1, n, 1, n) - suma;
    result -= 1LL * coef * (coef - 1) / 2;
  }
  std::cout << result;
  return 0;
}