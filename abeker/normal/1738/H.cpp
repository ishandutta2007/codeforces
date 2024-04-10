#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;

struct Node {
  Node* ltr_child[26];
  Node *suff_parent, *ltr_parent;
  int len, rightmost, suff_children;
  Node() {
    rightmost = -MAX;
    suff_children = 0;
    suff_parent = ltr_parent = nullptr;
    fill(ltr_child, ltr_child + 26, nullptr);
  }
  void updateRightmost(int pos) {
    if (len > 0 && pos > rightmost)
      rightmost = pos;
  }
  int getDiff() const {
    return rightmost - len;
  }
  bool isLeaf() const {
    return len > 0 && !suff_children;
  }
};

class Cmp {
public:
  bool operator()(const Node* lhs, const Node* rhs) const {
    int diff_lhs = lhs -> getDiff();
    int diff_rhs = rhs -> getDiff();
    if (diff_lhs != diff_rhs)
      return diff_lhs < diff_rhs;
    return lhs -> len < rhs -> len;
  }
};

int cnt;
int lo, hi;
Node* suff;
Node *zero, *minus_one;
set <Node*, Cmp> leaves;
char s[MAX];

void move(Node* &x) {
  while (x -> len >= hi - lo || s[hi - x -> len - 1] != s[hi])
    x = x -> suff_parent;
}

void in(Node* x) {
  if (x -> isLeaf())
    leaves.insert(x);
}

void out(Node* x) {
  if (x -> isLeaf())
    leaves.erase(x);
}

void add_parent(Node* &x, Node* y) {
  out(y);
  x -> suff_parent = y;
  (y -> suff_children)++;
}

void add() {
  int ltr = s[hi] - 'a';
  Node* curr = suff;
  move(curr);
  Node* &ref = curr -> ltr_child[ltr];
  if (!ref) {
    ref = new Node();
    ref -> ltr_parent = curr;
    ref -> len = curr -> len + 2;
    if (ref -> len == 1)
      add_parent(ref, zero);
    else {
      Node* tmp = curr -> suff_parent;
      move(tmp);
      add_parent(ref, tmp -> ltr_child[ltr]);
    }
    cnt++;
  }
  else 
    out(ref);
  ref -> updateRightmost(hi);
  in(ref);
  suff = ref;
}

void remove() {
  if (leaves.empty())
    return;
  Node* curr = *leaves.begin();
  if (curr -> getDiff() >= lo)
    return;
  out(curr);
  Node* parent = curr -> suff_parent;
  curr -> ltr_parent -> ltr_child[s[lo] - 'a'] = nullptr;
  parent -> updateRightmost(curr -> rightmost);
  (parent -> suff_children)--;
  in(parent);
  if (suff == curr)
    suff = parent;
  delete curr;
  cnt--;
}

void init() {
  minus_one = new Node();
  add_parent(minus_one, minus_one);
  minus_one -> len = -1;
  zero = new Node();
  add_parent(zero, minus_one);
  zero -> len = 0;
  suff = zero;
}

int main() {
  init();
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    char cmd[5];
    scanf("%s", cmd);
    if (!strcmp(cmd, "push")) {
      scanf(" %c", s + hi);
      add();
      hi++;
    }
    else {
      remove();
      lo++;
    }
    printf("%d\n", cnt);
  }
  return 0;
}