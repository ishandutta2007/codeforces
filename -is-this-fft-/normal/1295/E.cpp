#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll INF = 1LL << 62;

struct Seg {
  ll mn = 0;
  void recalc(const Seg &lhs_seg, int lhs_len,
    const Seg &rhs_seg, int rhs_len) {
    mn = min(lhs_seg.mn, rhs_seg.mn);
  }
} __attribute__((packed));

struct Lazy {
  ll add;
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
    cur.mn += add;
  }
} __attribute__((packed));

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
} __attribute__((packed));

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
    seg1.mn = INF;
    seg2.mn = INF;
    Seg *pres = &seg1, *ptmp = &seg2;
    roots[ver]->get(
      0, len, l, r, pres, ptmp, roots.size() - 1);
    return *pres;
  }
};

const int MAX_N = 1 << 18;

int perm [MAX_N];
ll cost [MAX_N];
int pos [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> perm[i];
    pos[perm[i]] = i;
  }

  for (int i = 1; i <= n; i++) {
    cin >> cost[i];
  }

  SegTree segTree (MAX_N);
  for (int i = 1; i <= n; i++) { // initially all in "1"-set
    Lazy tmp;
    tmp.add = cost[pos[i]];
    segTree.upd(pos[i], n, tmp);
  }

  ll ans = segTree.get(1, n).mn;
  //cerr << "  " << segTree.get(1, n).mn << endl;
  for (int i = 1; i <= n; i++) { // move into the "0"-set
    Lazy tmp;
    tmp.add = -cost[pos[i]];
    segTree.upd(pos[i], n, tmp);

    Lazy tmp2;
    tmp2.add = cost[pos[i]];
    segTree.upd(1, pos[i], tmp2);

    //cerr << "  " << segTree.get(1, n).mn << endl;
    ans = min(ans, segTree.get(1, n).mn);
  }

  cout << ans << endl;
}