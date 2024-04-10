#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 300300;

struct Node {
  int key;
  int pr;
  int bon;
  Node *l, *r;

  Node():
    key(0),
    pr(rand()),
    bon(0),
    l(nullptr),
    r(nullptr)
  { }

};

void push(Node *v) {
  if (v == nullptr)
    return;

  v->key += v->bon;

  if (v->l != nullptr) 
    v->l->bon += v->bon;

  if (v->r != nullptr)
    v->r->bon += v->bon;

  v->bon = 0;
}

void split(Node *v, int key, Node *&l, Node *&r) {
  push(v);

  if (v == nullptr) {
    l = nullptr;
    r = nullptr;
    return;
  }

  if (v->key < key) {
    split(v->r, key, l, r);
    v->r = l;
    l = v;
  } else {
    split(v->l, key, l, r);
    v->l = r;
    r = v;
  }
}

Node *merge(Node *l, Node *r) {
  push(l), push(r);

  if (l == nullptr)
    return r;

  if (r == nullptr)
    return l;

  if (l->pr < r->pr) {
    r->l = merge(l, r->l);
    return r;
  } else {
    l->r = merge(l->r, r);
    return l;
  }
}

Node* drop(Node *v) {
  if (v == nullptr)
    return v;

  if (v->l != nullptr)
    v->l = drop(v->l);
  else {
    v = v->r;
  }

  return v;
}

int sz(Node *v) {
  if (v == nullptr)
    return 0;

  return 1 + sz(v->l) + sz(v->r);
}


int n, l[M], r[M];
int cnt = 0;
Node pool[M];

Node* getSome() {
  return pool + cnt++;
}

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }
}

void kill() {
  Node *ROOT = getSome();
  ROOT->key = 0;
  for (int i = 0; i < n; ++i) {
    int l = ::l[i], r = ::r[i];
    Node *L;
    split(ROOT, l, L, ROOT);
    
    Node *MID, *R;
    split(ROOT, r, MID, R);

    if (MID != nullptr) 
      MID->bon++;
    
    Node *cur = getSome();
    cur->key = l;

    R = drop(R);

    ROOT = nullptr;
    ROOT = merge(ROOT, L);
    ROOT = merge(ROOT, cur);
    ROOT = merge(ROOT, MID);
    ROOT = merge(ROOT, R);
  }

  cout << sz(ROOT) - 1 << endl;
}


int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}