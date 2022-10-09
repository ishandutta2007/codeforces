#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <set>

using ll = long long;

struct Event{
  int type;
  int x;
  int y;
  int id;
  bool operator < (Event const oth) {
    if(x != oth.x)
      return x < oth.x;
    else if(type != oth.type) 
      return type < oth.type;
    else
      return y < oth.y;
  }
};

class SegmentTree{
  private:
    struct Node{
      int from;
      int to;
      int val;
      int lazy;
      Node* left;
      Node* right;
      Node(int from_, int to_) {
        from = from_;
        to = to_;
        val = to - from + 1;
        lazy = 1;
        left = right = nullptr;
      }
    };

    void cleanNode(Node* &node) {
      assert(node != nullptr);
      int mid = (node->from + node->to) / 2;
      if(node->from < node->to) {
        if(node->left == nullptr)
          node->left = new Node(node->from, mid);
        if(node->right == nullptr)
          node->right = new Node(mid + 1, node->to);
        if(node->lazy == 0) {
          node->left->lazy = 0;
          node->right->lazy = 0;
        }
      }

      if(node->lazy == 0) {
        node->val = 0;
      }
    }
    void computeNode(Node* &node) {
      assert(node != nullptr);
      if(node->from < node->to) {
        int mid = (1LL * node->from + node->to) / 2;
        node->val = 0;
        if(node->left == nullptr)
          node->left = new Node(node->from, mid);
        node->val += node->left->val;
        if(node->right == nullptr)
          node->right = new Node(mid + 1, node->to);
        node->val += node->right->val;
      }
    }

    void eraseInterval(Node* &node, int x, int y) {
      if(x == node->from && node->to == y) {
        node->lazy = 0;
        cleanNode(node);
      } else {
        int mid = (node->from + node->to) / 2;
        cleanNode(node);
        if(x <= mid)
          eraseInterval(node->left,  x, std::min(y, mid));
        else
          cleanNode(node->left);
        if(mid + 1 <= y)
          eraseInterval(node->right, std::max(mid + 1, x), y);
        else
          cleanNode(node->right);

        computeNode(node);
      }
    }

    int _query(Node* &node, int x) {
      cleanNode(node);
      if(node->from < node->to) {
        int mid = (node->from + node->to) / 2;
        if(x <= mid) 
          return _query(node->left, x);
        else
          return _query(node->right, x);
      } else
        return node->val;
    }

    int _kth(Node* &node, int x) {
      if(node->from < node->to) {
        int mid = (node->from + node->to) / 2;
        cleanNode(node);
        if(node->left->val < x)
          return _kth(node->right, x - node->left->val);
        else
          return _kth(node->left, x);
      } else
        return node->from;
    }

  public:
    Node* root;
    SegmentTree(int from_, int to_) {
      root = new Node(from_, to_);
    }
    void update(int x, int y) {
      eraseInterval(root, x, y);
    }
    int query(int x) {
      return _query(root, x);
    }
    int kth(int x) {
      return _kth(root, x);
    }
};

int const nmax = 100000;
int const inf = 1000000000 + nmax;
std::set<std::pair<int,int>> instant;

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  std::vector<Event> events;
  std::vector<int> lines;

  for(int i = 1;i <= n; i++) {
    Event val;
    val.type = 1;
    std::cin >> val.x >> val.y;
    val.id = i;
    events.push_back(val);
    lines.push_back(val.x);
    instant.insert({val.x, val.y});
  }
  for(int i = 1;i <= m; i++) {
    Event val;
    val.type = 2;
    std::cin >> val.x >> val.y;
    val.id = i - 1;
    events.push_back(val);
    lines.push_back(val.x);
    val.type = 0;
    events.push_back(val);
  }

  std::sort(lines.begin(), lines.end());
  lines.erase(std::unique(lines.begin(), lines.end()), lines.end());

  std::sort(events.begin(), events.end());
  std::vector<int> sol(m);
  SegmentTree aint(0, inf);
  int last = -1, ptr = 0;
  
  for(int i = 0; i < lines.size(); i++) {
    if(last + 1 < lines[i]) {
      aint.update(0, aint.kth(lines[i] - last - 1));
    }
    bool updated = false;
    while(ptr < events.size() && events[ptr].x == lines[i]) {
      Event event = events[ptr];
      if(event.type == 0) {
        if(instant.find({event.x, event.y}) != instant.end())
          sol[event.id] = 1;
        sol[event.id] |= aint.query(event.y);
      } else {
        if(event.type == 1) {
          if(event.y <= aint.kth(1))
            updated = true;
          aint.update(event.y, event.y);
          if(updated == false) {
            updated = true;
            aint.update(0, aint.kth(1));
          }
        } else {
          if(updated == false) {
            updated = true;
            aint.update(0, aint.kth(1));
          }
          sol[event.id] |= 2 * aint.query(event.y);
        }
      }
      ptr++;
    }
    if(updated == false) {
      updated = true;
      aint.update(0, aint.kth(1));
    }
    last = lines[i];
  }
  for(int i = 0; i < m; i++) {
    if(sol[i] == 1)
      std::cout << "LOSE\n";
    else
      std::cout << "WIN\n";
  }
  return 0;
}