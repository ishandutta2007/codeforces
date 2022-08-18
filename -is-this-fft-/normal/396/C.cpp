#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7; // change if needed

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

struct Seg {
  Modint sum = 0;
  void recalc(const Seg &lhs_seg, int lhs_len,
    const Seg &rhs_seg, int rhs_len) {
    sum = lhs_seg.sum + rhs_seg.sum;
  }
};

struct Lazy {
  Modint add;
  void init() {
    add = 0;
  }
  Lazy() { init(); }
  void split(Lazy &lhs_lazy, Lazy &rhs_lazy, int len) {
    lhs_lazy = *this;
    rhs_lazy = *this;
    init();
  }
  void merge(Lazy &oth, int len) {
    add += oth.add;
  }
  void apply_to_seg(Seg &cur, int len) const {
    cur.sum += Modint(len) * add;
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

class SegTree { // indexes start from 0, ranges are
                 // [beg, end)
  vector<Node *> roots; // versions start from 0
  int len;
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

public:
  SegTree(int _len = 0) : len(_len) {
    roots.push_back(new Node{0});
  }
  
  void add (int l, int r, int add) {
    Lazy tmp;
    tmp.add = Modint(add);
    upd(l, r + 1, tmp);
  }

  Modint mget (int l, int r) {
    return get(l, r + 1).sum; 
  }
};

const int MAX_N = 1 << 19;

int par [MAX_N];
vector<int> adj [MAX_N];
int sz [MAX_N];
int bigc [MAX_N];
void calc_sz (int u) {
  sz[u] = 1;
  pair<int, int> big = make_pair(-1, -1);
  for (int nxt : adj[u]) {
    calc_sz(nxt);
    sz[u] += sz[nxt];
    big = max(big, make_pair(sz[nxt], nxt));
  }
  bigc[u] = big.second;
}

int cur_idx;
int lfend [MAX_N];
int rgend [MAX_N];
int src [MAX_N];

void build (int u, int s) {
  cur_idx++;
  lfend[u] = cur_idx;
  src[u] = s;

  if (bigc[u] != -1) {
    build(bigc[u], s);
  }
  for (int nxt : adj[u]) {
    if (nxt != bigc[u]) {
      build(nxt, nxt);
    }
  }
  
  rgend[u] = cur_idx;
}

SegTree segtree;

void upd (int u, int x, int k) {
  segtree.add(lfend[u], lfend[u], x);
  if (lfend[u] < rgend[u]) {
    segtree.add(lfend[u] + 1, rgend[u], MOD - k);
  }
}

Modint get (int u) {
  Modint ans (0);
  if (src[u] != 1) {
    ans = get(par[src[u]]);
  }
  ans += segtree.mget(lfend[src[u]], lfend[u]);
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;

  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;

    adj[p].push_back(i);
    par[i] = p;
  }

  calc_sz(1);
  build(1, 1);
  segtree = SegTree (MAX_N);

  int qc;
  cin >> qc;
  for (int i = 0; i < qc; i++) {
    int type;
    cin >> type;

    if (type == 1) {
      int v, x, k;
      cin >> v >> x >> k;

      upd(v, x, k);
    } else {
      int v;
      cin >> v;

      cout << get(v) << '\n';
    }
  }
}