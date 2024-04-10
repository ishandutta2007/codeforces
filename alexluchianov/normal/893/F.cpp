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
int const inf = 1000000000;

class SegmentTree{
private:
  struct Node{
    int val;
    Node* left = NULL, *right = NULL;
    Node(int val_ = 0){
      val = val_;
      left = right = NULL;
    }
  };

  void _update(Node* &root, int from, int to, int x, int val){
    if(root == NULL)
      root = new Node(val);
    if(from < to){
      int mid = (from + to) / 2;
      if(x <= mid)
        _update(root->left, from, mid, x, val);
      else
        _update(root->right, mid + 1, to, x, val);
      root->val = min(root->val, val);
    } else
      root->val = min(root->val, val);
  }

  int _query(Node* &root, int from, int to, int x, int y){
    if(root == NULL)
      return inf;


    if(from == x && to == y)
      return root->val;
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return _query(root->left, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return _query(root->right, mid + 1, to, x, y);
      else
        return min(_query(root->left, from, mid, x, mid), _query(root->right, mid + 1, to, mid + 1, y));
    }
  }
  Node* root;
  int from, to;
public:
  SegmentTree(int n_ = 0){
    from = 1;
    to = n_;
    root = NULL;
  }
  void update(int x, int val){
    _update(root, from, to, x, val);
  }
  int query(int x, int y){
    return _query(root, from, to, x, y);
  }
};

class SegmentTreebig{
private:
  vector<SegmentTree> aint;
public:
  SegmentTreebig(int n_){
    aint.resize(1 + 4 * n_);
  }
  void build(int node, int from, int to, int lim){
    aint[node] = SegmentTree(lim);
    if(from < to){
      int mid = (from + to) / 2;
      build(node * 2, from, mid, lim);
      build(node * 2 + 1, mid + 1, to, lim);
    }
  }

  void update(int node, int from, int to, int x, int y, int val){
    if(from < to){
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, y, val);
      else
        update(node * 2 + 1, mid + 1, to, x, y, val);
    }
    aint[node].update(y, val);
  }

  int query(int node, int from, int to, int x, int y, int x2, int y2){
    if(from == x && to == y)
      return aint[node].query(x2, y2);
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y, x2, y2);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y, x2, y2);
      else
        return min(query(node * 2, from, mid, x, mid, x2, y2), query(node * 2 + 1, mid + 1, to, mid + 1, y, x2, y2));
    }
  }
};
int v[1 + nmax], level[1 + nmax];
vector<int> g[1 + nmax];
int start[1 + nmax], stop[1 + nmax];
int n, ptr = 0;

void dfs(int node, int parent, SegmentTreebig &aint){
  level[node] = level[parent] + 1;
  start[node] = ++ptr;
  aint.update(1, 1, n, ptr, level[node], v[node]);

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      dfs(to, node, aint);
  }
  stop[node] = ptr;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int root;
  cin >> n >> root;
  for(int i = 1; i <= n; i++)
    cin >> v[i];
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  SegmentTreebig aint(n);
  aint.build(1, 1, n, n);
  dfs(root, 0, aint);
  int q;
  cin >> q;
  int last = 0;
  for(int i = 1;i <= q; i++){
    int node, h;
    cin >> node >> h;
    node = (node + last) % n + 1;
    h = (h + last) % n;
    last = aint.query(1, 1, n, start[node], stop[node], level[node], min(n, level[node] + h));
    cout << last << '\n';
  }
  return 0;
}