#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;

int const nmax = 100000;
ll const inf = 1000000000000000;

struct Line{
  ll a;
  ll b;
  ll eval(int x){
    return x * a + b;
  }
};

class LiChao{
private:
  struct Node{
    Line val;
    Node* left;
    Node* right;
    Node(Line val_){
      val = val_;
      left = right = NULL;
    }
  };

  void _update(Node* &root, int from, int to, Line val){
    if(root == NULL) {
      root = new Node(val);
      return ;
    }

    int mid = (from + to) / 2;
    if(val.eval(mid) < root->val.eval(mid))
      swap(root->val, val);

    if(from < to){
      if(val.eval(from) < root->val.eval(from))
        _update(root->left, from, mid, val);
      if(val.eval(to) < root->val.eval(to))
        _update(root->right, mid + 1, to, val);
    }
  }

  ll _query(Node* &root, int from, int to, int x){
    if(root == NULL)
      return inf;
    else {
      ll result = root->val.eval(x);
      int mid = (from + to) / 2;
      if(x <= mid)
        return min(result, _query(root->left, from, mid, x));
      else
        return min(result, _query(root->right, mid + 1, to, x));
    }
  }
public:
  Node* root;
  int from;
  int to;
  LiChao(int from_ = 0, int to_ = 0){
    root = NULL;
    from = from_;
    to = to_;
  }
  void addline(Line val){
    _update(root, from, to, val);
  }
  ll query(int x){
    return _query(root, from, to, x);
  }
};

class SegmentTree{
private:
  vector<LiChao> aint;
public:
  SegmentTree(int n){
    aint.resize(1 + 4 * n);
    for(int i = 1;i <= 4 * n; i++)
      aint[i] = LiChao(-nmax, nmax);
  }
  void update(int node, int from, int to, int x, Line val){
    aint[node].addline(val);
    if(from < to){
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, val);
      else
        update(node * 2 + 1, mid + 1, to, x, val);
    }
  }
  ll query(int node, int from, int to, int x, int y, int target){
    if(from == x && to == y)
      return aint[node].query(target);
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y, target);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y, target);
      else
        return min(query(node * 2, from, mid, x, mid, target), query(node * 2 + 1, mid + 1, to, mid + 1, y, target));
    }
  }
};
ll v[1 + nmax], sum[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++){
    cin >> v[i];
    sum[i] = sum[i - 1] + v[i];
  }
  SegmentTree aint(n);
  for(int i = 1; i <= n; i++)
    aint.update(1, 1, n, i, {v[i], v[i] * i - sum[i]});
  int q;
  cin >> q;
  for(int i = 1;i <= q; i++){
    int x, y;
    cin >> x >> y;
    cout << sum[y] + aint.query(1, 1, n, y - x + 1, y, x - y) << '\n';
  }
  return 0;
}