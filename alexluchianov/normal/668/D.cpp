#include <iostream>
#include <map>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
int const nmax = 100000;
int const inf = 1000000000;

namespace DST{
  struct Node{
    int sum;
    int from;
    int to;
    Node* left;
    Node* right;
  };
  Node* emptynode = new Node{0, 0, 0, NULL, NULL};
  Node* newinstance(int from, int to){
    Node* result;
    result = new Node();
    result->sum = 0;
    result->from = from;
    result->to = to;
    result->left = result->right = emptynode;
    return result;
  }
  void computenode(Node* &root){
    root->sum = 0;
    if(root->left != emptynode)
      root->sum += root->left->sum;
    if(root->right != emptynode)
      root->sum += root->right->sum;
  }

  void update(Node* &root, int from, int to, int x, int val){
    if(root == emptynode)
      root = new Node{0, from, to, emptynode, emptynode};
    if(from < to){
      int mid = (from + to) / 2;
      if(x <= mid)
        update(root->left, from, mid, x, val);
      else
        update(root->right, mid + 1, to, x, val);
      computenode(root);
    } else
      root->sum += val;
  }

  int query(Node* &root, int from, int to, int x, int y){
    if(root == emptynode)
      return 0;
    if(from == x && to == y)
      return root->sum;
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(root->left, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(root->right, mid + 1, to, x, y);
      else
        return query(root->left, from, mid, x, mid) + query(root->right, mid + 1, to, mid + 1, y);
    }
  }
}

map<int,int> code;
DST::Node* roots[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  int ptr = 0;
  for(int i = 1;i <= n; i++){
    int op, time, val;
    cin >> op >> time >> val;
    if(code[val] == 0){
      code[val] = ++ptr;
      roots[ptr] = DST::newinstance(1, inf);
    }
    val = code[val];
    if(op == 1)
      DST::update(roots[val], 1, inf, time, 1);
    else if(op == 2)
      DST::update(roots[val], 1, inf, time, -1);
    else
      cout << DST::query(roots[val], 1, inf, 1, time) << '\n';
  }
  return 0;
}