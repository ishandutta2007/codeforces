#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

namespace {
  template <typename Key>
    class BinomialHeap {
      private:
        struct Node{
          Key key;
          int degree;
          Node* son;
          Node* sibling;
          Node(Key key_) {
            key = key_;
            degree = 0;
            son = sibling = nullptr;
          }
          ~Node() {
            delete son;
            delete sibling;
          }
        };
        Node* generateNode(Key val) {
          return new Node(val);
        }

        Node* _mergesmall(Node* a, Node* b) {
          assert(a->degree == b->degree);
          if(a->key < b->key) {
            a->sibling = b->son;
            b->son = a;
            b->degree++;
            return b;
          } else {
            b->sibling = a->son;
            a->son = b;
            a->degree++;
            return a;
          }
        }

        Node* _merge(Node* a, Node* b) {
          if(a == nullptr && b == nullptr)
            return nullptr;
          else if(a == nullptr)
            return b;
          else if(b == nullptr)
            return a;
          else {
            if(b->degree < a->degree) {
              b->sibling = _merge(a, b->sibling);
              return b;
            } else if(a->degree < b->degree) {
              a->sibling = _merge(a->sibling, b);
              return a;
            } else {
              Node *curr1 = a, *nxt1;
              Node *curr2 = b, *nxt2;
              nxt1 = a->sibling;
              nxt2 = b->sibling;
              curr1->sibling = nullptr;
              curr2->sibling = nullptr;
              return _merge(_merge(nxt1, _mergesmall(curr1, curr2)), nxt2);
            } 
          }
        }

        Key _extractTop(Node* node) {
          Key smax = node->key;
          do {
            if(smax < node->key)
              smax = node->key;
            node = node->sibling;
          } while(node != nullptr);
          return smax;
        }

        Node* _reverse(Node* node) {
          if(node == nullptr)
            return nullptr;
          else if(node->sibling == nullptr)
            return node;
          else {
            Node* start = _reverse(node->sibling);
            Node* sib = node->sibling;
            sib->sibling = node;
            node->sibling = nullptr;
            return start;
          }
        }

        Node* _separateTop(Node* node, Node* &sTop, Key smax) {
          if(node->key == smax) {
            Node* target = node->sibling;
            node->sibling = nullptr;
            sTop = node->son;
            node->son = nullptr;
            delete node;
            return target;
          } else {
            node->sibling = _separateTop(node->sibling, sTop, smax);
            return node;
          }
        }

        Node* _eraseTop(Node* node, Key smax) {
          Node* sTop = nullptr;
          node = _separateTop(node, sTop, smax);
          return _merge(node, _reverse(sTop));
        }

        Node* root = nullptr;

        void _print(Node* node) {
          if(node == nullptr)
            return ;
          std::cout << node->degree << " ";
          _print(node->sibling);
        }
      public:
        void print() {
          _print(root);
        }
        void mergeHeap(BinomialHeap<Key> &oth) {
          root = _merge(root, oth.root);
          oth.root = nullptr;
        }
        void push(Key key) {
          root = _merge(root, generateNode(key));
        }
        bool isEmpty() {
          return root == nullptr;
        }
        Key top() {
          assert(0 == isEmpty());
          return _extractTop(root);
        }
        void pop() {
          assert(0 == isEmpty()); 
          root = _eraseTop(root, _extractTop(root));
        }

        void clear() {
          delete root;
        }
        ~BinomialHeap() {
        }
    };
}

int const nmax = 200000;
int v[5 + nmax];

BinomialHeap<int> build(int from, int to) {
  if(from == to) {
    BinomialHeap<int> target;
    target.push(v[from]);
    return target;
  } else {
    BinomialHeap<int> f1, f2;
    int mid = (from + to) / 2;
    f1 = build(from, mid);
    f2 = build(mid + 1, to);
    f1.mergeHeap(f2);
    return f1;
  }
}

void sortInterval(int from, int to) {
  BinomialHeap<int> hp = build(from, to);
  int steps = 0;

  for(int i = to; from <= i; i--) {
    v[i] = hp.top();
    hp.pop();
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n ;
  std::cin>>n;
    for(int i = 1 ; i <= n;i++){
    std::cin>>v[i];
  }
  sortInterval(1 , n);
  int smin = 2000000000,smaxp = 0;
  for(int i = 2 ; i <= n ;i++){
    if(v[i] - v[i - 1] < smin){
      smin = v[i] - v[i - 1];
      smaxp = 1;
    } else if(smin == v[i] - v[i - 1]){
      smaxp++;
    }
  }
  std::cout<<smin<<" "<<smaxp << '\n';
  return 0;
}