#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct Seg {
  int mx = 0;
  void recalc(const Seg &lhs_seg, int lhs_len,
    const Seg &rhs_seg, int rhs_len) {
    mx = max(lhs_seg.mx, rhs_seg.mx);
  }
} __attribute__((packed));

struct Lazy {
  int add;
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
    cur.mx += add;
  }
} __attribute__((packed));

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
    Seg seg1, seg2;
    Seg *pres = &seg1, *ptmp = &seg2;
    roots[ver]->get(
      0, len, l, r, pres, ptmp, roots.size() - 1);
    return *pres;
  }
};

const int MAX_N = 1 << 18;

int pos [MAX_N];
int arr [2 * MAX_N];
int left_par [MAX_N];
int right_par [MAX_N];
int curl, curr;

void shift (SegTree &segTree) {
  int val = arr[curl];
  arr[curr + 1] = val;
  pos[val] = curr + 1;
  curl++;
  curr++;

  if (val != 1) {
    int rg = pos[right_par[val]];
    if (curl < rg) {
      Lazy tmp;
      tmp.add = -1;
      segTree.upd(curl, rg, tmp);
    }

    int lg = pos[left_par[val]];
    if (lg < curr - 1) {
      Lazy tmp;
      tmp.add = 1;
      segTree.upd(lg + 1, curr, tmp);
    }

    Lazy tmp;
    tmp.add = segTree.get(lg, lg + 1).mx + 1;
    segTree.upd(curr, curr + 1, tmp);
  } else {
    Lazy tmp;
    tmp.add = 1;
    segTree.upd(curr, curr + 1, tmp);
  }
}

int main () {
  ios::sync_with_stdio(false);

  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];
    pos[arr[i]] = i;
  }
  curl = 0;
  curr = length - 1;

  vector<pair<int, int>> elems;
  for (int i = 0; i < length; i++) {
    elems.push_back({arr[i], i});
  }
  sort(elems.begin(), elems.end());

  set<pair<int, int>> in_already;
  for (auto pr : elems) {
    int val = pr.first;
    int loc = pr.second;

    if (!in_already.empty()) {
      auto lb = in_already.lower_bound({loc, val});
      if (lb == in_already.end()) {
        right_par[val] = in_already.begin()->second;
      } else {
        right_par[val] = lb->second;
      }

      if (lb == in_already.begin()) {
        left_par[val] = in_already.rbegin()->second;
      } else {
        left_par[val] = prev(lb)->second;
      }
    }
    in_already.insert({loc, val});
  }

  // build the initial tree
  SegTree segTree (2 * MAX_N);
  Lazy tmp;
  tmp.add = 1;
  segTree.upd(pos[1], pos[1] + 1, tmp);
  for (auto pr : elems) {
    int val = pr.first;
    int loc = pr.second;

    if (val != 1) {
      Lazy tmp;
      if (pos[left_par[val]] < loc && loc < pos[right_par[val]]) {
        if (left_par[val] > right_par[val]) {
          tmp.add = segTree.get(pos[left_par[val]], pos[left_par[val]] + 1).mx + 1;
        } else {
          tmp.add = segTree.get(pos[right_par[val]], pos[right_par[val]] + 1).mx + 1;
        }
      } else if (pos[left_par[val]] < loc) {
        tmp.add = segTree.get(pos[left_par[val]], pos[left_par[val]] + 1).mx + 1;
      } else if (loc < pos[right_par[val]]) {
        tmp.add = segTree.get(pos[right_par[val]], pos[right_par[val]] + 1).mx + 1;
      }

      segTree.upd(loc, loc + 1, tmp);
    }
  }
  
  // start shifting
  pair<int, int> ans = {segTree.get(curl, curr + 1).mx, 0};
  for (int i = 1; i < length; i++) {
    shift(segTree);
    
    ans = min(ans, {segTree.get(curl, curr + 1).mx, i});
  }

  cout << ans.first << " " << ans.second << endl;
}