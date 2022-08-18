#include <iostream>

const int MAX_DEPTH = 30;

using namespace std;

int bit_at (int mask, int bit) {
  return 1 & (mask >> bit);
}

struct node {
  int val, depth;
  node *children [2];

  node (int _depth) {
    depth = _depth;
    val = 0;

    for (int k = 0; k < 2; k++) {
      children[k] = nullptr;
    }
  }

  void insert (int val) {
    if (depth < 0) {
      return;
    }

    for (int k = 0; k < 2; k++) {
      if (children[k] == nullptr) {
        children[k] = new node (depth - 1);
      }
    }
    
    children[!bit_at(val, depth)]->val++;
    children[bit_at(val, depth)]->insert(val);
  }

  void erase (int val) {
    if (depth < 0) {
      return;
    }

    for (int k = 0; k < 2; k++) {
      if (children[k] == nullptr) {
        children[k] = new node (depth - 1);
      }
    }
    
    children[!bit_at(val, depth)]->val--;
    children[bit_at(val, depth)]->erase(val);
  }
};

int main () {
  ios::sync_with_stdio(false);

  node root (MAX_DEPTH);
  
  int queryc;
  cin >> queryc;

  for (int i = 0; i < queryc; i++) {
    int query;
    cin >> query;

    if (query == 1) {
      int personality;
      cin >> personality;
      
      root.insert(personality);
    } else if (query == 2) {
      int personality;
      cin >> personality;

      root.erase(personality);
    } else if (query == 3) {
      int personality, leadership;
      cin >> personality >> leadership;

      int ans = 0, cur_xor = personality ^ leadership;
      node *cur = &root;

      for (int i = MAX_DEPTH; i >= 0; i--) {
        if (cur->children[bit_at(cur_xor, i)] == nullptr) {
          break;
        }

        cur = cur->children[bit_at(cur_xor, i)];
        ans += bit_at(leadership, i) * cur->val;
      }

      cout << ans << '\n';
    }
  }
}