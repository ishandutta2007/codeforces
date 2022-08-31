#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Seg {
  pair<int, int> mn = make_pair(1e7, 1e7); // <value, pos>
  void recalc(const Seg &lhs_seg, int lhs_len,
    const Seg &rhs_seg, int rhs_len) {
    mn = min(lhs_seg.mn, rhs_seg.mn);
  }
};

struct Lazy {
  int add;
  int assign_idx; // LLONG_MIN if no assign;
  void init() {
    add = 0;
    assign_idx = INT_MIN;
  }
  Lazy() { init(); }
  void split(Lazy &lhs_lazy, Lazy &rhs_lazy, int len) {
    lhs_lazy = *this;
    rhs_lazy = *this;
    init();
  }
  void merge(Lazy &oth, int len) {
    add += oth.add;
    assign_idx = max(assign_idx, oth.assign_idx);
  }
  void apply_to_seg(Seg &cur, int len) const {
    cur.mn.first += add;
    if (assign_idx != INT_MIN) {
      cur.mn.second = assign_idx;
    }
  }
};

struct Node { // Following code should not need to be
              // modified
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
    Seg seg1, seg2;
    Seg *pres = &seg1, *ptmp = &seg2;
    roots[ver]->get(
      0, len, l, r, pres, ptmp, roots.size() - 1);
    return *pres;
  }
};

const int MAX_N = 1e6 + 5;

vector<pair<int, int>> conds [MAX_N];
vector<int> ans;

void solve (int root, int l, int r, SegTree &segTree) {
  int vr = r;
  int vl = l;
  
  for (pair<int, int> pr : conds[root]) {
    if (pr.second == 0) {
      vl = max(vl, pr.first);
    } else {
      vr = min(vr, pr.first);
    }

    Lazy tmp;
    tmp.add = -1;
    segTree.upd(root, pr.first, tmp);
  }

  if (vl >= vr) {
    cout << "IMPOSSIBLE" << endl;
    exit(0);
  }

  pair<int, int> mid = segTree.get(vl, vr).mn;
  if (mid.first > 0) {
    cout << "IMPOSSIBLE" << endl;
    exit(0);
  }

  if (root < mid.second) {
    solve(root + 1, root + 1, mid.second + 1, segTree);
  }
  ans.push_back(root);
  if (mid.second + 1 < r) {
    solve(mid.second + 1, mid.second + 1, r, segTree);
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int vertexc, condc;
  cin >> vertexc >> condc;

  SegTree segTree (1 << 21);
  for (int i = 0; i <= vertexc; i++) {
    Lazy tmp;
    tmp.assign_idx = i;
    tmp.add = -1e7;

    segTree.upd(i, i + 1, tmp);
  }
  
  for (int i = 0; i < condc; i++) {
    int par, ch;
    string dir;
    cin >> par >> ch >> dir;

    if (ch <= par) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }

    Lazy tmp;
    tmp.add = 1;
    segTree.upd(par, ch, tmp);

    if (dir[0] == 'L') {
      conds[par].push_back(make_pair(ch, 0));
    } else {
      conds[par].push_back(make_pair(ch, 1));
    }
  }

  solve(1, 1, vertexc + 1, segTree);

  for (int u : ans) {
    cout << u << " ";
  }
  cout << endl;
}