#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using ll = long long;

std::mt19937 rnd(std::chrono::high_resolution_clock().now().time_since_epoch().count());

int const nmax = 300000;
int const inf = 1000000000;

int random(int lim) {
  return std::uniform_int_distribution<int>(0, lim)(rnd);
}

class Treap{
  struct Node{
    int val;
    int prio;
    int lazy;
    Node* left;
    Node* right;
    Node(int val_) {
      val = val_;
      prio = random(inf);
      lazy = 0;
      left = right = nullptr;
    }
  };
  
  void cleannode(Node* &node) {
    if(node == nullptr)
      return ;
    if(node->left != nullptr)
      node->left->lazy += node->lazy;
    if(node->right != nullptr)
      node->right->lazy += node->lazy;
    node->val += node->lazy;
    node->lazy = 0;
  }

  Node* join(Node* &left, Node* &right) {
    if(left == nullptr && right == nullptr)
      return nullptr;
    else if(left == nullptr)
      return right;
    else if(right == nullptr)
      return left;
    else {
      cleannode(left);
      cleannode(right);
      if(left->prio < right->prio) {
        left->right = join(left->right, right);
        return left;
      } else {
        right->left = join(left, right->left);
        return right;
      }
    }
  }
  std::pair<Node*, Node*> split(Node* &node, int target) {
    if(node == nullptr)
      return {nullptr, nullptr};
    else {
      cleannode(node);
      if(node->val <= target) {
        std::pair<Node*, Node*> sol = split(node->right, target);
        node->right = sol.first;
        return {node, sol.second};
      } else {
        std::pair<Node*, Node*> sol = split(node->left, target);
        node->left = sol.second;
        return {sol.first, node};
      }
    }
  }
  Node* eraselowest(Node* &node) {
    if(node == nullptr)
      return nullptr;
    else {
      cleannode(node);
      if(node->left != nullptr) {
        node->left = eraselowest(node->left);
        return node;
      } else
        return node->right;
    }
  }
  Node* root = nullptr;
public:
  void update(int from, int to) {
    std::pair<Node*, Node*> sol2 = split(root, to - 1);
    std::pair<Node*, Node*> sol3 = split(sol2.first, from - 1);
    Node* newnode = new Node(from - 1);
    sol3.second = join(newnode, sol3.second);
    sol3.second->lazy++;
    sol2.first = join(sol3.first, sol3.second);
    sol2.second = eraselowest(sol2.second);
    root = join(sol2.first, sol2.second);
  }
  int _getsz(Node* &node) {
    if(node == nullptr)
      return 0;
    else {
      return _getsz(node->left) + _getsz(node->right) + 1;
    }
  }
  int getsz() {
    return _getsz(root);
  }
  
  void _print(Node* &node) {
    if(node == nullptr)
      return ;
    cleannode(node);
    _print(node->left);
    std::cout << node->val << " ";
    _print(node->right);
  }
  void print() {
    std::cout << "Print\n";
    _print(root);
    std::cout << '\n';
  }
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  Treap treap;
  for(int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    treap.update(x, y);
  }
  std::cout << treap.getsz() << '\n';
  return 0;
}