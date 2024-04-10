#include <bits/stdc++.h>

using namespace std;

struct Seg {
  int sum = INT_MIN;
  void recalc(const Seg &lhs_seg, int lhs_len,
    const Seg &rhs_seg, int rhs_len) {
    sum = max(lhs_seg.sum, rhs_seg.sum);
  }
} __attribute__((packed));

struct Lazy {
  int assign_val; // LLONG_MIN if no assign;
  void init() {
    assign_val = INT_MIN;
  }
  Lazy() { init(); }
  void split(Lazy &lhs_lazy, Lazy &rhs_lazy, int len) {
    lhs_lazy = *this;
    rhs_lazy = *this;
    init();
  }
  void merge(Lazy &oth, int len) {
    if (oth.assign_val != INT_MIN) {
      assign_val = oth.assign_val;
    }
  }
  void apply_to_seg(Seg &cur, int len) const {
    cur.sum = max(cur.sum, assign_val);
  }
} __attribute__((packed));

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

#include <bits/extc++.h>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>,
  rb_tree_tag, tree_order_statistics_node_update>;

const int MAX_N = 1 << 17;

int resp [MAX_N];
int age [MAX_N];
int groupsz [MAX_N];
int ans [MAX_N];

struct Event {
  int type, l, r, id; // 0 - add; 1 - calc ans

  Event (int _type = 0, int _l = 0, int _r = 0, int _id = 0)
    : type(_type), l(_l), r(_r), id(_id) {}
  
  int key () const {
    if (type == 0) return resp[l];
    else return max(resp[l], resp[r]);
  }
};

bool operator< (Event p, Event q) {
  if (p.key() != q.key()) {
    return p.key() > q.key();
  }
  return p.type < q.type;
}

int main () {
  ios::sync_with_stdio(false);
  
  int membc, K;
  cin >> membc >> K;

  for (int i = 1; i <= membc; i++) {
    cin >> resp[i];
  }

  for (int i = 1; i <= membc; i++) {
    cin >> age[i];
  }

  vector<pair<int, pair<int, int>>> leaders; // <resp, <type, idx>>
  for (int i = 1; i <= membc; i++) {
    leaders.push_back({resp[i], {0, i}}); // add to ordset
    leaders.push_back({resp[i], {1, i}}); // count
  }

  sort(leaders.begin(), leaders.end());

  ordered_set<pair<int, int>> followers; // <age, id>
  for (auto pr : leaders) {
    int cur_age = age[pr.second.second];
    if (pr.second.first == 0) {
      followers.insert(make_pair(cur_age, pr.second.second));
    } else {
      groupsz[pr.second.second] = followers.order_of_key(make_pair(cur_age + K, MAX_N))
        - followers.order_of_key(make_pair(cur_age - K, -MAX_N));
    }
  }

  int queryc;
  cin >> queryc;

  vector<Event> events;
  for (int i = 1; i <= membc; i++) {
    events.push_back(Event(0, i));
  }

  for (int i = 0; i < queryc; i++) {
    int l, r;
    cin >> l >> r;
    
    events.push_back(Event(1, l, r, i));
  }

  sort(events.begin(), events.end());

  SegTree segTree (1LL << 30);
  for (Event e : events) {
    if (e.type == 0) {
      Lazy tmp;
      tmp.assign_val = groupsz[e.l];
      segTree.upd(age[e.l], age[e.l] + 1, tmp);
    } else {
      int ql = max(age[e.l] - K, age[e.r] - K);
      int qr = min(age[e.l] + K, age[e.r] + K);
      if (ql > qr) {
        ans[e.id] = -1;
      } else {
        ql = max(0, ql);
        qr = min((1 << 30) - 1, qr);
        ans[e.id] = segTree.get(ql, qr + 1).sum;
        if (ans[e.id] < 0) ans[e.id] = -1;
      }
    }
  }

  for (int i = 0; i < queryc; i++) {
    cout << ans[i] << '\n';
  }
}