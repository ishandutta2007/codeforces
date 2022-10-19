#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
  int key, prior, cnt;
  Node *l, *r;
  Node(int key, int prior) : key(key), prior(prior), cnt(1), l(0), r(0) {}
};

Node* root;

int get_cnt(Node* x) {
  return x ? x->cnt : 0;
}

void update_cnt(Node* x) {
  if (x)
    x->cnt = get_cnt(x->l) + get_cnt(x->r) + 1;
}

void split(Node* x, Node* &left, Node* &right, int val) {
  if (!x)
    left = right = 0;
  else if (x->key <= val) {
    split(x->r, x->r, right, val);
    left = x;
  }
  else {
    split(x->l, left, x->l, val);
    right = x;
  }
  update_cnt(x);
}

void insert(Node* &x, Node* elem) {
  if (!x)
    x = elem;
  else if (x->prior < elem->prior) {
    split(x, elem->l, elem->r, elem->key);
    x = elem;
  }
  else
    insert(elem->key <= x->key ? x->l : x->r, elem);
  update_cnt(x);
}

int count_smaller(Node* x, int val) {
  if (!x)
    return 0;
  if (x->key < val)
    return get_cnt(x->l) + count_smaller(x->r, val) + 1;
  return count_smaller(x->l, val);
}

Node* create_node(int val) {
  return new Node(val, uniform_int_distribution <int> (1, 2e9)(rng));
}

int main() {
  int N, T;
  scanf("%d%d", &N, &T);
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    int t;
    scanf("%d", &t);
    insert(root, create_node(t - i));
    if (i < T)
      ans = max(ans, count_smaller(root, T - i));
  }
  printf("%d\n", ans);
  return 0;
}