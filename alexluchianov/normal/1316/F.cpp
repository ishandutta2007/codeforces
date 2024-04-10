#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 300000;
int const modulo = 1000000007;

class SegmentTree{
private:
  struct Node{
    int result;
    int coef;
    int left;
    int right;
    Node operator + (Node const oth) {
      Node answer;
      answer.result = (1LL * result * oth.coef + 1LL * oth.result * coef +
                       1LL * left * oth.right) % modulo;
      answer.coef = 1LL * coef * oth.coef % modulo;
      answer.left = (left + 1LL * coef * oth.left) % modulo;
      answer.right = (1LL * right * oth.coef + oth.right) % modulo;
      return answer;
    }
    Node(int val_ = 0) {
      result = 0;
      coef = (0 < val_) + 1;
      left = right = val_;
    }
  };
  std::vector<Node> aint;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
  }

  void update(int node, int from, int to, int x, int val) {
    if(from < to) {
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, val);
      else
        update(node * 2 + 1, mid + 1 ,to, x, val);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    } else
      aint[node] = val;
  }

  int query() {
    return aint[1].result;
  }
};

int lgpow(int a, int b) {
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b/ 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int inverse(int number) {
  return lgpow(number, modulo - 2);
}

int v[5 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  std::vector<std::pair<int,int>> events;
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    events.push_back({val, i});
    v[i] = val;
  }
  int q;
  std::cin >> q;
  std::vector<std::pair<int,int>> queries(q);
  for(int i = 0;i < q; i++) {
    std::cin >> queries[i].first >> queries[i].second;
    events.push_back({queries[i].second, queries[i].first});
  }
  std::sort(events.begin(), events.end());
  events.erase(std::unique(events.begin(), events.end()), events.end());
  SegmentTree aint(n + q);
  
  auto getPos = [&](int x, int val) {
    return std::lower_bound(events.begin(), events.end(), std::pair<int,int>(val, x)) - events.begin();
  };
  
  int lim = n + q - 1;
  for(int i = 1;i <= n; i++)
    aint.update(1, 0, lim,  getPos(i, v[i]), v[i]);
  
  int base = inverse(lgpow(2, n));
  
  std::cout << 1LL * aint.query() * base % modulo << '\n';
  
  for(int i = 0;i < q; i++) {
    std::pair<int,int> ev = queries[i];
    int pos = ev.first;
    aint.update(1, 0, lim, getPos(pos, v[pos]), 0);
    v[pos] = ev.second;
    aint.update(1, 0, lim, getPos(pos, v[pos]), v[pos]);
    std::cout << 1LL * aint.query() * base % modulo << '\n';
  }
  return 0;
}