#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct Node {
  Node *parent, *lch, *rch;
  int lfend, rgend;
  vector<Node*> upds;
  ll sum;

  Node (int _lfend, int _rgend, Node *_parent = nullptr) :
    parent(_parent), lch(nullptr), rch(nullptr), lfend(_lfend), rgend(_rgend),
    upds(vector<Node*> (0)), sum(0) {}
  
  void addl () {
    lch = new Node (lfend, (lfend + rgend) / 2, this);
  }

  void addr () {
    rch = new Node ((lfend + rgend) / 2 + 1, rgend, this);
  }
  
  void propagate () {
    if (!upds.empty()) {
      for (int i = 0; i < (int) upds.size(); i++) {
        Node *p = upds[i];
        for (Node *q : p->upds) {
          upds.push_back(q);
        }
        if (p->lch != nullptr) {
          if (lch == nullptr) {
            lch = p->lch;
            p->lch->parent = this;
          } else {
            lch->upds.push_back(p->lch);
            lch->sum += p->lch->sum;
          }
        }
        if (p->rch != nullptr) {
          if (rch == nullptr) {
            rch = p->rch;
            p->rch->parent = this;
          } else {
            rch->upds.push_back(p->rch);
            rch->sum += p->rch->sum;
          }
        }
        // delete p;
      }
      upds.clear();
    }
  }

  void update () {
    propagate();
    if (rgend != lfend) {
      sum = 0;
      if (lch != nullptr) sum += lch->sum;
      if (rch != nullptr) sum += rch->sum;
    }
    if (parent != nullptr) parent->update();
  }

  ll query (int ql, int qr) {
    propagate();
    
    ql = max(ql, lfend);
    qr = min(qr, rgend);

    if (ql > qr) return 0;
    if (ql == lfend && qr == rgend) return sum;
    ll ans = 0;
    if (lch != nullptr) ans += lch->query(ql, qr);
    if (rch != nullptr) ans += rch->query(ql, qr);
    return ans;
  }

  Node *getnode (int ql, int qr) {
    // cerr << this << " " << lfend << " " << rgend << endl;
    propagate();
    
    if (ql == lfend && qr == rgend) return this;
    if (qr <= (lfend + rgend) / 2) {
      if (lch == nullptr) addl();
      return lch->getnode(ql, qr);
    } else {
      if (rch == nullptr) addr();
      return rch->getnode(ql, qr);
    }
  }

  void disown () {
    if (parent == nullptr) return;
    if (this == parent->lch) {
      // parent->sum -= sum;
      parent->lch = nullptr;
      parent->update();
    } else {
      // parent->sum -= sum;
      parent->rch = nullptr;
      parent->update();
    }
  }

  void range (int ql, int qr, vector<Node*> &ans) {
    propagate();

    ql = max(ql, lfend);
    qr = min(qr, rgend);
    if (ql > qr) return;
    if (ql == lfend && qr == rgend) {
      ans.push_back(this);
      return;
    }
    if (lch != nullptr) lch->range(ql, qr, ans);
    if (rch != nullptr) rch->range(ql, qr, ans);
  }
};

struct Segtree {
  Node *root;

  Segtree (int len = 1) {
    root = new Node (0, len - 1, nullptr);
  }

  vector<Node*> remove (int ql, int qr) {
    vector<Node*> nodes;
    root->range(ql, qr, nodes);
    for (Node *p : nodes) {
      p->disown();
    }
    return nodes;
  }

  void adjoin (const vector<Node*> &nodes) {
    for (Node *p : nodes) {
      Node *u = root->getnode(p->lfend, p->rgend);
      u->upds.push_back(p);
      u->sum += p->sum;
      u->update();
    }
  }

  void set (int idx, ll val) {
    Node *u = root->getnode(idx, idx);
    u->sum = val;
    u->update();
  }

  ll get (int l, int r) {
    return root->query(l, r);
  }
};

Segtree trees [10];

void type1 (int l, int r, int x, int y) {
  vector<Node*> nodes = trees[x].remove(l, r);
  trees[y].adjoin(nodes);
}

ll type2 (int l, int r) {
  ll ans = 0;
  for (int i = 1; i <= 9; i++) {
    ans += trees[i].get(l, r) * i;
  }
  return ans;
}

const int MAX_N = 1 << 17;

ll arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, qc;
  cin >> n >> qc;

  for (int i = 0; i <= 9; i++) {
    trees[i] = Segtree(MAX_N);
  }

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];

    int x = arr[i];
    vector<int> adds (10, 0);
    int pw = 1;
    while (x != 0) {
      adds[x % 10] += pw;      
      pw *= 10;
      x /= 10;
    }

    for (int j = 0; j <= 9; j++) {
      trees[j].set(i, adds[j]);
    }
  }

  for (int i = 0; i < qc; i++) {
    int t;
    cin >> t;

    if (t == 1) {
      int l, r, x, y;
      cin >> l >> r >> x >> y;

      type1(l, r, x, y);
    } else {
      int l, r;
      cin >> l >> r;

      cout << type2(l, r) << '\n';
    }
  }
}