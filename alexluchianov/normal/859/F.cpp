#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 200000;
ll s[5 + nmax], s2[5 + nmax];
ll sums[5 + nmax], sums2[5 + nmax];

class SegmentTree{
private:
  std::vector<ll> aint;
  std::vector<ll> lazy;
public:
  void cleannode(int node, int from, int to) {
    if(from < to) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node] = aint[node] + lazy[node];
    lazy[node] = 0;
  }
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }
 
  void update(int node, int from, int to, int x, int y, ll val) {
    if(from == x && to == y) {
      lazy[node] += val;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        update(node * 2, from, mid, x, std::min(y, mid), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, std::max(mid + 1, x) , y, val);
      aint[node] = std::max(aint[node * 2], aint[node * 2 +1]);
    }
  }
 
  ll query(int node, int from, int to, int x, int y) {
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
        return std::max(query(node * 2, from, mid, x, mid),
               query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }
  }
};
ll dp[5 + nmax], sumdp[5 + nmax];

int main() {
  int n;
  ll total;
  std::cin >> n >> total;
  for(int i = 1;i < 2 * n; i++) {
    int val;
    std::cin >> val;
    if(i % 2 == 1)
      s[(i + 1) / 2] = val;
    else
      s2[i / 2] = val;
  }
  for(int i = 1;i <= n; i++)
    sums[i] = sums[i - 1] + s[i];
  for(int i = 1;i <= n; i++)
    sums2[i] = sums2[i - 1] + s2[i];
  
  SegmentTree aint(n);

  for(int i = 1; i <= n; i++) {
    dp[i] = std::min(total, s[i]);
    int start = i + 1;
    for(int jump = (1 << 20); 0 < jump; jump /= 2)
      if(0 < start - jump && sums[i] - sums[start - jump - 1] + sums2[i - 1] - sums2[start - jump - 1] <= total)
        start -= jump;
    ll acc = sums[i] + sums2[i - 1];
    if(2 <= start) {
      acc -= sums[start - 2];
      acc -= sums2[start - 2];
    }
    ll acc2 = sumdp[i - 1];
    if(2 <= start)
      acc2 -= sumdp[start - 2];

    dp[i] = std::max(dp[i], std::min(acc, total) - acc2);

    if(start < i)
      dp[i] = std::max(dp[i], s[i] + aint.query(1, 1, n, start, i - 1));
    
    aint.update(1, 1, n, 1, i, s[i] + s2[i] - dp[i]);
    sumdp[i] = sumdp[i - 1] + dp[i];
  }

  ll result = 0;
  for(int i = 1;i <= n; i++)
    result += dp[i];
  std::cout << result << '\n';
  return 0;
}