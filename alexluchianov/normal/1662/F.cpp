#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <cassert>

using ll = long long;

int const nmax = 200000;
int const inf = 1000000000;

class SegmentTree{
private:
  std::vector<std::pair<int,int>> aint;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
  }
  void update(int node, int from, int to, int x, int y) {
    if(from < to) {
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, y);
      else
        update(node * 2 + 1, mid + 1, to, x, y);
      aint[node] = std::max(aint[node * 2], aint[node * 2 + 1]);
    } else
      aint[node] = {y, from};
  }
  std::pair<int,int> query(int node, int from, int to, int x, int y) {
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
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

int solve() {
  int n, source, sink;
  std::cin >> n >> source >> sink;
  std::vector<int> dp(1 + n), v(1 + n);
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  
  std::queue<int> q;
  dp[source] =1;
  q.push(source);

  SegmentTree base(1 + n), leftside(1 + n), rightside(1 + n);

  for(int i = 1; i <= n; i++) {
    base.update(1, 1, n, i, v[i]);
    leftside.update(1, 1, n, i, i + v[i]);
    rightside.update(1, 1, n, i, -(i - v[i]));
  }
 
  auto valid = [&](int x, int y) {
    return std::abs(x - y) <= std::min(v[x], v[y]);
  };
  
  auto deactivate = [&](int node) {
    base.update(1, 1, n, node, -inf);
    leftside.update(1, 1, n, node, -inf);
    rightside.update(1, 1, n, node, -inf);
  };
  
  deactivate(source);

  while(0 < q.size()) {
    int node = q.front();
    q.pop();
    int from = std::max(1, node - v[node]);
    int to = std::min(n, node + v[node]);
    while(true) {
      int target = base.query(1, 1, n, from, to).second;
      if(valid(node, target) == 1 && dp[target] == 0) {
        deactivate(target);
        dp[target] = dp[node] + 1;
        q.push(target);
      } else
        break;
    }
    while(true) {
      int target = leftside.query(1, 1, n, from, node).second;
      if(valid(node, target) == 1 && dp[target] == 0) {
        deactivate(target);
        dp[target] = dp[node] + 1;
        q.push(target);
      } else
        break;
    }
    while(true) {
      int target = rightside.query(1, 1, n, node, to).second;
      if(valid(node, target) == 1 && dp[target] == 0) {
        deactivate(target);
        dp[target] = dp[node] + 1;
        q.push(target);
      } else
        break;
    }
  }

  return dp[sink] - 1;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    std::cout << solve() << '\n';
  }
  return 0;
}