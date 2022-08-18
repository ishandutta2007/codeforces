#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Seg {
  ll sum = 0;
  void recalc(const Seg &lhs_seg, int lhs_len,
    const Seg &rhs_seg, int rhs_len) {
    sum = lhs_seg.sum + rhs_seg.sum;
  }
} __attribute__((packed));

struct Lazy {
  ll add;
  ll assign_val; // LLONG_MIN if no assign;
  void init() {
    add = 0;
    assign_val = LLONG_MIN;
  }
  Lazy() { init(); }
  void split(Lazy &lhs_lazy, Lazy &rhs_lazy, int len) {
    lhs_lazy = *this;
    rhs_lazy = *this;
    init();
  }
  void merge(Lazy &oth, int len) {
    if (oth.assign_val != LLONG_MIN) {
      add = 0;
      assign_val = oth.assign_val;
    }
    add += oth.add;
  }
  void apply_to_seg(Seg &cur, int len) const {
    if (assign_val != LLONG_MIN) {
      cur.sum = len * assign_val;
    }
    cur.sum += len * add;
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
  SegTree(int _len) {
    len = 1;
    while (len < _len) {
      len *= 2;
    }
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

  void set (int l, int r, int val) {
    Lazy tmp;
    tmp.assign_val = val;
    upd(l, r + 1, tmp);
  }

  ll get (int x) {
    return get(x, x + 1).sum;
  }

  ll cnt (int l, int r) {
    return get(l, r + 1).sum;
  }
};

#define L first
#define R second

bool solve () {
  int n, qc;
  cin >> n >> qc;

  string s, t;
  cin >> s >> t;

  vector<pair<int, int>> qs;
  for (int i = 0; i < qc; i++) {
    int l, r;
    cin >> l >> r;
    l--; r--;

    qs.push_back(make_pair(l, r));
  }

  SegTree seg (n);
  for (int i = 0; i < n; i++) {
    seg.set(i, i, t[i] - '0');
  }

  reverse(qs.begin(), qs.end());
  for (auto q : qs) {
    int cnt = seg.cnt(q.L, q.R);
    int len = q.R - q.L + 1;
    if (2 * cnt == len) {
      return false;
    }

    if (2 * cnt < len) {
      seg.set(q.L, q.R, 0);
    } else {
      seg.set(q.L, q.R, 1);
    }
  }

  for (int i = 0; i < n; i++) {
    if (seg.get(i) != s[i] - '0') {
      return false;
    }
  }

  return true;
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    bool ans = solve();
    cout << (ans ? "YES" : "NO") << '\n';
  }
}