#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <tuple>

using namespace std;

typedef long long ll;

const int MOD = 998244353;

struct Modint {
  ll val;
  
  Modint (ll _val = 0)
    : val(_val % MOD) {}

  Modint operator+ (Modint other) const {
    return Modint(val + other.val);
  }

  void operator+= (Modint other) {
    val += other.val;
    val %= MOD;
  }

  Modint operator- () const {
    return Modint(MOD - val);
  }

  Modint operator- (Modint other) const {
    return Modint(val + MOD - other.val);
  }

  void operator-= (Modint other) {
    val += MOD - other.val;
    val %= MOD;
  }

  Modint operator* (Modint other) const {
    return Modint(val * other.val);
  }

  void operator*= (Modint other) {
    val *= other.val;
    val %= MOD;
  }

  bool operator== (Modint other) const {
    return val == other.val;
  }

  bool operator!= (Modint other) const {
    return val != other.val;
  }
};

Modint exp (Modint a, int k) {
  if (k == 0) {
    return Modint(1);
  } else if (k % 2 == 0) {
    Modint half = exp(a, k / 2);
    return half * half;
  } else {
    return a * exp(a, k - 1);
  }
}

Modint inv (Modint a) {
  return exp(a, MOD - 2);
}

ostream& operator<< (ostream& out, Modint p) {
  out << p.val;
  return out;
}

mt19937 randgen;

struct Treap {
  struct Node {
    int value, lazy;
    unsigned int priority;

    Node* lch;
    Node* rch;

    Node(int new_value) {
      value = new_value;
      priority = randgen();
      lch = 0;
      rch = 0;
    }

    void propagate () {
      value += lazy;
      if (lch) {
        lch->lazy += lazy;
      }
      if (rch) {
        rch->lazy += lazy;
      }
      lazy = 0;
    }
  };

  Node* root = 0;

  pair<Node*, Node*> split(int key, Node* cur) {
    if (cur == 0) return {0, 0};
    cur->propagate();

    pair<Node*, Node*> result;
    if (key <= cur->value) {
      auto ret = split(key, cur->lch);
      cur->lch = ret.second;
      result = {ret.first, cur};
    } else {
      auto ret = split(key, cur->rch);
      cur->rch = ret.first;
      result = {cur, ret.second};
    }
    return result;
  }

  Node* merge(Node* left, Node* right) {
    if (left == 0) return right;
    if (right == 0) return left;

    Node* top;
    if (left->priority < right->priority) {
      left->propagate();
      left->rch = merge(left->rch, right);
      top = left;
    } else {
      right->propagate();
      right->lch = merge(left, right->lch);
      top = right;
    }
    return top;
  }

  void incr_abv (int key) {
    auto ret = split(key, root);
    if (ret.second) {
      ret.second->lazy++;
    }
    auto cur = merge(ret.first, ret.second);
    root = cur;
  }

  void insert (int key) {
    auto cur = new Node(key);
    auto ret = split(key, root);
    cur = merge(ret.first, cur);
    cur = merge(cur, ret.second);
    root = cur;
  }

  void erase(int key) {
    Node *left, *mid, *right;

    tie(left, mid) = split(key, root);
    tie(mid, right) = split(key + 1, mid);
    root = merge(left, right);
  }

  int size (Node *cur) {
    if (cur == 0) {
      return 0;
    }

    return 1 + size(cur->lch) + size(cur->rch);
  }

  int size () {
    return size(root);
  }

  void print (Node *cur) {
    if (cur == 0) {
      return;
    }

    cur->propagate();

    print(cur->lch);
    cerr << cur->value << " ";
    print(cur->rch);
  }

  void print () {
    cerr << " treap : ";
    print(root);
    cerr << endl;
  }
};

const int MAX_N = 4e5 + 5;

Modint fact [MAX_N];
Modint ifact [MAX_N];

Modint choose (int n, int k) {
  return fact[n] * ifact[k] * ifact[n - k];
}

void solve () {
  int n, m;
  cin >> n >> m;

  Treap breaks;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;

    breaks.erase(y - 1);
    breaks.incr_abv(y);
    breaks.insert(y);
  }

  cout << choose(2 * n - breaks.size() - 1, n) << '\n';
}

int main () {
  fact[0] = 1;
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = fact[i - 1] * i;
  }

  for (int i = 0; i < MAX_N; i++) {
    ifact[i] = inv(fact[i]);
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);
  randgen = mt19937(chrono::steady_clock::now().time_since_epoch().count());
  
  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}