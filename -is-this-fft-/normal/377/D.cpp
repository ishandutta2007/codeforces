#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct Seg {
  pair<int, int> mx = make_pair(0, 0); // <idx, val>
  void recalc(const Seg &lhs_seg, int lhs_len,
    const Seg &rhs_seg, int rhs_len) {
    mx = max(lhs_seg.mx, rhs_seg.mx);
  }
};

struct Lazy {
  int add;
  int ass; // second only
  void init() {
    add = 0;
    ass = 0;
  }
  Lazy() { init(); }
  void split(Lazy &lhs_lazy, Lazy &rhs_lazy, int len) {
    lhs_lazy = *this;
    rhs_lazy = *this;
    init();
  }
  void merge(Lazy &oth, int len) {
    if (oth.ass != 0) {
      ass = oth.ass;
    }
    add += oth.add;
  }
  void apply_to_seg(Seg &cur, int len) const {
    cur.mx.first += add;
    if (ass != 0) {
      cur.mx.second = ass;
    }
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

const int MAX_A = 1 << 19;

struct Event {
  int l, r;

  Event (int _l = 0, int _r = 0) : l(_l), r(_r) {}
};

vector<Event> adds [MAX_A];
vector<Event> dels [MAX_A];

const int MAX_N = 1e5 + 5;

int l [MAX_N];
int r [MAX_N];
int v [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> l[i] >> v[i] >> r[i];

    adds[v[i]].push_back(Event(l[i], v[i]));
    dels[r[i]].push_back(Event(l[i], v[i]));
  }
  
  SegTree tree (MAX_A);
  for (int i = 0; i < MAX_A; i++) {
    Lazy tmp;
    tmp.ass = i;
    tree.upd(i, i + 1, tmp);
  }

  pair<int, pair<int, int>> ans = make_pair(0, make_pair(0, 0)); // <val, <x, y>>
  for (int i = 0; i < MAX_A; i++) {
    for (auto e : adds[i]) {
      Lazy tmp;
      tmp.add = 1;
      tree.upd(e.l, e.r + 1, tmp);
    }

    auto seg = tree.get(0, MAX_A).mx;
    auto cur = make_pair(seg.first, make_pair(seg.second, i));
    ans = max(ans, cur);
    
    for (auto e : dels[i]) {
      Lazy tmp;
      tmp.add = -1;
      tree.upd(e.l, e.r + 1, tmp);
    }
  }

  cout << ans.first << '\n';
  int x = ans.second.first, y = ans.second.second;
  for (int i = 0; i < n; i++) {
    if (l[i] <= x && x <= v[i] &&
        v[i] <= y && y <= r[i]) {
      cout << i + 1 << " ";
    }
  }
  cout << endl;
}