#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Seg {
  short pt = -1, st = 1;
  int pl = 1, sl = 1, mw = 1; // 1 - in incr part, -1 - in decr part
  ll l = 0, r = 0;
  void recalc(const Seg &lhs_seg, int lhs_len,
    const Seg &rhs_seg, int rhs_len) {
    if (lhs_seg.pt == -2) {
      pl = rhs_seg.pl;
      pt = rhs_seg.pt;
      sl = rhs_seg.sl;
      st = rhs_seg.st;
      mw = rhs_seg.mw;
      l = rhs_seg.l;
      r = rhs_seg.r;
    } else if (rhs_seg.pt == -2) {
      pl = lhs_seg.pl;
      pt = lhs_seg.pt;
      sl = lhs_seg.sl;
      st = lhs_seg.st;
      mw = lhs_seg.mw;
      l = lhs_seg.l;
      r = lhs_seg.r;
    } else {
      l = lhs_seg.l;
      r = rhs_seg.r;
      pt = lhs_seg.pt;
      st = rhs_seg.st;
    
      int nmw = 0;
      int mmt = -1;
      if (lhs_seg.st == 1) {
        if (rhs_seg.pt == -1) {
          if (lhs_seg.r != rhs_seg.l) {
            nmw = lhs_seg.sl + rhs_seg.pl;
            mmt = 0; // full merge
          }
        } else {
          if (lhs_seg.r < rhs_seg.l) {
            nmw = lhs_seg.sl + rhs_seg.pl;
            mmt = 0;
          } else if (lhs_seg.r > rhs_seg.l) {
            nmw = lhs_seg.sl + 1;
            mmt = 1; // left expanded
          }
        }
      } else {
        if (rhs_seg.pt == -1) {
          if (lhs_seg.r > rhs_seg.l) {
            nmw = lhs_seg.sl + rhs_seg.pl;
            mmt = 0;
          } else if (lhs_seg.r < rhs_seg.l) {
            nmw = rhs_seg.pl + 1;
            mmt = 2; // right expanded
          }
        } else {
          if (lhs_seg.r < rhs_seg.l) {
            nmw = rhs_seg.pl + 1;
            mmt = 2; // right expanded
          } else if (lhs_seg.r > rhs_seg.l) {
            nmw = lhs_seg.sl + 1;
            mmt = 1;
          }
        }
      }

      mw = max({lhs_seg.mw, rhs_seg.mw, nmw});

      pl = lhs_seg.pl;
      if (pl == lhs_len) {
        if (pl == 1 && (mmt == 0 || mmt == 2) && lhs_seg.r < rhs_seg.l) {
          pt = 1;
        }
        
        if (mmt == 0) {
          pl += rhs_seg.pl;
        } else if (mmt == 1) {
          pl++;
        }
      }
    
      sl = rhs_seg.sl;
      if (sl == rhs_len) {
        if (sl == 1 && (mmt == 0 || mmt == 2) && lhs_seg.r > rhs_seg.l) {
          st = -1;
        }
        
        if (mmt == 0) {
          sl += lhs_seg.sl;
        } else if (mmt == 2) {
          sl++;
        }
      }
    }
  }
};

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
    cur.l += add;
    cur.r += add;
  }
};

//!finish
//!start

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
    Seg seg1;
    seg1.pt = -2;
    Seg seg2 = seg1;
    Seg *pres = &seg1, *ptmp = &seg2;
    roots[ver]->get(
      0, len, l, r, pres, ptmp, roots.size() - 1);
    return *pres;
  }
};

const int MAX_N = 1 << 19;
int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int length;
  cin >> length;

  SegTree stree (MAX_N);
  for (int i = 1; i <= length; i++) {
    cin >> arr[i];

    Lazy tmp;
    tmp.add = arr[i];
    stree.upd(i, i + 1, tmp);
  }

  /*
  Seg u = stree.get(1, 4);
  Seg v = stree.get(4, 8);
  cout << u.pl << " " << u.sl << " " << u.pt << " "
       << u.st << " " << u.l << " " << u.r << " " << u.mw << endl;
  cout << v.pl << " " << v.sl << " " << v.pt << " "
       << v.st << " " << v.l << " " << v.r << " " << v.mw << endl;
  Seg w;
  w.recalc(u, 3, v, 4);
  cout << w.pl << " " << w.sl << " " << w.pt << " "
       << w.st << " " << w.l << " " << w.r << " " << w.mw << endl;
  cout << endl << endl;
  */
  
  int queryc;
  cin >> queryc;
  for (int i = 0; i < queryc; i++) {
    int l, r, d;
    cin >> l >> r >> d;

    Lazy tmp;
    tmp.add = d;
    stree.upd(l, r + 1, tmp);

    cout << stree.get(1, length + 1).mw << '\n';
    /*
    Seg u = stree.get(2, 4);
    Seg v = stree.get(4, 6);
    cout << u.pl << " " << u.sl << " " << u.pt << " "
         << u.st << " " << u.l << " " << u.r << " " << u.mw << endl;
    cout << v.pl << " " << v.sl << " " << v.pt << " "
         << v.st << " " << v.l << " " << v.r << " " << v.mw << endl;
    Seg w;
    w.recalc(u, 2, v, 2);
    cout << w.pl << " " << w.sl << " " << w.pt << " "
         << w.st << " " << w.l << " " << w.r << " " << w.mw << endl;
    cout << endl << endl;
    */
  }
}