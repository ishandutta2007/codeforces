#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
  int prior, value, cnt;
  Node *l, *r;
  Node(int prior, int value) : prior(prior), value(value), cnt(1), l(0), r(0) {}
};

Node* root;

int get_cnt(Node* x) {
  return x ? x->cnt : 0;
}

void update_cnt(Node* x) {
  if (x)
    x->cnt = get_cnt(x->l) + get_cnt(x->r) + 1;
}

void merge(Node* &x, Node* left, Node* right) {
  if (!left || !right) 
    x = left ? left : right;
  else if (left->prior > right->prior) {
    merge(left->r, left->r, right);
    x = left;
  }
  else {
    merge(right->l, left, right->l);
    x = right;
  }
  update_cnt(x);
}

int erase(Node* &x, int pos, int add) {
  int res = 0;
  int key = add + get_cnt(x->l);
  if (pos == key) {
    res = x->value;
    Node* tmp = x;
    merge(x, x->l, x->r);
    delete tmp;
  }
  else if (pos < key)
    res = erase(x->l, pos, add);
  else
    res = erase(x->r, pos, key + 1);
  update_cnt(x);
  return res;
}

Node* create_node(int val) {
  return new Node(uniform_int_distribution <int> (1, 2e9)(rng), val);
}

void insert(int val) {
  merge(root, create_node(val), root);
}

int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  for (int i = N; i; i--) 
    insert(i);
  bool ok = true;
  vector <int> perm(N + 1), inv(N + 1);
  auto assign = [&](int x, int y) {
    perm[x] = y;
    inv[y] = x;
  };
  while (M--) {
    int x, y;
    scanf("%d%d", &x, &y);
    int curr = erase(root, y - 1, 0);
    ok &= !perm[curr] || perm[curr] == x;
    ok &= !inv[x] || inv[x] == curr;
    assign(curr, x);
    insert(curr);
  }
  if (!ok) {
    puts("-1");
    return 0;
  }
  int ptr = 1;
  for (int i = 1; i <= N; i++) {
    if (!perm[i]) {
      while (inv[ptr])
        ptr++;
      assign(i, ptr);
    }
    printf("%d ", perm[i]);
  }
  puts("");
  return 0;
}