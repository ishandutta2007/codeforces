#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <queue>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 250000;
ll const inf = 2000000000;

struct Star{
  ll dist;
  ll range;
  ll power;
  ll weight;
  bool operator < (Star const &a) const {
    return dist < a.dist;
  }
} v[1 + nmax];

class SegmentTree{
public:
  std::vector<std::pair<int,int>> aint;
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
  }
  void update(int node, int from, int to, int x, std::pair<int,int> val) {
    if(from < to) {
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, val);
      else
        update(node * 2 + 1, mid + 1, to, x, val);
      aint[node] = std::min(aint[node * 2], aint[node * 2 + 1]);
    } else
      aint[node] = val;
  }
  std::pair<int,int> query(int node, int from, int to , int x, int y) {
    if(from == x && to == y)
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

int seen[1 + nmax];

int get_range(int n, ll range) {
  int x = 0;
  for(int jump = (1 << 20); 0 < jump; jump /= 2)
    if(x + jump <= n && v[x + jump].dist <= range)
      x += jump;
  return x;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int originx, originy, n;
  std::cin >> originx >> originy >> v[0].power >> v[0].range >> n;
  v[0].range = 1LL * v[0].range * v[0].range;
  v[0].dist = 0;
  for(int i = 1;i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    v[i].dist = 1LL * (x - originx) * (x - originx) + 1LL * (y - originy) * (y - originy);
    std::cin >> v[i].weight >> v[i].power >> v[i].range;
    v[i].range = 1LL * v[i].range * v[i].range;
  }
  std::sort(v + 1, v + n + 1);
  std::queue<int> q;
  q.push(0);
  seen[0] = 1;
  int result = 0;
  SegmentTree aint(n);
  
  for(int i = 1;i <= n; i++)
    aint.update(1, 1, n, i, {v[i].weight, i});

  while(0 < q.size()) {
    int node = q.front();
    int lim = get_range(n, v[node].range);
    q.pop();
    if(0 == lim)
      continue;
    while(true) {
      int id = aint.query(1, 1, n, 1, lim).second;
      if(seen[id] == 0 && v[id].weight <= v[node].power) {
        q.push(id);
        result++;
        seen[id] = 1;
        aint.update(1, 1, n, id, {inf, id});
      } else
        break;
    }
  }
  std::cout << result;
}