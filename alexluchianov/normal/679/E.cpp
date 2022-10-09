#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100000;
int const sigma = 42;
ll const inf = 1000000000000000000;

std::vector<ll> powp;

void precompute() {
  powp.push_back(1);
  while(powp.back() < inf / sigma) {
    powp.push_back(powp.back() * sigma);
  }
}

struct Node{
  ll smin;
  ll target;
  int left;
  int right;

  Node(ll val = 0, int left_ = 0, int right_ = 0) {
    for(int j = 0; j < powp.size(); j++)
      if(val <= powp[j]) {
        smin = powp[j] - val;
        target = powp[j];
        left = left_;
        right = right_;
        return ;
      }
    smin = 0;
    target = 0;
    left = left_;
    right = right_;
  }

  Node(ll smin_, ll target_, int left_, int right_) {
    smin = smin_;
    target = target_;
    left = left_;
    right = right_;
  }

  Node operator + (Node const oth) {
    if(smin == oth.smin && target == oth.target && right == oth.left - 1)
      return {smin, target, left, oth.right};
    else if(smin <= oth.smin)
      return *this;
    else
      return oth;
  }

  Node operator + (ll const oth) {
    if(oth == 0)
      return *this;
    else if(oth < 0)
      return Node(-oth, left, right);
    else
      return {smin - oth, target, left, right};
  }
};

ll join(ll f1, ll f2) {
  if(0 == f2)
    return f1;
  else if(f2 < 0)
    return f2;
  else if(0 <= f1)
    return f1 + f2;
  else
    return f1 - f2;
}

class SegmentTree{
  private:
    std::vector<Node> aint;
    std::vector<ll> lazy;
  public:
    SegmentTree(int n) {
      aint.resize(1 + 4 * n);
      lazy.resize(1 + 4 * n);
    }
    void cleannode(int node, int from, int to) {
      if(lazy[node] == 0)
        return ;
      if(from < to) {
        int mid = (from + to) / 2;
        lazy[node * 2] = join(lazy[node * 2], lazy[node]);
        lazy[node * 2 + 1] = join(lazy[node * 2 + 1], lazy[node]);
      }
      aint[node] = aint[node] + lazy[node];
      lazy[node] = 0;
    }
    void build(int node, int from, int to) {
      if(from < to) {
        int mid = (from + to) / 2;
        build(node * 2, from, mid);
        build(node * 2 + 1, mid + 1, to);
      } else
        aint[node] = {0, 0, from, to};
    }
    void update(int node, int from, int to, int x, int y, ll val) {
      if(x == from && to == y) {
        lazy[node] = join(lazy[node], val);
        cleannode(node, from, to);
      } else {
        int mid = (from + to) / 2;
        cleannode(node * 2, from, mid);
        cleannode(node * 2 + 1, mid + 1, to);
        if(x <= mid)
          update(node * 2, from, mid, x, std::min(mid, y), val);
        if(mid + 1 <= y)
          update(node * 2 + 1, mid + 1, to, std::max(mid + 1, x), y, val);
        aint[node] = aint[node * 2] + aint[node * 2 + 1];
      }
    }

    Node query(int node, int from, int to, int x, int y) {
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
int v[5 + nmax];

int main() {
  precompute();
  int n, q;
  std::cin >> n >> q;
  SegmentTree aint(n);
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];

  aint.build(1, 1, n);

  for(int i = 1; i <= n; i++)
    aint.update(1, 1, n, i, i, -v[i]);

  for(int i = 1; i <= q; i++) {
    int op;
    std::cin >> op;
    if(op == 1) {
      int x;
      std::cin >> x;
      Node sol = aint.query(1, 1, n, x, x);
      std::cout << sol.target - sol.smin << '\n';
    } else if(op == 2) {
      int a, b, x;
      std::cin >> a >> b >> x;
      aint.update(1, 1, n, a, b, -x);
    } else if(op == 3) {
      int a, b, x;
      std::cin >> a >> b >> x;
      bool flag = true;
      while(flag == true) {
        aint.update(1, 1, n, a, b, x);

        Node sol = aint.query(1, 1, n, 1, n);
        while(sol.smin < 0) {
          aint.update(1, 1, n, sol.left, sol.right, -(sol.target - sol.smin));
          sol = aint.query(1, 1, n, 1, n);
        }
        flag = (sol.smin == 0);
      }
    }
  }
  return 0;
}