#include <iostream>
#include <map>
#include <set>
#include <vector>

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

  Modint operator- () {
    return Modint(MOD - val);
  }

  Modint operator- (Modint other) {
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

  bool operator== (Modint other) {
    return val == other.val;
  }

  bool operator!= (Modint other) {
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

struct Seg {
  Modint sum = 0;
  void recalc(const Seg &lhs_seg, int lhs_len,
    const Seg &rhs_seg, int rhs_len) {
    sum = lhs_seg.sum + rhs_seg.sum;
  }
};

struct Lazy {
  Modint a, b; // update of the form x |-> ax + b
  void init() {
    a = 1;
    b = 0;
  }
  Lazy() { init(); }
  void split(Lazy &lhs_lazy, Lazy &rhs_lazy, int len) {
    lhs_lazy = *this;
    rhs_lazy = *this;
    init();
  }
  void merge(Lazy &oth, int len) {
    a *= oth.a;
    b *= oth.a;
    b += oth.b;
    // b += oth.b * a;
  }
  void apply_to_seg(Seg &cur, int len) const {
    cur.sum = a * cur.sum + b * len;
  }
};

struct Node { // Following code should not need to be
              // modified. An exception is the assign thing.
  int ver;
  bool is_lazy = false;
  Seg seg;
  Lazy lazy;
  Node *lc = NULL, *rc = NULL;
  void init() {
    if (!lc) {
      lc = new Node{ver};
      rc = new Node{ver};
    }
  }
  Node *upd(
    int L, int R, int l, int r, Lazy &val, int tar_ver) {
    if (ver != tar_ver) {
      Node *rep = new Node(*this);
      rep->ver = tar_ver;
      return rep->upd(L, R, l, r, val, tar_ver);
    }
    if (L >= l && R <= r) {
      val.apply_to_seg(seg, R - L);
      lazy.merge(val, R - L);
      is_lazy = true;
    } else {
      init();
      int M = (L + R) / 2;
      if (is_lazy) {
        Lazy l_val, r_val;
        lazy.split(l_val, r_val, R - L);
        lc = lc->upd(L, M, L, M, l_val, ver);
        rc = rc->upd(M, R, M, R, r_val, ver);
        is_lazy = false;
      }
      Lazy l_val, r_val;
      val.split(l_val, r_val, R - L);
      if (l < M) lc = lc->upd(L, M, l, r, l_val, ver);
      if (M < r) rc = rc->upd(M, R, l, r, r_val, ver);
      seg.recalc(lc->seg, M - L, rc->seg, R - M);
    }
    return this;
  }
  void get(int L, int R, int l, int r, Seg *&lft_res,
    Seg *&tmp, bool last_ver) {
    if (L >= l && R <= r) {
      tmp->recalc(*lft_res, L - l, seg, R - L);
      swap(lft_res, tmp);
    } else {
      init();
      int M = (L + R) / 2;
      if (is_lazy) {
        Lazy l_val, r_val;
        lazy.split(l_val, r_val, R - L);
        lc = lc->upd(L, M, L, M, l_val, ver + last_ver);
        lc->ver = ver;
        rc = rc->upd(M, R, M, R, r_val, ver + last_ver);
        rc->ver = ver;
        is_lazy = false;
      }
      if (l < M)
        lc->get(L, M, l, r, lft_res, tmp, last_ver);
      if (M < r)
        rc->get(M, R, l, r, lft_res, tmp, last_ver);
    }
  }
};

struct SegTree { // indexes start from 0, ranges are
                 // [beg, end)
  vector<Node *> roots; // versions start from 0
  int len;
  SegTree(int _len) : len(_len) {
    roots.push_back(new Node{0});
  }
  int upd(
    int l, int r, Lazy &val, bool new_ver = false) {
    Node *cur_root = roots.back()->upd(
      0, len, l, r, val, roots.size() - !new_ver);
    if (cur_root != roots.back())
      roots.push_back(cur_root);
    return roots.size() - 1;
  }
  Seg get(int l, int r, int ver = -1) {
    if (ver == -1) ver = roots.size() - 1;
    Seg seg1, seg2; // if the default value of Seg isn't an identity,
    // replace those with an identity.
    Seg *pres = &seg1, *ptmp = &seg2;
    roots[ver]->get(
      0, len, l, r, pres, ptmp, roots.size() - 1);
    return *pres;
  }
};

struct Query {
  int l, r, x; // x = 0 is a sum query
};

struct DSU {
  vector<int> root;

  DSU (int _vertexc = 0) {
    root = vector<int> (_vertexc);
    for (int i = 0; i < _vertexc; i++) {
      root[i] = i;
    }
  }

  int find (int u) {
    if (root[u] != u) {
      root[u] = find(root[u]);
    }
    return root[u];
  }
};

const int MAX_N = 2e5 + 5;

map<int, int> compr [MAX_N];
DSU dsus [MAX_N];
vector<int> big [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, qc;
  cin >> n >> qc;

  vector<Query> qs;
  for (int i = 0; i < qc; i++) {
    int t;
    cin >> t;

    if (t == 2) {
      int l, r;
      cin >> l >> r;

      qs.push_back({l, r, 0});
    } else {
      int l, r, x;
      cin >> l >> r >> x;

      compr[x][l] = 0;
      compr[x][r + 1] = 0;
      qs.push_back({l, r, x});
    }
  }

  for (int i = 1; i <= n; i++) {
    int cur = 0;
    for (auto it = compr[i].begin(); it != compr[i].end(); it++) {
      it->second = cur;
      cur++;
    }
    dsus[i] = DSU(cur);
    big[i] = vector<int>(cur);
    for (auto it = compr[i].begin(); it != compr[i].end(); it++) {
      big[i][it->second] = it->first;
    }
  }

  SegTree segtree (1 << 18);
  for (Query q : qs) {
    if (q.x == 0) {
      cout << segtree.get(q.l, q.r + 1).sum << '\n';
    } else {
      int cl = compr[q.x][q.l];
      int cr = compr[q.x][q.r + 1];
      for (int i = cl; i < cr;) {
        if (dsus[q.x].find(i) == i) {
          int kl = big[q.x][i];
          int kr = big[q.x][i + 1];

          Lazy tmp;
          tmp.a = 1;
          tmp.b = 1;
          segtree.upd(kl, kr, tmp);
          dsus[q.x].root[i] = i + 1;
          i++;
        } else {
          int kl = big[q.x][i];
          int kr = min(q.r + 1, big[q.x][dsus[q.x].find(i)]);

          Lazy tmp;
          tmp.a = 2;
          tmp.b = 0;
          segtree.upd(kl, kr, tmp);
          i = dsus[q.x].find(i);
        }
      }
    }
  }
}