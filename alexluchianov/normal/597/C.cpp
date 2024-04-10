#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
 
using ll = long long;
 
class SegmentTree{
private:
  std::vector<ll> aint;
  int n;
 
  ll join(ll x, ll y) {
    return x + y;
  }
  
  void _update(int node, int from, int to, int x, ll val) {
    if(from < to) {
      int mid = (from + to) / 2;
      if(x <= mid)
        _update(node * 2, from, mid, x, val);
      else
        _update(node * 2 + 1, mid + 1, to, x, val);
      aint[node] = join(aint[node * 2], aint[node * 2 + 1]);
    } else
      aint[node] = val;
  }
 
  ll _query(int node, int from, int to, int x, int y) {
    if(from == x && to == y) {
      return aint[node];
    } else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return _query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return _query(node * 2 + 1, mid + 1, to, x, y);
      else
        return join(_query(node * 2, from, mid, x, mid),
                    _query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }
  }
  
  void _print(int node, int from, int to) {
    if(from < to) {
      int mid = (from + to) / 2;
      _print(node * 2, from, mid);
      _print(node * 2 + 1, mid + 1, to);
    } else
      std::cout << aint[node] << " ";
  }
 
public:
  SegmentTree(int n_ = 0) {
    n = n_;
    aint.resize(1 + 4 * n);
  }
  
  void update(int x, ll val) {
    _update(1, 0, n, x, val);
  }
  
  ll query(int x, int y) {
    return _query(1, 0, n, x, y);
  }
 
  void print() {
    std::cout << "Print array\n";
    _print(1, 1, n);
    std::cout << '\n';
  }
};

int const kmax = 10;
SegmentTree dp[5 + kmax];

int main() {
  int n, k;
  std::cin >> n >> k;
  k++;
  for(int i = 0;i <= k; i++)
    dp[i] = SegmentTree(n);
  
  dp[0].update(0, 1);

  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    for(int j = 1; j <= k; j++)
      dp[j].update(val, dp[j - 1].query(0, val - 1));
  }
  
  std::cout<< dp[k].query(0, n) << '\n';

  return 0;
}