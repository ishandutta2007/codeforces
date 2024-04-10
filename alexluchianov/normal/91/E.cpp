#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const domain = 1000000;

struct Line {
  int a;
  int b;
  int id;
  ll eval(int x) {
    return 1LL * a * x + b;
  }
};

Line null_line = {0, 0, 0};

Line best(Line x, Line y, int _point) {
  if(x.eval(_point) < y.eval(_point))
    return y;
  else
    return x;
}

class LiChao{
private:
  struct Node{
    Line val;
    Node* left, *right;
    Node(Line val_) {
      val = val_;
      left = right = nullptr;
    }
  };
public:
  void _update(Node* &root, int from, int to, Line val) {
    if(root == nullptr) 
      root = new Node(val);
    else {
      int mid = (from + to) / 2;
      if(root->val.eval(mid) < val.eval(mid))
        std::swap(root->val, val);
      if(from < to) {
        if(root->val.eval(from) < val.eval(from))
          _update(root->left, from, mid, val);
        if(root->val.eval(to) < val.eval(to))
          _update(root->right, mid + 1, to, val);
      }
    }
  }
  Line _query(Node* &root, int from, int to, int x) {
    if(root == nullptr)
      return null_line;
    else if(from < to) {
      int mid = (from + to) / 2;
      if(x <= mid)
        return best(root->val, _query(root->left, from, mid, x), x);
      else
        return best(root->val, _query(root->right, mid + 1, to, x), x);
    } else
      return root->val;
  }
  Node* root;
  int lim;
  LiChao(int lim_ = domain) {
    root = nullptr;
    lim = lim_;
  }
  void update(Line val){
    _update(root, 0, lim, val);
  }
  Line query(int x) {
    return _query(root, 0, lim, x);
  }
};
class SegmentTree{
private:
  std::vector<LiChao> aint;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
  }
  void update(int node, int from, int to, int x, Line val) {
    if(from < to) {
      int mid = (from + to) / 2;
      aint[node].update(val);
      if(x <= mid)
        update(node * 2, from, mid, x, val);
      else
        update(node * 2 + 1, mid + 1, to, x, val);
    } else
      aint[node].update(val);
  }

  Line query(int node, int from, int to, int x, int y, int target) {
    if(from == x && to == y)
      return aint[node].query(target);
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y, target);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y, target);
      else
        return best(query(node * 2, from, mid, x, mid, target),
                     query(node * 2 + 1, mid + 1, to, mid + 1, y, target), target);
    }
  }
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  SegmentTree aint(n);
  for(int i = 1;i <= n; i++) {
    Line val;
    val.id = i;
    std::cin >> val.b >> val.a;
    aint.update(1, 1, n, i, val);
  }
  for(int i = 1; i <= q; i++) {
    int x, y, target;
    std::cin >> x >> y >> target;
    std::cout << aint.query(1, 1, n, x, y, target).id << '\n';
  }
}