#include <iostream>
#include <random>


int const inf = 1000000000;
std::mt19937 rng;
std::uniform_int_distribution<int> dist(0, inf);

int random(){
  return dist(rng);
}

class Treap{
private:
  struct Node{
    int key;
    int prio;
    int val;
    Node* left;
    Node* right;
    Node(int key_ = 0, int val_ = 0){
      key = key_;
      val = val_;
      prio = random();
      left = right = nullptr;
    }
  };

  std::pair<Node*, Node*> split(Node* &root, int target){
    if(root == nullptr)
      return {nullptr, nullptr};
    else if(root->key <= target){
      std::pair<Node*, Node*> sol = split(root->right, target);
      root->right = sol.first;
      return {root, sol.second};
    } else {
      std::pair<Node*, Node*> sol = split(root->left, target);
      root->left = sol.second;
      return {sol.first, root};
    }
  }

  Node* join(Node* &left, Node* &right){
    if(left == nullptr)
      return right;
    else if(right == nullptr)
      return left;
    else {
      if(left->prio < right->prio){
        right->left = join(left, right->left);
        return right;
      } else {
        left->right = join(left->right, right);
        return left;
      }
    }
  }

public:
  Node* root;
  Treap(){
    root = nullptr;
  }
  int _acces(int key){
    std::pair<Node*, Node*> sol = split(root, key);
    std::pair<Node*, Node*> sol2 = split(sol.first, key - 1);

    int result;
    if(sol2.second == nullptr)
      result = 0;
    else
      result = sol2.second->val;

    sol.first = join(sol2.first, sol2.second);
    root = join(sol.first, sol.second);
    return result;
  }

  void _insert(int key, int val){
    std::pair<Node*, Node*> sol = split(root, key);
    std::pair<Node*, Node*> sol2 = split(sol.first, key - 1);
    sol2.second = new Node(key, val);
    sol.first = join(sol2.first, sol2.second);
    root = join(sol.first, sol.second);
  }
};

int main()
{
  Treap mymap;
  int n;
  std::cin >> n;
  int smax = 0, scount = 0;
  for(int i = 1; i <= n; i++){
    int val;
    std::cin >> val;
    int app = mymap._acces(val) + 1;
    if(smax < app)
      smax = app;
    if(app == 1)
      scount++;
    mymap._insert(val, app);
  }
  std::cout << smax << " " << scount;
  return 0;
}